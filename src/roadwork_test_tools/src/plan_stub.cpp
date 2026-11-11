#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "roadwork_solution_msgs/msg/plan.hpp"
#include "roadwork_solution_msgs/msg/plan_point.hpp"

using Plan = roadwork_solution_msgs::msg::Plan;
using PlanPoint = roadwork_solution_msgs::msg::PlanPoint;

constexpr std::size_t kMaxPathPoints = 250;

class PlanStub : public rclcpp::Node {
public:
  PlanStub() : Node("plan_stub") {
    shape_ = declare_parameter<std::string>("shape", "straight");
    cruise_ = declare_parameter<double>("cruise_speed", 3.0);
    decel_ = declare_parameter<double>("planning_decel", 2.0);
    spacing_ = declare_parameter<double>("spacing", 0.5);
    goal_x_ = declare_parameter<double>("goal_x", 80.2);
    validity_ = declare_parameter<double>("validity", 0.3);
    stop_line_release_ = declare_parameter<double>("stop_line_release", -1.0);
    declare_parameter<bool>("publish_enabled", true);
    declare_parameter<bool>("mode_stop", false);

    if (spacing_ <= 0.0 || cruise_ <= 0.0 || decel_ <= 0.0 || validity_ <= 0.0) {
      RCLCPP_FATAL(get_logger(), "spacing, cruise_speed, planning_decel and validity must be positive");
      throw std::invalid_argument("invalid plan stub parameters");
    }

    path_ = build_path();
    if (path_.size() > kMaxPathPoints) {
      RCLCPP_FATAL(get_logger(), "Path has %zu points, the Plan message allows at most %zu",
                   path_.size(), kMaxPathPoints);
      throw std::runtime_error("path too long for Plan message");
    }

    RCLCPP_INFO(get_logger(), "Plan stub: shape=%s points=%zu cruise=%.2f",
                shape_.c_str(), path_.size(), cruise_);

    pub_ = create_publisher<Plan>("/solution/plan", rclcpp::QoS(1).reliable());
    timer_ = rclcpp::create_timer(this, get_clock(),
        rclcpp::Duration::from_seconds(0.1),
        std::bind(&PlanStub::on_tick, this));
  }

private:
  double lane_y(double x) const {
    const double own = -1.75;
    const double opposing = 1.75;
    if (shape_ != "bypass") {
      return own;
    }
    const double out_start = 26.0, out_end = 40.0;
    const double back_start = 50.0, back_end = 64.0;
    auto blend = [](double s) { return 0.5 - 0.5 * std::cos(M_PI * s); };
    if (x <= out_start || x >= back_end) {
      return own;
    }
    if (x < out_end) {
      return own + (opposing - own) * blend((x - out_start) / (out_end - out_start));
    }
    if (x <= back_start) {
      return opposing;
    }
    return opposing + (own - opposing) * blend((x - back_start) / (back_end - back_start));
  }

  std::vector<PlanPoint> build_path() const {
    std::vector<PlanPoint> path;
    for (double x = 0.0; x < goal_x_; x += spacing_) {
      PlanPoint p;
      p.x = x;
      p.y = lane_y(x);
      p.speed = std::min(cruise_, std::sqrt(2.0 * decel_ * (goal_x_ - x)));
      path.push_back(p);
    }
    PlanPoint last;
    last.x = goal_x_;
    last.y = lane_y(goal_x_);
    last.speed = 0.0;
    path.push_back(last);
    return path;
  }

  void on_tick() {
    const rclcpp::Time now = get_clock()->now();
    if (now.nanoseconds() == 0 || !get_parameter("publish_enabled").as_bool()) {
      return;
    }

    Plan plan;
    plan.header.stamp = now;
    plan.header.frame_id = "map";
    plan.scene_stamp = now;
    plan.valid_until = now + rclcpp::Duration::from_seconds(validity_);
    plan.seq = ++seq_;
    plan.mode = get_parameter("mode_stop").as_bool() ? Plan::MODE_STOP : Plan::MODE_TRACK;
    plan.path.assign(path_.begin(), path_.end());
    plan.speed_limit = 4.0;
    plan.has_stop_line = stop_line_release_ >= 0.0 && now.seconds() < stop_line_release_;
    plan.stop_line_x = 25.0;
    plan.decision_state = plan.has_stop_line ? "STUB_HOLD" : "STUB_GO";
    pub_->publish(plan);
  }

  std::string shape_;
  double cruise_, decel_, spacing_, goal_x_, validity_, stop_line_release_;
  std::vector<PlanPoint> path_;
  uint32_t seq_ = 0;
  rclcpp::Publisher<Plan>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PlanStub>());
  rclcpp::shutdown();
  return 0;
}