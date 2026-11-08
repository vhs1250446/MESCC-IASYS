// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roadwork_solution_msgs:msg/ActStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/act_status.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__BUILDER_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roadwork_solution_msgs/msg/detail/act_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roadwork_solution_msgs
{

namespace msg
{

namespace builder
{

class Init_ActStatus_limit_flags
{
public:
  explicit Init_ActStatus_limit_flags(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  ::roadwork_solution_msgs::msg::ActStatus limit_flags(::roadwork_solution_msgs::msg::ActStatus::_limit_flags_type arg)
  {
    msg_.limit_flags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_steering_cmd
{
public:
  explicit Init_ActStatus_steering_cmd(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_limit_flags steering_cmd(::roadwork_solution_msgs::msg::ActStatus::_steering_cmd_type arg)
  {
    msg_.steering_cmd = std::move(arg);
    return Init_ActStatus_limit_flags(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_speed_cmd
{
public:
  explicit Init_ActStatus_speed_cmd(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_steering_cmd speed_cmd(::roadwork_solution_msgs::msg::ActStatus::_speed_cmd_type arg)
  {
    msg_.speed_cmd = std::move(arg);
    return Init_ActStatus_steering_cmd(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_steering_raw
{
public:
  explicit Init_ActStatus_steering_raw(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_speed_cmd steering_raw(::roadwork_solution_msgs::msg::ActStatus::_steering_raw_type arg)
  {
    msg_.steering_raw = std::move(arg);
    return Init_ActStatus_speed_cmd(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_speed_raw
{
public:
  explicit Init_ActStatus_speed_raw(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_steering_raw speed_raw(::roadwork_solution_msgs::msg::ActStatus::_speed_raw_type arg)
  {
    msg_.speed_raw = std::move(arg);
    return Init_ActStatus_steering_raw(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_heading_error
{
public:
  explicit Init_ActStatus_heading_error(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_speed_raw heading_error(::roadwork_solution_msgs::msg::ActStatus::_heading_error_type arg)
  {
    msg_.heading_error = std::move(arg);
    return Init_ActStatus_speed_raw(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_cross_track_error
{
public:
  explicit Init_ActStatus_cross_track_error(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_heading_error cross_track_error(::roadwork_solution_msgs::msg::ActStatus::_cross_track_error_type arg)
  {
    msg_.cross_track_error = std::move(arg);
    return Init_ActStatus_heading_error(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_target_index
{
public:
  explicit Init_ActStatus_target_index(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_cross_track_error target_index(::roadwork_solution_msgs::msg::ActStatus::_target_index_type arg)
  {
    msg_.target_index = std::move(arg);
    return Init_ActStatus_cross_track_error(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_odom_age
{
public:
  explicit Init_ActStatus_odom_age(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_target_index odom_age(::roadwork_solution_msgs::msg::ActStatus::_odom_age_type arg)
  {
    msg_.odom_age = std::move(arg);
    return Init_ActStatus_target_index(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_plan_age
{
public:
  explicit Init_ActStatus_plan_age(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_odom_age plan_age(::roadwork_solution_msgs::msg::ActStatus::_plan_age_type arg)
  {
    msg_.plan_age = std::move(arg);
    return Init_ActStatus_odom_age(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_plan_seq
{
public:
  explicit Init_ActStatus_plan_seq(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_plan_age plan_seq(::roadwork_solution_msgs::msg::ActStatus::_plan_seq_type arg)
  {
    msg_.plan_seq = std::move(arg);
    return Init_ActStatus_plan_age(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_reason
{
public:
  explicit Init_ActStatus_reason(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_plan_seq reason(::roadwork_solution_msgs::msg::ActStatus::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_ActStatus_plan_seq(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_state
{
public:
  explicit Init_ActStatus_state(::roadwork_solution_msgs::msg::ActStatus & msg)
  : msg_(msg)
  {}
  Init_ActStatus_reason state(::roadwork_solution_msgs::msg::ActStatus::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_ActStatus_reason(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

class Init_ActStatus_header
{
public:
  Init_ActStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActStatus_state header(::roadwork_solution_msgs::msg::ActStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ActStatus_state(msg_);
  }

private:
  ::roadwork_solution_msgs::msg::ActStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roadwork_solution_msgs::msg::ActStatus>()
{
  return roadwork_solution_msgs::msg::builder::Init_ActStatus_header();
}

}  // namespace roadwork_solution_msgs

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__BUILDER_HPP_
