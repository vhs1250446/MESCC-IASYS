// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roadwork_solution_msgs:msg/PlanPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/plan_point.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__BUILDER_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roadwork_solution_msgs/msg/detail/plan_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roadwork_solution_msgs
{

namespace msg
{

namespace builder
{

class Init_PlanPoint_speed
{
public:
  explicit Init_PlanPoint_speed(::roadwork_solution_msgs::msg::PlanPoint & msg)
  : msg_(msg)
  {}
  ::roadwork_solution_msgs::msg::PlanPoint speed(::roadwork_solution_msgs::msg::PlanPoint::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::PlanPoint msg_;
};

class Init_PlanPoint_y
{
public:
  explicit Init_PlanPoint_y(::roadwork_solution_msgs::msg::PlanPoint & msg)
  : msg_(msg)
  {}
  Init_PlanPoint_speed y(::roadwork_solution_msgs::msg::PlanPoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PlanPoint_speed(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::PlanPoint msg_;
};

class Init_PlanPoint_x
{
public:
  Init_PlanPoint_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanPoint_y x(::roadwork_solution_msgs::msg::PlanPoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PlanPoint_y(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::PlanPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roadwork_solution_msgs::msg::PlanPoint>()
{
  return roadwork_solution_msgs::msg::builder::Init_PlanPoint_x();
}

}  // namespace roadwork_solution_msgs

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__BUILDER_HPP_
