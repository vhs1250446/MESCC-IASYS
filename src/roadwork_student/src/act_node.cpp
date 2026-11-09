#include <chrono>
#include <cmath>
#include <functional>
#include <memory>
#include <optional>
#include <stdexcept>


#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "roadwork_interfaces/msg/vehicle_command.hpp"
#include "roadwork_solution_msgs/msg/act_status.hpp"
#include "roadwork_solution_msgs/msg/plan.hpp"
#include "roadwork_solution_msgs/msg/plan_point.hpp"

using Odometry = nav_msgs::msg::Odometry;
using ActStatus = roadwork_solution_msgs::msg::ActStatus;
using Plan = roadwork_solution_msgs::msg::Plan;
using VehicleCommand = roadwork_interfaces::msg::VehicleCommand;

// /vehicle/odometry [nav_msgs/msg/Odometry]

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
};

struct ActDecision {
  double speed;
  double steering;
  uint8_t state;
  uint8_t reason;
};

class ActNode : public rclcpp::Node {

  public:
    ActNode() : Node("act") {

      params_ = load_params();

      odometry_sub_ = create_subscription<Odometry>("/vehicle/odometry", rclcpp::SensorDataQoS(), std::bind(&ActNode::odometry_callback, this, std::placeholders::_1));
      plan_sub_ = create_subscription<Plan>("/solution/plan", rclcpp::QoS(1).reliable(), std::bind(&ActNode::plan_callback, this, std::placeholders::_1));
    
      cmd_pub_ = create_publisher<VehicleCommand>("/vehicle/command", rclcpp::QoS(10).reliable());
      act_status_pub_ = create_publisher<ActStatus>("/solution/act_status", rclcpp::QoS(10).reliable());
      
      timer_ = rclcpp::create_timer(this, get_clock(), rclcpp::Duration::from_seconds(params_.control_period), std::bind(&ActNode::on_tick, this));

    }



  private:

    ActParams load_params() {
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
      
    if (p.control_period <= 0.0 || p.plan_timeout <= 0.0 ||
        p.scene_timeout <= 0.0 || p.odom_timeout <= 0.0 ||
        p.speed_cap <= 0.0 || p.max_steer <= 0.0 ||
        p.max_steer_rate <= 0.0 || p.wheelbase <= 0.0) {
        RCLCPP_FATAL(get_logger(), "Invalid Act parameters: periods, timeouts and limits must be positive");
        throw std::invalid_argument("invalid act parameters");
    }

    RCLCPP_INFO(get_logger(),
        "Act params: period=%.3f plan_timeout=%.3f scene_timeout=%.3f odom_timeout=%.3f "
        "speed_cap=%.2f max_steer=%.2f max_steer_rate=%.2f wheelbase=%.2f front_offset=%.2f "
        "use_sim_time=%s",
        p.control_period, p.plan_timeout, p.scene_timeout, p.odom_timeout,
        p.speed_cap, p.max_steer, p.max_steer_rate, p.wheelbase, p.front_offset,
        get_parameter("use_sim_time").as_bool() ? "true" : "false");
      
      return p;
    }

    void plan_callback(const roadwork_solution_msgs::msg::Plan::SharedPtr msg) {

    }

    void odometry_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {

    }

    void on_tick() {

    }

  ActParams params_;

  rclcpp::Subscription<roadwork_solution_msgs::msg::Plan>::SharedPtr plan_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odometry_sub_;
  rclcpp::Publisher<roadwork_interfaces::msg::VehicleCommand>::SharedPtr cmd_pub_;
  rclcpp::Publisher<ActStatus>::SharedPtr act_status_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};





// TODO: Subscribe to your plan; check validity, control the vehicle and publish /vehicle/command.
// TODO: Define your own internal ROS messages and update build dependencies.
// This deliberately provides no subscriptions, publishers, timers or algorithms.
int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<rclcpp::Node>("act"));
  rclcpp::shutdown();
}
