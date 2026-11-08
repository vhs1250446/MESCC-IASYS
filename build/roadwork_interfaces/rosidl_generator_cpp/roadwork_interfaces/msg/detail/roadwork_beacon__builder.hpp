// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roadwork_interfaces:msg/RoadworkBeacon.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/roadwork_beacon.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__BUILDER_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roadwork_interfaces/msg/detail/roadwork_beacon__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roadwork_interfaces
{

namespace msg
{

namespace builder
{

class Init_RoadworkBeacon_pass_side
{
public:
  explicit Init_RoadworkBeacon_pass_side(::roadwork_interfaces::msg::RoadworkBeacon & msg)
  : msg_(msg)
  {}
  ::roadwork_interfaces::msg::RoadworkBeacon pass_side(::roadwork_interfaces::msg::RoadworkBeacon::_pass_side_type arg)
  {
    msg_.pass_side = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roadwork_interfaces::msg::RoadworkBeacon msg_;
};

class Init_RoadworkBeacon_speed_limit
{
public:
  explicit Init_RoadworkBeacon_speed_limit(::roadwork_interfaces::msg::RoadworkBeacon & msg)
  : msg_(msg)
  {}
  Init_RoadworkBeacon_pass_side speed_limit(::roadwork_interfaces::msg::RoadworkBeacon::_speed_limit_type arg)
  {
    msg_.speed_limit = std::move(arg);
    return Init_RoadworkBeacon_pass_side(msg_);
  }

private:
  ::roadwork_interfaces::msg::RoadworkBeacon msg_;
};

class Init_RoadworkBeacon_exit_x
{
public:
  explicit Init_RoadworkBeacon_exit_x(::roadwork_interfaces::msg::RoadworkBeacon & msg)
  : msg_(msg)
  {}
  Init_RoadworkBeacon_speed_limit exit_x(::roadwork_interfaces::msg::RoadworkBeacon::_exit_x_type arg)
  {
    msg_.exit_x = std::move(arg);
    return Init_RoadworkBeacon_speed_limit(msg_);
  }

private:
  ::roadwork_interfaces::msg::RoadworkBeacon msg_;
};

class Init_RoadworkBeacon_work_end
{
public:
  explicit Init_RoadworkBeacon_work_end(::roadwork_interfaces::msg::RoadworkBeacon & msg)
  : msg_(msg)
  {}
  Init_RoadworkBeacon_exit_x work_end(::roadwork_interfaces::msg::RoadworkBeacon::_work_end_type arg)
  {
    msg_.work_end = std::move(arg);
    return Init_RoadworkBeacon_exit_x(msg_);
  }

private:
  ::roadwork_interfaces::msg::RoadworkBeacon msg_;
};

class Init_RoadworkBeacon_work_start
{
public:
  explicit Init_RoadworkBeacon_work_start(::roadwork_interfaces::msg::RoadworkBeacon & msg)
  : msg_(msg)
  {}
  Init_RoadworkBeacon_work_end work_start(::roadwork_interfaces::msg::RoadworkBeacon::_work_start_type arg)
  {
    msg_.work_start = std::move(arg);
    return Init_RoadworkBeacon_work_end(msg_);
  }

private:
  ::roadwork_interfaces::msg::RoadworkBeacon msg_;
};

class Init_RoadworkBeacon_entry_x
{
public:
  explicit Init_RoadworkBeacon_entry_x(::roadwork_interfaces::msg::RoadworkBeacon & msg)
  : msg_(msg)
  {}
  Init_RoadworkBeacon_work_start entry_x(::roadwork_interfaces::msg::RoadworkBeacon::_entry_x_type arg)
  {
    msg_.entry_x = std::move(arg);
    return Init_RoadworkBeacon_work_start(msg_);
  }

private:
  ::roadwork_interfaces::msg::RoadworkBeacon msg_;
};

class Init_RoadworkBeacon_valid_for
{
public:
  explicit Init_RoadworkBeacon_valid_for(::roadwork_interfaces::msg::RoadworkBeacon & msg)
  : msg_(msg)
  {}
  Init_RoadworkBeacon_entry_x valid_for(::roadwork_interfaces::msg::RoadworkBeacon::_valid_for_type arg)
  {
    msg_.valid_for = std::move(arg);
    return Init_RoadworkBeacon_entry_x(msg_);
  }

private:
  ::roadwork_interfaces::msg::RoadworkBeacon msg_;
};

class Init_RoadworkBeacon_header
{
public:
  Init_RoadworkBeacon_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoadworkBeacon_valid_for header(::roadwork_interfaces::msg::RoadworkBeacon::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RoadworkBeacon_valid_for(msg_);
  }

private:
  ::roadwork_interfaces::msg::RoadworkBeacon msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roadwork_interfaces::msg::RoadworkBeacon>()
{
  return roadwork_interfaces::msg::builder::Init_RoadworkBeacon_header();
}

}  // namespace roadwork_interfaces

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__BUILDER_HPP_
