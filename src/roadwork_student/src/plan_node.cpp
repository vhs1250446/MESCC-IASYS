// Plan node: /solution/scene -> /solution/plan (+ plan_status, state, path).
// Contracts: team_docs/SENSE_PLAN_CONTRACT.md, team_docs/PLAN_ACT_CONTRACT.md,
// team_docs/PLAN_NODE.md. Decision and path logic live in plan_logic.
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/path.hpp"
#include "std_msgs/msg/string.hpp"
#include "roadwork_solution_msgs/msg/plan.hpp"
#include "roadwork_solution_msgs/msg/plan_status.hpp"
#include "roadwork_solution_msgs/msg/scene.hpp"
#include "roadwork_student/path_builder.hpp"
#include "roadwork_student/plan_decision.hpp"
#include "roadwork_student/time_utils.hpp"

using Plan = roadwork_solution_msgs::msg::Plan;
using PlanStatus = roadwork_solution_msgs::msg::PlanStatus;
using Scene = roadwork_solution_msgs::msg::Scene;
using NavPath = nav_msgs::msg::Path;
using StringMsg = std_msgs::msg::String;

namespace rs = roadwork_student;

class PlanNode : public rclcpp::Node {
public:
  PlanNode() : Node("plan") {
    load_parameters();
    path_.reserve(rs::path_const::kMaxPoints);

    scene_sub_ = create_subscription<Scene>(
        "/solution/scene", rclcpp::QoS(1).reliable(),
        std::bind(&PlanNode::scene_callback, this, std::placeholders::_1));
    plan_pub_ = create_publisher<Plan>("/solution/plan", rclcpp::QoS(1).reliable());
    status_pub_ = create_publisher<PlanStatus>("/solution/plan_status", rclcpp::QoS(10).reliable());
    state_pub_ = create_publisher<StringMsg>("/solution/state", rclcpp::QoS(10).reliable());
    path_pub_ = create_publisher<NavPath>("/solution/path", rclcpp::QoS(1).reliable());

    timer_ = rclcpp::create_timer(this, get_clock(), rclcpp::Duration::from_seconds(plan_period_),
                                  std::bind(&PlanNode::on_tick, this));
  }

private:
  void load_parameters() {
    plan_period_ = declare_parameter<double>("plan_period", 0.1);
    plan_validity_ = declare_parameter<double>("plan_validity", 0.3);
    dparams_.scene_timeout = declare_parameter<double>("scene_timeout", 0.5);
    dparams_.future_tolerance = declare_parameter<double>("future_tolerance", 1.0e-6);
    pparams_.v_cruise = declare_parameter<double>("v_cruise", 3.8);
    pparams_.a_acc = declare_parameter<double>("a_acc", 1.4);
    pparams_.a_dec = declare_parameter<double>("a_dec", 1.8);
    pparams_.stop_margin = declare_parameter<double>("stop_margin", 0.3);
    pparams_.slew_margin = declare_parameter<double>("slew_margin", 0.8);

    const bool ok =
        plan_period_ > 0.0 && plan_validity_ > 0.0 && dparams_.scene_timeout > 0.0 &&
        dparams_.future_tolerance >= 0.0 &&
        pparams_.v_cruise > 0.0 && pparams_.v_cruise <= rs::path_const::kDefaultSpeedLimit &&
        pparams_.a_acc > 0.0 && pparams_.a_acc <= rs::path_const::kMaxAccel &&
        pparams_.a_dec > 0.0 && pparams_.a_dec <= rs::path_const::kMaxPlanDecel &&
        pparams_.stop_margin >= 0.0 && pparams_.stop_margin <= 1.0 &&
        pparams_.slew_margin > 0.0 && pparams_.slew_margin <= 1.0;
    if (!ok) {
      RCLCPP_FATAL(get_logger(), "Invalid Plan parameters (see config/plan.yaml for bounds)");
      throw std::invalid_argument("invalid plan parameters");
    }
    RCLCPP_INFO(get_logger(),
        "Plan params: period=%.3f validity=%.3f scene_timeout=%.3f v_cruise=%.2f "
        "a_acc=%.2f a_dec=%.2f stop_margin=%.2f slew_margin=%.2f use_sim_time=%s",
        plan_period_, plan_validity_, dparams_.scene_timeout, pparams_.v_cruise,
        pparams_.a_acc, pparams_.a_dec, pparams_.stop_margin, pparams_.slew_margin,
        get_parameter("use_sim_time").as_bool() ? "true" : "false");
  }

  void scene_callback(const Scene::SharedPtr msg) { scene_ = msg; }

  void on_tick() {
    const rclcpp::Time now = get_clock()->now();
    if (now.nanoseconds() == 0) {
      return;  // sim clock not started
    }
    if (last_tick_ && now < *last_tick_) {
      RCLCPP_WARN(get_logger(), "Simulation time moved backwards: resetting Plan state");
      reset();
    }
    last_tick_ = now;
    const double t = now.seconds();

    rs::Decision d = rs::decide(scene_.get(), t, dparams_, mem_);
    if (d.entry_violation) {
      RCLCPP_WARN(get_logger(), "Front crossed entry_x=%.2f while entry was denied (flags 0x%02x)",
                  mem_.geo.entry_x, entry_denials_or_zero(t));
    }
    if (d.mode == Plan::MODE_TRACK) {
      update_path(d);
    }

    publish_plan(now, d);
    publish_status(now, d);
    log_transition(d);
  }

  // Builds the path if its inputs changed; latches FAULT if it breaks an invariant.
  void update_path(rs::Decision & d) {
    // Stop line released: accelerate from where the vehicle is, at the speed
    // the hold profile asked for there (0 when stopped at the line).
    if (had_stop_line_ && !d.stop_line && path_valid_) {
      accel_x_ = scene_->ego_x;
      accel_v_ = rs::speed_at_x(path_, scene_->ego_x);
    }
    had_stop_line_ = d.stop_line;

    const rs::PathRequest req{mem_.geo, d.stop_line, accel_x_, accel_v_,
                              std::min(mem_.geo.speed_limit, pparams_.v_cruise)};
    if (path_valid_ && req == last_req_) {
      return;
    }
    rs::build_path(req, pparams_, path_);
    const rs::PathCheck check = rs::check_path(path_, req, pparams_);
    if (check != rs::PathCheck::OK) {
      RCLCPP_ERROR(get_logger(), "Path invariant broken (%s): latching MODE_FAULT",
                   rs::path_check_to_string(check));
      mem_.fault_latched = true;
      path_valid_ = false;
      d = rs::fault_decision();
      return;
    }
    last_req_ = req;
    path_valid_ = true;
    fill_nav_path();
    RCLCPP_INFO(get_logger(), "Path rebuilt: %zu points, stop_line=%s, accel from x=%.2f v=%.2f",
                path_.size(), req.stop_line ? "true" : "false", req.accel_x, req.accel_v);
  }

  uint8_t entry_denials_or_zero(double t) const {
    return scene_ ? rs::entry_denials(*scene_, t, dparams_) : 0;
  }

  void fill_nav_path() {
    nav_path_.header.frame_id = "map";
    nav_path_.poses.resize(path_.size());
    for (std::size_t i = 0; i < path_.size(); ++i) {
      const std::size_t a = i + 1 < path_.size() ? i : i - 1;
      const double yaw = std::atan2(path_[a + 1].y - path_[a].y, path_[a + 1].x - path_[a].x);
      auto & ps = nav_path_.poses[i];
      ps.header.frame_id = "map";
      ps.pose.position.x = path_[i].x;
      ps.pose.position.y = path_[i].y;
      ps.pose.orientation.z = std::sin(0.5 * yaw);
      ps.pose.orientation.w = std::cos(0.5 * yaw);
    }
  }

  void publish_plan(const rclcpp::Time & now, const rs::Decision & d) {
    plan_msg_.header.stamp = now;
    plan_msg_.header.frame_id = "map";
    plan_msg_.scene_stamp = scene_ ? scene_->header.stamp : builtin_interfaces::msg::Time();
    plan_msg_.valid_until = now + rclcpp::Duration::from_seconds(plan_validity_);
    plan_msg_.seq = ++seq_;
    plan_msg_.mode = d.mode;
    // MODE_STOP / MODE_FAULT: Act ignores the path; send none.
    if (d.mode == Plan::MODE_TRACK) {
      plan_msg_.path.assign(path_.begin(), path_.end());
    } else {
      plan_msg_.path.clear();
    }
    plan_msg_.speed_limit = mem_.has_geometry ? mem_.geo.speed_limit
                                              : rs::path_const::kDefaultSpeedLimit;
    plan_msg_.has_stop_line = d.stop_line;
    plan_msg_.stop_line_x = d.stop_line ? mem_.geo.entry_x : 0.0;
    plan_msg_.decision_state = d.label;
    plan_pub_->publish(plan_msg_);

    nav_path_.header.stamp = now;
    if (d.mode == Plan::MODE_TRACK) {
      path_pub_->publish(nav_path_);
    } else {
      NavPath empty;
      empty.header = nav_path_.header;
      path_pub_->publish(empty);
    }
  }

  void publish_status(const rclcpp::Time & now, const rs::Decision & d) {
    PlanStatus s;
    s.header.stamp = now;
    s.header.frame_id = "map";
    s.state = d.state;
    s.reason_code = d.reason;
    s.reason = rs::plan_reason_to_string(d.reason);
    s.plan_seq = seq_;
    s.scene_seq = scene_ ? scene_->seq : 0;
    s.scene_age = scene_ ? now.seconds() - rs::to_seconds(scene_->header.stamp) : -1.0;
    s.committed = mem_.committed;
    s.deny_flags = d.deny_flags;
    status_pub_->publish(s);

    StringMsg state;
    state.data = d.label;
    state_pub_->publish(state);
  }

  void log_transition(const rs::Decision & d) {
    if (logged_label_ == d.label && logged_deny_ == d.deny_flags) {
      return;
    }
    RCLCPP_INFO(get_logger(), "Plan %s -> %s (reason %s, deny 0x%02x, committed %s)",
                logged_label_.c_str(), d.label,
                rs::plan_reason_to_string(d.reason), d.deny_flags,
                mem_.committed ? "true" : "false");
    logged_label_ = d.label;
    logged_deny_ = d.deny_flags;
  }

  void reset() {
    scene_.reset();
    mem_ = rs::PlanMemory{};
    path_valid_ = false;
    had_stop_line_ = false;
    accel_x_ = rs::path_const::kStartX;
    accel_v_ = 0.0;
    seq_ = 0;
  }

  // Parameters
  double plan_period_ = 0.1;
  double plan_validity_ = 0.3;
  rs::DecisionParams dparams_{};
  rs::PathParams pparams_{};

  // State
  Scene::SharedPtr scene_;
  rs::PlanMemory mem_;
  std::vector<rs::PlanPoint> path_;
  rs::PathRequest last_req_{};
  bool path_valid_ = false;
  bool had_stop_line_ = false;
  double accel_x_ = rs::path_const::kStartX;
  double accel_v_ = 0.0;
  uint32_t seq_ = 0;
  std::optional<rclcpp::Time> last_tick_;
  std::string logged_label_ = "START";
  uint8_t logged_deny_ = 0;

  // Reused messages (built in place, never regrown past 250 points).
  Plan plan_msg_;
  NavPath nav_path_;

  rclcpp::Subscription<Scene>::SharedPtr scene_sub_;
  rclcpp::Publisher<Plan>::SharedPtr plan_pub_;
  rclcpp::Publisher<PlanStatus>::SharedPtr status_pub_;
  rclcpp::Publisher<StringMsg>::SharedPtr state_pub_;
  rclcpp::Publisher<NavPath>::SharedPtr path_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PlanNode>());
  rclcpp::shutdown();
  return 0;
}
