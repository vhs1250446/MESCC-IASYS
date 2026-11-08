// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/plan.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__BUILDER_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roadwork_solution_msgs/msg/detail/plan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roadwork_solution_msgs
{

namespace msg
{

namespace builder
{

class Init_Plan_decision_state
{
public:
  explicit Init_Plan_decision_state(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  ::roadwork_solution_msgs::msg::Plan decision_state(::roadwork_solution_msgs::msg::Plan::_decision_state_type arg)
  {
    msg_.decision_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_stop_line_x
{
public:
  explicit Init_Plan_stop_line_x(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  Init_Plan_decision_state stop_line_x(::roadwork_solution_msgs::msg::Plan::_stop_line_x_type arg)
  {
    msg_.stop_line_x = std::move(arg);
    return Init_Plan_decision_state(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_has_stop_line
{
public:
  explicit Init_Plan_has_stop_line(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  Init_Plan_stop_line_x has_stop_line(::roadwork_solution_msgs::msg::Plan::_has_stop_line_type arg)
  {
    msg_.has_stop_line = std::move(arg);
    return Init_Plan_stop_line_x(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_speed_limit
{
public:
  explicit Init_Plan_speed_limit(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  Init_Plan_has_stop_line speed_limit(::roadwork_solution_msgs::msg::Plan::_speed_limit_type arg)
  {
    msg_.speed_limit = std::move(arg);
    return Init_Plan_has_stop_line(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_path
{
public:
  explicit Init_Plan_path(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  Init_Plan_speed_limit path(::roadwork_solution_msgs::msg::Plan::_path_type arg)
  {
    msg_.path = std::move(arg);
    return Init_Plan_speed_limit(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_mode
{
public:
  explicit Init_Plan_mode(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  Init_Plan_path mode(::roadwork_solution_msgs::msg::Plan::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_Plan_path(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_seq
{
public:
  explicit Init_Plan_seq(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  Init_Plan_mode seq(::roadwork_solution_msgs::msg::Plan::_seq_type arg)
  {
    msg_.seq = std::move(arg);
    return Init_Plan_mode(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_valid_until
{
public:
  explicit Init_Plan_valid_until(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  Init_Plan_seq valid_until(::roadwork_solution_msgs::msg::Plan::_valid_until_type arg)
  {
    msg_.valid_until = std::move(arg);
    return Init_Plan_seq(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_scene_stamp
{
public:
  explicit Init_Plan_scene_stamp(::roadwork_solution_msgs::msg::Plan & msg)
  : msg_(msg)
  {}
  Init_Plan_valid_until scene_stamp(::roadwork_solution_msgs::msg::Plan::_scene_stamp_type arg)
  {
    msg_.scene_stamp = std::move(arg);
    return Init_Plan_valid_until(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

class Init_Plan_header
{
public:
  Init_Plan_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Plan_scene_stamp header(::roadwork_solution_msgs::msg::Plan::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Plan_scene_stamp(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::Plan msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roadwork_solution_msgs::msg::Plan>()
{
  return roadwork_solution_msgs::msg::builder::Init_Plan_header();
}

}  // namespace roadwork_solution_msgs

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__BUILDER_HPP_
