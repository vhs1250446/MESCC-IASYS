// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roadwork_solution_msgs:msg/ActStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/act_status.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__TRAITS_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roadwork_solution_msgs/msg/detail/act_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace roadwork_solution_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ActStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << ", ";
  }

  // member: plan_seq
  {
    out << "plan_seq: ";
    rosidl_generator_traits::value_to_yaml(msg.plan_seq, out);
    out << ", ";
  }

  // member: plan_age
  {
    out << "plan_age: ";
    rosidl_generator_traits::value_to_yaml(msg.plan_age, out);
    out << ", ";
  }

  // member: odom_age
  {
    out << "odom_age: ";
    rosidl_generator_traits::value_to_yaml(msg.odom_age, out);
    out << ", ";
  }

  // member: target_index
  {
    out << "target_index: ";
    rosidl_generator_traits::value_to_yaml(msg.target_index, out);
    out << ", ";
  }

  // member: cross_track_error
  {
    out << "cross_track_error: ";
    rosidl_generator_traits::value_to_yaml(msg.cross_track_error, out);
    out << ", ";
  }

  // member: heading_error
  {
    out << "heading_error: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_error, out);
    out << ", ";
  }

  // member: speed_raw
  {
    out << "speed_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_raw, out);
    out << ", ";
  }

  // member: steering_raw
  {
    out << "steering_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_raw, out);
    out << ", ";
  }

  // member: speed_cmd
  {
    out << "speed_cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_cmd, out);
    out << ", ";
  }

  // member: steering_cmd
  {
    out << "steering_cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_cmd, out);
    out << ", ";
  }

  // member: limit_flags
  {
    out << "limit_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.limit_flags, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ActStatus & msg,
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

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }

  // member: plan_seq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "plan_seq: ";
    rosidl_generator_traits::value_to_yaml(msg.plan_seq, out);
    out << "\n";
  }

  // member: plan_age
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "plan_age: ";
    rosidl_generator_traits::value_to_yaml(msg.plan_age, out);
    out << "\n";
  }

  // member: odom_age
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "odom_age: ";
    rosidl_generator_traits::value_to_yaml(msg.odom_age, out);
    out << "\n";
  }

  // member: target_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_index: ";
    rosidl_generator_traits::value_to_yaml(msg.target_index, out);
    out << "\n";
  }

  // member: cross_track_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cross_track_error: ";
    rosidl_generator_traits::value_to_yaml(msg.cross_track_error, out);
    out << "\n";
  }

  // member: heading_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_error: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_error, out);
    out << "\n";
  }

  // member: speed_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_raw, out);
    out << "\n";
  }

  // member: steering_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_raw, out);
    out << "\n";
  }

  // member: speed_cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_cmd, out);
    out << "\n";
  }

  // member: steering_cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_cmd, out);
    out << "\n";
  }

  // member: limit_flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "limit_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.limit_flags, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ActStatus & msg, bool use_flow_style = false)
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

}  // namespace roadwork_solution_msgs

namespace rosidl_generator_traits
{

[[deprecated("use roadwork_solution_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roadwork_solution_msgs::msg::ActStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  roadwork_solution_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roadwork_solution_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const roadwork_solution_msgs::msg::ActStatus & msg)
{
  return roadwork_solution_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<roadwork_solution_msgs::msg::ActStatus>()
{
  return "roadwork_solution_msgs::msg::ActStatus";
}

template<>
inline const char * name<roadwork_solution_msgs::msg::ActStatus>()
{
  return "roadwork_solution_msgs/msg/ActStatus";
}

template<>
struct has_fixed_size<roadwork_solution_msgs::msg::ActStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roadwork_solution_msgs::msg::ActStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roadwork_solution_msgs::msg::ActStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__TRAITS_HPP_
