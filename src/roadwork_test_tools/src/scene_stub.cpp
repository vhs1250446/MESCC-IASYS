// TEST TOOL ONLY: stands in for the Sense node until it is implemented.
// Publishes /solution/scene from /vehicle/odometry with fixed beacon geometry
// and a scripted panel (STOP until `go_after` s of sim time, then GO). It reads
// no camera, LiDAR or beacon, so it must never be part of a graded launch.
#include <functional>
#include <memory>

#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"
#include "roadwork_solution_msgs/msg/scene.hpp"

using Scene = roadwork_solution_msgs::msg::Scene;
using Odometry = nav_msgs::msg::Odometry;

class SceneStub : public rclcpp::Node {
public:
  SceneStub() : Node("scene_stub") {
    work_shift_ = declare_parameter<double>("work_shift", 0.0);
    speed_limit_ = declare_parameter<double>("speed_limit", 4.0);
    go_after_ = declare_parameter<double>("go_after", 0.0);
    declare_parameter<bool>("publish_enabled", true);
    declare_parameter<bool>("obstacle_in_lane", false);
    declare_parameter<bool>("sense_fault", false);

    odom_sub_ = create_subscription<Odometry>(
        "/vehicle/odometry", rclcpp::SensorDataQoS(),
        [this](const Odometry::SharedPtr m) { odom_ = m; });
    pub_ = create_publisher<Scene>("/solution/scene", rclcpp::QoS(1).reliable());
    timer_ = rclcpp::create_timer(this, get_clock(), rclcpp::Duration::from_seconds(0.1),
                                  std::bind(&SceneStub::on_tick, this));
    RCLCPP_WARN(get_logger(), "scene_stub: scripted Scene (go_after=%.1f s, work_shift=%.1f). "
                "Test tool only.", go_after_, work_shift_);
  }

private:
  void on_tick() {
    const rclcpp::Time now = get_clock()->now();
    if (now.nanoseconds() == 0 || !odom_ || !get_parameter("publish_enabled").as_bool()) {
      return;
    }
    Scene s;
    s.header.stamp = now;
    s.header.frame_id = "map";
    s.seq = ++seq_;
    s.odom_stamp = odom_->header.stamp;
    s.lidar_stamp = now;
    s.radar_stamp = now;
    s.camera_stamp = now;
    s.beacon_stamp = now;
    s.ego_x = odom_->pose.pose.position.x;
    s.beacon_valid = true;
    s.entry_x = 25.0;
    s.work_start = 42.0 + work_shift_;
    s.work_end = 49.0 + work_shift_;
    s.exit_x = 68.0 + work_shift_;
    s.speed_limit = speed_limit_;
    s.pass_side = 1;
    s.panel_state = now.seconds() >= go_after_ ? Scene::PANEL_GO : Scene::PANEL_STOP;
    s.obstacle_in_lane = get_parameter("obstacle_in_lane").as_bool();
    s.obstacle_range = 0.0;
    s.sense_status = get_parameter("sense_fault").as_bool() ? Scene::SENSE_FAULT : Scene::SENSE_OK;
    s.stale_flags = 0;
    s.sense_state = "SCENE_STUB";
    pub_->publish(s);
  }

  double work_shift_, speed_limit_, go_after_;
  uint32_t seq_ = 0;
  Odometry::SharedPtr odom_;
  rclcpp::Subscription<Odometry>::SharedPtr odom_sub_;
  rclcpp::Publisher<Scene>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SceneStub>());
  rclcpp::shutdown();
  return 0;
}
