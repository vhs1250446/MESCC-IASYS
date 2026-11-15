#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <functional>
#include <limits>
#include <memory>
#include <optional>

#include "builtin_interfaces/msg/time.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"
#include "roadwork_interfaces/msg/radar_detections.hpp"
#include "roadwork_interfaces/msg/roadwork_beacon.hpp"
#include "roadwork_solution_msgs/msg/scene.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

using Odometry = nav_msgs::msg::Odometry;
using RadarDetections = roadwork_interfaces::msg::RadarDetections;
using RoadworkBeacon = roadwork_interfaces::msg::RoadworkBeacon;
using Scene = roadwork_solution_msgs::msg::Scene;
using Image = sensor_msgs::msg::Image;
using LaserScan = sensor_msgs::msg::LaserScan;

namespace {
constexpr double kOdomTtl = 0.075;
constexpr double kSensorTtl = 0.15;
constexpr double kBeaconTtl = 1.2;
constexpr double kFutureTolerance = 1.0e-6;
constexpr double kLaneEdgeMargin = 0.5;

double seconds(const builtin_interfaces::msg::Time & stamp) {
  return static_cast<double>(stamp.sec) + 1.0e-9 * static_cast<double>(stamp.nanosec);
}

bool valid_stamp(const builtin_interfaces::msg::Time & stamp) {
  return stamp.sec >= 0 && stamp.nanosec < 1000000000U;
}

bool fresh(double now, double stamp, double ttl) {
  return std::isfinite(now) && std::isfinite(stamp) && stamp >= 0.0 &&
         now >= stamp - kFutureTolerance && now - stamp <= ttl;
}

struct OdomSample {
  builtin_interfaces::msg::Time stamp;
  double time;
  double x;
  double y;
  double yaw;
};

uint8_t classify_panel(const Image & image) {
  if (image.width != 96 || image.height != 64 || image.encoding != "rgb8" ||
      image.step < image.width * 3U ||
      image.data.size() < static_cast<std::size_t>(image.step) * image.height) {
    return Scene::PANEL_UNKNOWN;
  }

  std::size_t red_pixels = 0;
  std::size_t green_pixels = 0;
  for (std::size_t y = 0; y < image.height; ++y) {
    for (std::size_t x = 0; x < image.width; ++x) {
      const std::size_t offset = y * image.step + x * 3U;
      const int red = image.data[offset];
      const int green = image.data[offset + 1U];
      const int blue = image.data[offset + 2U];
      if (red >= green + 50 && red >= blue + 50) {
        ++red_pixels;
      } else if (green >= red + 50 && green >= blue + 50) {
        ++green_pixels;
      }
    }
  }

  if (red_pixels >= 100U && red_pixels >= 4U * green_pixels) {
    return Scene::PANEL_STOP;
  }
  if (green_pixels >= 100U && green_pixels >= 4U * red_pixels) {
    return Scene::PANEL_GO;
  }
  return Scene::PANEL_UNKNOWN;
}
}

class SenseNode : public rclcpp::Node {
public:
  SenseNode() : Node("sense") {
    scene_pub_ = create_publisher<Scene>("/solution/scene", rclcpp::QoS(1).reliable());
    odom_sub_ = create_subscription<Odometry>(
        "/vehicle/odometry", rclcpp::SensorDataQoS(),
        std::bind(&SenseNode::on_odometry, this, std::placeholders::_1));
    lidar_sub_ = create_subscription<LaserScan>(
        "/lidar/scan", rclcpp::SensorDataQoS(),
        std::bind(&SenseNode::on_lidar, this, std::placeholders::_1));
    radar_sub_ = create_subscription<RadarDetections>(
        "/radar/detections", rclcpp::SensorDataQoS(),
        std::bind(&SenseNode::on_radar, this, std::placeholders::_1));
    camera_sub_ = create_subscription<Image>(
        "/camera/image_raw", rclcpp::SensorDataQoS(),
        std::bind(&SenseNode::on_camera, this, std::placeholders::_1));
    beacon_sub_ = create_subscription<RoadworkBeacon>(
        "/infra/roadwork/beacon", rclcpp::QoS(10).reliable(),
        std::bind(&SenseNode::on_beacon, this, std::placeholders::_1));
    timer_ = rclcpp::create_timer(
        this, get_clock(), rclcpp::Duration::from_seconds(0.1),
        std::bind(&SenseNode::on_tick, this));
  }

private:
  void on_odometry(const Odometry::SharedPtr msg) {
    if (!valid_stamp(msg->header.stamp)) {
      return;
    }
    const double stamp = seconds(msg->header.stamp);
    if (!odom_history_.empty() && stamp <= odom_history_.back().time) {
      return;
    }
    const auto & p = msg->pose.pose.position;
    const auto & q = msg->pose.pose.orientation;
    const double q_norm = std::sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
    if (msg->header.frame_id != "map" || msg->child_frame_id != "base_link" ||
        !std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(q_norm) ||
        q_norm < 1.0e-9) {
      return;
    }
    const double qx = q.x / q_norm;
    const double qy = q.y / q_norm;
    const double qz = q.z / q_norm;
    const double qw = q.w / q_norm;
    OdomSample sample{
        msg->header.stamp, stamp, p.x, p.y,
        std::atan2(2.0 * (qw * qz + qx * qy), 1.0 - 2.0 * (qy * qy + qz * qz))};
    odom_history_.push_back(sample);
    if (odom_history_.size() > 8U) {
      odom_history_.pop_front();
    }
    latest_odom_ = sample;
    has_input_ = true;
  }

  void on_lidar(const LaserScan::SharedPtr msg) {
    if (!valid_stamp(msg->header.stamp)) {
      return;
    }
    const double stamp = seconds(msg->header.stamp);
    if (lidar_received_ && stamp <= lidar_time_) {
      return;
    }
    lidar_received_ = true;
    lidar_time_ = stamp;
    lidar_stamp_ = msg->header.stamp;
    lidar_format_valid_ =
        msg->header.frame_id == "base_link" && msg->ranges.size() == 360U &&
        std::isfinite(msg->angle_min) && std::isfinite(msg->angle_increment) &&
        msg->angle_increment > 0.0F && std::isfinite(msg->range_min) &&
        std::isfinite(msg->range_max) && msg->range_min >= 0.0F &&
        msg->range_max > msg->range_min;
    lidar_ = msg;
    if (lidar_format_valid_) {
      has_input_ = true;
    }
  }

  void on_radar(const RadarDetections::SharedPtr msg) {
    if (!valid_stamp(msg->header.stamp) || msg->header.frame_id != "base_link") {
      return;
    }
    const double stamp = seconds(msg->header.stamp);
    if (radar_received_ && stamp <= radar_time_) {
      return;
    }
    radar_received_ = true;
    radar_time_ = stamp;
    radar_stamp_ = msg->header.stamp;
    has_input_ = true;
  }

  void on_camera(const Image::SharedPtr msg) {
    if (!valid_stamp(msg->header.stamp)) {
      return;
    }
    const double stamp = seconds(msg->header.stamp);
    if (camera_received_ && stamp <= camera_time_) {
      return;
    }
    camera_received_ = true;
    camera_time_ = stamp;
    camera_stamp_ = msg->header.stamp;
    camera_valid_ = msg->header.frame_id == "panel_crop" &&
                    msg->width == 96 && msg->height == 64 &&
                    msg->encoding == "rgb8" && msg->step >= msg->width * 3U &&
                    msg->data.size() >= static_cast<std::size_t>(msg->step) * msg->height;
    if (!camera_valid_) {
      candidate_panel_ = Scene::PANEL_UNKNOWN;
      candidate_count_ = 0;
      panel_state_ = Scene::PANEL_UNKNOWN;
      return;
    }
    has_input_ = true;

    const uint8_t observed = classify_panel(*msg);
    if (observed == Scene::PANEL_UNKNOWN) {
      candidate_panel_ = Scene::PANEL_UNKNOWN;
      candidate_count_ = 0;
      panel_state_ = Scene::PANEL_UNKNOWN;
      return;
    }
    if (observed == candidate_panel_) {
      ++candidate_count_;
    } else {
      candidate_panel_ = observed;
      candidate_count_ = 1;
    }
    panel_state_ = candidate_count_ >= 3U ? candidate_panel_ : Scene::PANEL_UNKNOWN;
  }

  void on_beacon(const RoadworkBeacon::SharedPtr msg) {
    if (!valid_stamp(msg->header.stamp)) {
      return;
    }
    const double stamp = seconds(msg->header.stamp);
    if (beacon_received_ && stamp <= beacon_time_) {
      return;
    }
    beacon_received_ = true;
    beacon_time_ = stamp;
    beacon_stamp_ = msg->header.stamp;
    beacon_data_valid_ =
        msg->header.frame_id == "map" && std::isfinite(msg->valid_for) &&
        msg->valid_for > 0.0 && std::isfinite(msg->entry_x) &&
        std::isfinite(msg->work_start) && std::isfinite(msg->work_end) &&
        std::isfinite(msg->exit_x) && std::isfinite(msg->speed_limit) &&
        msg->speed_limit > 0.0 && msg->pass_side == 1;
    if (!beacon_data_valid_) {
      return;
    }
    beacon_valid_for_ = std::min(msg->valid_for, kBeaconTtl);
    entry_x_ = msg->entry_x;
    work_start_ = msg->work_start;
    work_end_ = msg->work_end;
    exit_x_ = msg->exit_x;
    speed_limit_ = msg->speed_limit;
    pass_side_ = msg->pass_side;
    has_input_ = true;
  }

  std::optional<OdomSample> odometry_for_scan(double scan_time) const {
    std::optional<OdomSample> best;
    double best_age = kOdomTtl;
    for (const auto & sample : odom_history_) {
      const double age = scan_time - sample.time;
      if (age >= -kFutureTolerance && age <= best_age) {
        best = sample;
        best_age = age;
      }
    }
    return best;
  }

  bool detect_obstacle(const OdomSample & odom, bool & obstacle, double & range) const {
    if (!lidar_ || !lidar_format_valid_) {
      return false;
    }
    std::size_t valid_returns = 0;
    std::size_t cluster_size = 0;
    std::size_t previous_index = 0;
    double previous_range = 0.0;
    double cluster_nearest = 0.0;
    double nearest_cluster = std::numeric_limits<double>::infinity();
    auto finish_cluster = [&]() {
      if (cluster_size >= 2U) {
        nearest_cluster = std::min(nearest_cluster, cluster_nearest);
      }
      cluster_size = 0;
    };

    for (std::size_t i = 0; i < lidar_->ranges.size(); ++i) {
      const double distance = lidar_->ranges[i];
      const bool valid = std::isfinite(distance) && distance >= lidar_->range_min &&
                         distance <= lidar_->range_max;
      if (valid) {
        ++valid_returns;
      }
      bool in_opposing_lane = false;
      if (valid) {
        const double angle = odom.yaw + lidar_->angle_min +
                             static_cast<double>(i) * lidar_->angle_increment;
        const double map_y = odom.y + distance * std::sin(angle);
        in_opposing_lane = map_y > 0.0 && map_y < 3.5 - kLaneEdgeMargin;
      }
      const bool joins_cluster =
          in_opposing_lane && cluster_size > 0U && previous_index + 1U == i &&
          std::abs(distance - previous_range) <= 0.75;
      if (!joins_cluster) {
        finish_cluster();
        if (in_opposing_lane) {
          cluster_size = 1U;
          cluster_nearest = distance;
        }
      } else {
        ++cluster_size;
        cluster_nearest = std::min(cluster_nearest, distance);
      }
      if (in_opposing_lane) {
        previous_index = i;
        previous_range = distance;
      }
    }
    finish_cluster();
    if (valid_returns == 0U) {
      return false;
    }
    obstacle = std::isfinite(nearest_cluster);
    range = obstacle ? nearest_cluster : 0.0;
    return true;
  }

  void on_tick() {
    const rclcpp::Time now = get_clock()->now();
    if (now.nanoseconds() == 0) {
      return;
    }
    if (last_tick_ && now < *last_tick_) {
      reset();
    }
    last_tick_ = now;
    if (!has_input_) {
      return;
    }

    const double now_seconds = now.seconds();
    Scene scene;
    scene.header.stamp = now;
    scene.header.frame_id = "map";
    scene.seq = ++seq_;
    scene.lidar_stamp = lidar_stamp_;
    scene.radar_stamp = radar_stamp_;
    scene.camera_stamp = camera_stamp_;
    scene.beacon_stamp = beacon_stamp_;

    std::optional<OdomSample> projection_odom;
    if (lidar_received_ && fresh(now_seconds, lidar_time_, kSensorTtl)) {
      projection_odom = odometry_for_scan(lidar_time_);
    }
    const std::optional<OdomSample> scene_odom =
        projection_odom ? projection_odom : latest_odom_;
    if (scene_odom) {
      scene.odom_stamp = scene_odom->stamp;
      scene.ego_x = scene_odom->x;
    }

    bool obstacle = false;
    double obstacle_range = 0.0;
    const bool lidar_usable =
        lidar_received_ && fresh(now_seconds, lidar_time_, kSensorTtl) &&
        projection_odom && detect_obstacle(*projection_odom, obstacle, obstacle_range);

    bool beacon_valid = beacon_received_ && beacon_data_valid_ &&
                        fresh(now_seconds, beacon_time_, beacon_valid_for_);
    const bool radar_fresh = radar_received_ && fresh(now_seconds, radar_time_, kSensorTtl);
    const bool camera_fresh = camera_received_ && camera_valid_ &&
                              fresh(now_seconds, camera_time_, kSensorTtl);
    uint8_t stale_flags = 0;
    if (!lidar_usable) {
      stale_flags |= Scene::STALE_LIDAR;
    }
    if (!radar_fresh) {
      stale_flags |= Scene::STALE_RADAR;
    }
    if (!camera_fresh) {
      stale_flags |= Scene::STALE_CAMERA;
    }
    if (!beacon_valid) {
      stale_flags |= Scene::STALE_BEACON;
    }

    scene.beacon_valid = beacon_valid;
    scene.entry_x = entry_x_;
    scene.work_start = work_start_;
    scene.work_end = work_end_;
    scene.exit_x = exit_x_;
    scene.speed_limit = beacon_valid ? speed_limit_ : 0.0;
    scene.pass_side = pass_side_;
    scene.panel_state = camera_fresh ? panel_state_ : Scene::PANEL_UNKNOWN;
    scene.obstacle_in_lane = lidar_usable && obstacle;
    scene.obstacle_range = lidar_usable ? obstacle_range : 0.0;
    scene.stale_flags = stale_flags;
    if (!lidar_usable || !camera_fresh || !std::isfinite(scene.ego_x)) {
      scene.sense_status = Scene::SENSE_FAULT;
      scene.sense_state = "FAULT";
    } else if (!radar_fresh || !beacon_valid) {
      scene.sense_status = Scene::SENSE_DEGRADED;
      scene.sense_state = "DEGRADED";
    } else {
      scene.sense_status = Scene::SENSE_OK;
      scene.sense_state = "RUNNING";
    }
    scene_pub_->publish(scene);
  }

  void reset() {
    odom_history_.clear();
    latest_odom_.reset();
    lidar_.reset();
    lidar_received_ = false;
    lidar_format_valid_ = false;
    radar_received_ = false;
    camera_received_ = false;
    camera_valid_ = false;
    beacon_received_ = false;
    beacon_data_valid_ = false;
    has_input_ = false;
    lidar_time_ = 0.0;
    radar_time_ = 0.0;
    camera_time_ = 0.0;
    beacon_time_ = 0.0;
    lidar_stamp_ = builtin_interfaces::msg::Time();
    radar_stamp_ = builtin_interfaces::msg::Time();
    camera_stamp_ = builtin_interfaces::msg::Time();
    beacon_stamp_ = builtin_interfaces::msg::Time();
    candidate_panel_ = Scene::PANEL_UNKNOWN;
    candidate_count_ = 0;
    panel_state_ = Scene::PANEL_UNKNOWN;
    beacon_valid_for_ = kBeaconTtl;
    entry_x_ = 0.0;
    work_start_ = 0.0;
    work_end_ = 0.0;
    exit_x_ = 0.0;
    speed_limit_ = 0.0;
    pass_side_ = 1;
  }

  uint32_t seq_ = 0;
  bool has_input_ = false;
  bool lidar_received_ = false;
  bool lidar_format_valid_ = false;
  bool radar_received_ = false;
  bool camera_received_ = false;
  bool camera_valid_ = false;
  bool beacon_received_ = false;
  bool beacon_data_valid_ = false;
  double lidar_time_ = 0.0;
  double radar_time_ = 0.0;
  double camera_time_ = 0.0;
  double beacon_time_ = 0.0;
  double beacon_valid_for_ = kBeaconTtl;
  double entry_x_ = 0.0;
  double work_start_ = 0.0;
  double work_end_ = 0.0;
  double exit_x_ = 0.0;
  double speed_limit_ = 0.0;
  int8_t pass_side_ = 1;
  uint8_t candidate_panel_ = Scene::PANEL_UNKNOWN;
  uint8_t panel_state_ = Scene::PANEL_UNKNOWN;
  std::size_t candidate_count_ = 0;
  builtin_interfaces::msg::Time lidar_stamp_;
  builtin_interfaces::msg::Time radar_stamp_;
  builtin_interfaces::msg::Time camera_stamp_;
  builtin_interfaces::msg::Time beacon_stamp_;
  LaserScan::SharedPtr lidar_;
  std::deque<OdomSample> odom_history_;
  std::optional<OdomSample> latest_odom_;
  std::optional<rclcpp::Time> last_tick_;
  rclcpp::Publisher<Scene>::SharedPtr scene_pub_;
  rclcpp::Subscription<Odometry>::SharedPtr odom_sub_;
  rclcpp::Subscription<LaserScan>::SharedPtr lidar_sub_;
  rclcpp::Subscription<RadarDetections>::SharedPtr radar_sub_;
  rclcpp::Subscription<Image>::SharedPtr camera_sub_;
  rclcpp::Subscription<RoadworkBeacon>::SharedPtr beacon_sub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SenseNode>());
  rclcpp::shutdown();
  return 0;
}
