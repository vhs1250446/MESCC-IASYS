// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roadwork_interfaces:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/vehicle_command.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__BUILDER_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roadwork_interfaces/msg/detail/vehicle_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roadwork_interfaces
{

namespace msg
{

namespace builder
{

class Init_VehicleCommand_steering_angle
{
public:
  explicit Init_VehicleCommand_steering_angle(::roadwork_interfaces::msg::VehicleCommand & msg)
  : msg_(msg)
  {}
  ::roadwork_interfaces::msg::VehicleCommand steering_angle(::roadwork_interfaces::msg::VehicleCommand::_steering_angle_type arg)
  {
    msg_.steering_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roadwork_interfaces::msg::VehicleCommand msg_;
};

class Init_VehicleCommand_speed
{
public:
  explicit Init_VehicleCommand_speed(::roadwork_interfaces::msg::VehicleCommand & msg)
  : msg_(msg)
  {}
  Init_VehicleCommand_steering_angle speed(::roadwork_interfaces::msg::VehicleCommand::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_VehicleCommand_steering_angle(msg_);
  }

private:
  ::roadwork_interfaces::msg::VehicleCommand msg_;
};

class Init_VehicleCommand_header
{
public:
  Init_VehicleCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleCommand_speed header(::roadwork_interfaces::msg::VehicleCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleCommand_speed(msg_);
  }

private:
  ::roadwork_interfaces::msg::VehicleCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roadwork_interfaces::msg::VehicleCommand>()
{
  return roadwork_interfaces::msg::builder::Init_VehicleCommand_header();
}

}  // namespace roadwork_interfaces

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__BUILDER_HPP_
