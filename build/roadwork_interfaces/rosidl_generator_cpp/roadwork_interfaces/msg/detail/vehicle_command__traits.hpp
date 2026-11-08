// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roadwork_interfaces:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/vehicle_command.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__TRAITS_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roadwork_interfaces/msg/detail/vehicle_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace roadwork_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: steering_angle
  {
    out << "steering_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: steering_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VehicleCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace roadwork_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roadwork_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roadwork_interfaces::msg::VehicleCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  roadwork_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roadwork_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const roadwork_interfaces::msg::VehicleCommand & msg)
{
  return roadwork_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<roadwork_interfaces::msg::VehicleCommand>()
{
  return "roadwork_interfaces::msg::VehicleCommand";
}

template<>
inline const char * name<roadwork_interfaces::msg::VehicleCommand>()
{
  return "roadwork_interfaces/msg/VehicleCommand";
}

template<>
struct has_fixed_size<roadwork_interfaces::msg::VehicleCommand>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<roadwork_interfaces::msg::VehicleCommand>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<roadwork_interfaces::msg::VehicleCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__TRAITS_HPP_
