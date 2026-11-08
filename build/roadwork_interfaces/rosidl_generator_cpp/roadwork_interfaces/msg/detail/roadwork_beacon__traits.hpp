// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roadwork_interfaces:msg/RoadworkBeacon.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/roadwork_beacon.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__TRAITS_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roadwork_interfaces/msg/detail/roadwork_beacon__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace roadwork_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RoadworkBeacon & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: valid_for
  {
    out << "valid_for: ";
    rosidl_generator_traits::value_to_yaml(msg.valid_for, out);
    out << ", ";
  }

  // member: entry_x
  {
    out << "entry_x: ";
    rosidl_generator_traits::value_to_yaml(msg.entry_x, out);
    out << ", ";
  }

  // member: work_start
  {
    out << "work_start: ";
    rosidl_generator_traits::value_to_yaml(msg.work_start, out);
    out << ", ";
  }

  // member: work_end
  {
    out << "work_end: ";
    rosidl_generator_traits::value_to_yaml(msg.work_end, out);
    out << ", ";
  }

  // member: exit_x
  {
    out << "exit_x: ";
    rosidl_generator_traits::value_to_yaml(msg.exit_x, out);
    out << ", ";
  }

  // member: speed_limit
  {
    out << "speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_limit, out);
    out << ", ";
  }

  // member: pass_side
  {
    out << "pass_side: ";
    rosidl_generator_traits::value_to_yaml(msg.pass_side, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RoadworkBeacon & msg,
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

  // member: valid_for
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid_for: ";
    rosidl_generator_traits::value_to_yaml(msg.valid_for, out);
    out << "\n";
  }

  // member: entry_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "entry_x: ";
    rosidl_generator_traits::value_to_yaml(msg.entry_x, out);
    out << "\n";
  }

  // member: work_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "work_start: ";
    rosidl_generator_traits::value_to_yaml(msg.work_start, out);
    out << "\n";
  }

  // member: work_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "work_end: ";
    rosidl_generator_traits::value_to_yaml(msg.work_end, out);
    out << "\n";
  }

  // member: exit_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "exit_x: ";
    rosidl_generator_traits::value_to_yaml(msg.exit_x, out);
    out << "\n";
  }

  // member: speed_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_limit, out);
    out << "\n";
  }

  // member: pass_side
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pass_side: ";
    rosidl_generator_traits::value_to_yaml(msg.pass_side, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RoadworkBeacon & msg, bool use_flow_style = false)
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
  const roadwork_interfaces::msg::RoadworkBeacon & msg,
  std::ostream & out, size_t indentation = 0)
{
  roadwork_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roadwork_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const roadwork_interfaces::msg::RoadworkBeacon & msg)
{
  return roadwork_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<roadwork_interfaces::msg::RoadworkBeacon>()
{
  return "roadwork_interfaces::msg::RoadworkBeacon";
}

template<>
inline const char * name<roadwork_interfaces::msg::RoadworkBeacon>()
{
  return "roadwork_interfaces/msg/RoadworkBeacon";
}

template<>
struct has_fixed_size<roadwork_interfaces::msg::RoadworkBeacon>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<roadwork_interfaces::msg::RoadworkBeacon>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<roadwork_interfaces::msg::RoadworkBeacon>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__TRAITS_HPP_
