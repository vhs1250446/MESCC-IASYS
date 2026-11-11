#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <limits>
#include <memory>
#include <optional>
#include <stdexcept>

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "roadwork_interfaces/msg/vehicle_command.hpp"
#include "roadwork_solution_msgs/msg/act_status.hpp"
#include "roadwork_solution_msgs/msg/plan.hpp"
#include "roadwork_solution_msgs/msg/plan_point.hpp"
#include "roadwork_student/act_validator.hpp"
#include "roadwork_student/pure_pursuit.hpp"
#include "roadwork_student/command_limiter.hpp"

using Odometry = nav_msgs::msg::Odometry;
using ActStatus = roadwork_solution_msgs::msg::ActStatus;
using Plan = roadwork_solution_msgs::msg::Plan;
using VehicleCommand = roadwork_interfaces::msg::VehicleCommand;

struct ActParams {
  double control_period;
  double plan_timeout;
  double scene_timeout;
  double odom_timeout;
  double future_tolerance;
  double speed_cap;
  double max_steer;
  double max_steer_rate;
  double wheelbase;
  double front_offset;
  double lookahead_gain;
  double lookahead_min;
  double lookahead_max;
  double speed_preview;
  double stop_decel;
  double stop_margin;
  double control_delay;
};

struct ActDecision {
  double speed;
  double steering;
  double speed_raw;
  double steering_raw;
  double cross_track_error;
  double heading_error;
  uint32_t target_index;
  uint8_t limit_flags;
  uint8_t state;
  uint8_t reason;
};

class ActNode : public rclcpp::Node {

public:
  ActNode() : Node("act") {

    params_ = load_params();
    vparams_ = {params_.plan_timeout, params_.scene_timeout,
                params_.odom_timeout, params_.future_tolerance};

    pp_params_ = {params_.wheelbase, params_.lookahead_gain, params_.lookahead_min, params_.lookahead_max, params_.speed_preview};
    lim_params_ = {params_.speed_cap, params_.max_steer, params_.max_steer_rate,
                   params_.front_offset, params_.stop_decel, params_.stop_margin,
                   params_.control_delay};

    odometry_sub_ = create_subscription<Odometry>("/vehicle/odometry", rclcpp::SensorDataQoS(), std::bind(&ActNode::odometry_callback, this, std::placeholders::_1));
    plan_sub_ = create_subscription<Plan>("/solution/plan", rclcpp::QoS(1).reliable(), std::bind(&ActNode::plan_callback, this, std::placeholders::_1));

    cmd_pub_ = create_publisher<VehicleCommand>("/vehicle/command", rclcpp::QoS(10).reliable());
    act_status_pub_ = create_publisher<ActStatus>("/solution/act_status", rclcpp::QoS(10).reliable());

    timer_ = rclcpp::create_timer(this, get_clock(), rclcpp::Duration::from_seconds(params_.control_period), std::bind(&ActNode::on_tick, this));

  }

private:

  ActParams load_params() {

    if(!get_parameter("use_sim_time").as_bool()) {
      RCLCPP_FATAL(get_logger(),
          "use_sim_time is false: Act must run on simulation time (/clock). "
          "Start it with the act.yaml parameter file or -p use_sim_time:=true");
      throw std::runtime_error("act requires use_sim_time=true");
    }

    ActParams p;
    p.control_period    = declare_parameter<double>("control_period", 0.05);
    p.plan_timeout      = declare_parameter<double>("plan_timeout", 0.3);
    p.scene_timeout     = declare_parameter<double>("scene_timeout", 0.5);
    p.odom_timeout      = declare_parameter<double>("odom_timeout", 0.15);
    p.future_tolerance  = declare_parameter<double>("future_tolerance", 1.0e-6);
    p.speed_cap         = declare_parameter<double>("speed_cap", 3.9);
    p.max_steer         = declare_parameter<double>("max_steer", 0.45);
    p.max_steer_rate    = declare_parameter<double>("max_steer_rate", 0.6);
    p.wheelbase         = declare_parameter<double>("wheelbase", 2.4);
    p.front_offset      = declare_parameter<double>("front_offset", 0.9);
    p.lookahead_gain    = declare_parameter<double>("lookahead_gain", 1.0);
    p.lookahead_min     = declare_parameter<double>("lookahead_min", 2.5);
    p.lookahead_max     = declare_parameter<double>("lookahead_max", 6.0);
    p.speed_preview     = declare_parameter<double>("speed_preview", 0.5);
    p.stop_decel        = declare_parameter<double>("stop_decel", 2.0);
    p.stop_margin       = declare_parameter<double>("stop_margin", 0.2);
    p.control_delay     = declare_parameter<double>("control_delay", 0.1);

    if (p.control_period <= 0.0 || p.plan_timeout <= 0.0 ||
        p.scene_timeout <= 0.0 || p.odom_timeout <= 0.0 ||
        p.speed_cap <= 0.0 || p.max_steer <= 0.0 ||
        p.max_steer_rate <= 0.0 || p.wheelbase <= 0.0 ||
        p.lookahead_min <= 0.0 || p.lookahead_max < p.lookahead_min ||
        p.lookahead_gain < 0 || p.speed_preview < 0 ||
        p.stop_decel <= 0.0 || p.stop_margin < 0.0 || p.control_delay < 0.0) {
        RCLCPP_FATAL(get_logger(), "Invalid Act parameters: periods, timeouts and limits must be positive");
        throw std::invalid_argument("invalid act parameters");
    }

    RCLCPP_INFO(get_logger(),
        "Act params: period=%.3f plan_timeout=%.3f scene_timeout=%.3f odom_timeout=%.3f "
        "speed_cap=%.2f max_steer=%.2f max_steer_rate=%.2f wheelbase=%.2f front_offset=%.2f "
        "lookahead_gain=%.2f lookahead_min=%.2f lookahead_max=%.2f speed_preview=%.2f "
        "stop_decel=%.2f stop_margin=%.2f control_delay=%.3f use_sim_time=%s",
        p.control_period, p.plan_timeout, p.scene_timeout, p.odom_timeout,
        p.speed_cap, p.max_steer, p.max_steer_rate, p.wheelbase, p.front_offset,
        p.lookahead_gain, p.lookahead_min, p.lookahead_max, p.speed_preview,
        p.stop_decel, p.stop_margin, p.control_delay,
        get_parameter("use_sim_time").as_bool() ? "true" : "false");

    return p;
  }

  void plan_callback(const Plan::SharedPtr msg) {
    last_plan_ = msg;
  }

  void odometry_callback(const Odometry::SharedPtr msg) {
    last_odom_ = msg;
  }

  void on_tick() {
    const rclcpp::Time now = get_clock()->now();
    if (now.nanoseconds() == 0) {
      //sim clock not started
      return;
    }

    if (last_tick_ && now < *last_tick_) {
      RCLCPP_WARN(get_logger(), "Simulation time moved backwards: resetting Act state");
      reset();
    }

    // Sim time since the previous command, for the steering slew limit.
    // First tick or after a reset: one nominal period. Capped at two periods so
    // a stalled clock cannot unlock a large steering jump.
    double dt = params_.control_period;
    if (last_tick_ && now >= *last_tick_) {
      dt = std::min((now - *last_tick_).seconds(), 2.0 * params_.control_period);
    }
    last_tick_ = now;

    const ActDecision decision = decide_command(now, dt);
    previous_steering_ = decision.steering;

    publish_command(now, decision);
    publish_status(now, decision);
  }

  // Validation + state machine (team_docs/PLAN_ACT_CONTRACT.md, "When Act stops on its own").
  //
  //   INIT      --valid-->                          TRACKING
  //   TRACKING  --any reason-->                     SAFE_STOP  (remember held plan stamp)
  //   SAFE_STOP --valid and newer stamp-->          TRACKING
  //   SAFE_STOP --valid but not newer-->            stay, reason WAITING_NEW_SEQ
  //   any       --REASON_FAULT-->                   FAULT      (latched until reset())
  ActDecision decide_command(const rclcpp::Time & now, double dt) {
    uint8_t reason = roadwork_student::validate_inputs(
        last_plan_.get(), last_odom_.get(), now.seconds(), vparams_);

    if (reason == ActStatus::REASON_FAULT) {
      state_ = ActStatus::STATE_FAULT;
    }

    switch (state_) {
      case ActStatus::STATE_INIT:
        if (reason == ActStatus::REASON_NONE) {
          state_ = ActStatus::STATE_TRACKING;
        }
        break;
      case ActStatus::STATE_TRACKING:
        if (reason != ActStatus::REASON_NONE) {
          state_ = ActStatus::STATE_SAFE_STOP;
          stopped_plan_stamp_ = last_plan_
              ? roadwork_student::to_seconds(last_plan_->header.stamp)
              : std::numeric_limits<double>::infinity();
        }
        break;
      case ActStatus::STATE_SAFE_STOP:
        if (reason == ActStatus::REASON_NONE) {
          if (roadwork_student::is_newer_plan(*last_plan_, stopped_plan_stamp_)) {
            state_ = ActStatus::STATE_TRACKING;
          } else {
            reason = ActStatus::REASON_WAITING_NEW_SEQ;
          }
        }
        break;
      case ActStatus::STATE_FAULT:
      default:
        reason = ActStatus::REASON_FAULT;
        break;
    }

    log_transition(reason);

    ActDecision d;
    d.state = state_;
    d.reason = reason;
    d.target_index = 0;
    d.limit_flags = 0;

    if (state_ == ActStatus::STATE_TRACKING) {
      const auto & o = last_odom_->pose.pose;
      const roadwork_student::Pose2D pose{o.position.x, o.position.y, roadwork_student::yaw_from_quaternion(o.orientation)};

      const double v = last_odom_->twist.twist.linear.x;
      const auto out = roadwork_student::track_path(last_plan_->path, pose, v, pp_params_);

      d.target_index      = out.nearest_index;
      d.speed_raw         = out.speed;
      d.steering_raw      = out.steering;
      d.cross_track_error = out.cross_track_error;
      d.heading_error     = out.heading_error;   
      
      roadwork_student::LimiterInput in;
      in.speed_raw         = d.speed_raw;
      in.steering_raw      = d.steering_raw;
      in.previous_steering = previous_steering_;
      in.dt                = dt;
      in.rear_x            = o.position.x;
      in.current_speed     = v;
      in.speed_limit       = last_plan_->speed_limit;
      in.has_stop_line     = last_plan_->has_stop_line;
      in.stop_line_x       = last_plan_->stop_line_x;
      // Applying limits to speed and steering
      const auto lim = roadwork_student::limit_command(in, lim_params_);

      d.speed       = lim.speed;
      d.steering    = lim.steering;
      d.limit_flags = lim.flags;
    } else {
      // INIT, SAFE_STOP, FAULT: brake to zero and hold the wheel where it is
      // (snapping it to 0 would break the 0.6 rad/s slew limit).
      d.speed_raw = 0.0;
      d.steering_raw = previous_steering_;
      d.speed = 0.0;
      d.steering = previous_steering_;
      d.cross_track_error = 0.0;
      d.heading_error = 0.0;
    }
    return d;
  }

  
  void log_transition(uint8_t reason) {
    if (state_ == logged_state_ && reason == logged_reason_) {
      return;
    }
    RCLCPP_INFO(get_logger(), "Act state %s -> %s (reason %s)",
        state_to_string(logged_state_), state_to_string(state_),
        roadwork_student::reason_to_string(reason));
    logged_state_ = state_;
    logged_reason_ = reason;
  }

  static const char * state_to_string(uint8_t s) {
    switch (s) {
      case ActStatus::STATE_INIT:      return "INIT";
      case ActStatus::STATE_TRACKING:  return "TRACKING";
      case ActStatus::STATE_SAFE_STOP: return "SAFE_STOP";
      case ActStatus::STATE_FAULT:     return "FAULT";
      default:                         return "UNKNOWN";
    }
  }

  void publish_command(const rclcpp::Time & now, const ActDecision & d) {
    VehicleCommand cmd;
    cmd.header.stamp = now;
    cmd.header.frame_id = "base_link";
    cmd.speed = d.speed;
    cmd.steering_angle = d.steering;
    cmd_pub_->publish(cmd);
  }

  void publish_status(const rclcpp::Time & now, const ActDecision & d) {
    ActStatus status;
    status.header.stamp = now;
    status.header.frame_id = "map";
    status.state = d.state;
    status.reason_code = d.reason;
    status.reason = roadwork_student::reason_to_string(d.reason);
    status.plan_seq = last_plan_ ? last_plan_->seq : 0;
    status.plan_age = last_plan_ ? age_of(now, last_plan_->header.stamp) : -1.0;
    status.odom_age = last_odom_ ? age_of(now, last_odom_->header.stamp) : -1.0;
    status.target_index = d.target_index;
    status.speed_raw = d.speed_raw;
    status.steering_raw = d.steering_raw;
    status.speed_cmd = d.speed;
    status.steering_cmd = d.steering;
    status.cross_track_error = d.cross_track_error;
    status.heading_error = d.heading_error;
    status.limit_flags = d.limit_flags;
    act_status_pub_->publish(status);
  }

  double age_of(const rclcpp::Time & now, const builtin_interfaces::msg::Time & stamp) const {
    return (now - rclcpp::Time(stamp, now.get_clock_type())).seconds();
  }

  void reset() {
    last_plan_.reset();
    last_odom_.reset();
    previous_steering_ = 0.0;
    state_ = ActStatus::STATE_INIT;
    stopped_plan_stamp_ = std::numeric_limits<double>::infinity();
  }

  ActParams params_;
  roadwork_student::ValidatorParams vparams_;
  roadwork_student::PurePursuitParams pp_params_;
  roadwork_student::LimiterParams lim_params_;

  rclcpp::Subscription<roadwork_solution_msgs::msg::Plan>::SharedPtr plan_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odometry_sub_;
  rclcpp::Publisher<roadwork_interfaces::msg::VehicleCommand>::SharedPtr cmd_pub_;
  rclcpp::Publisher<ActStatus>::SharedPtr act_status_pub_;
  rclcpp::TimerBase::SharedPtr timer_;

  Plan::SharedPtr last_plan_;
  Odometry::SharedPtr last_odom_;
  std::optional<rclcpp::Time> last_tick_;
  double previous_steering_ = 0.0;

  uint8_t state_ = ActStatus::STATE_INIT;
  double stopped_plan_stamp_ = std::numeric_limits<double>::infinity();
  uint8_t logged_state_ = ActStatus::STATE_INIT;
  uint8_t logged_reason_ = 0xFE;  // forces the first log line

};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ActNode>());
  rclcpp::shutdown();
  return 0;
}
