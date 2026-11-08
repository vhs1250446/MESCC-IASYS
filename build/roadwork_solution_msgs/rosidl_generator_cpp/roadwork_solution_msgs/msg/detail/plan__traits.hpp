// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/plan.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__TRAITS_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roadwork_solution_msgs/msg/detail/plan__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'scene_stamp'
// Member 'valid_until'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'path'
#include "roadwork_solution_msgs/msg/detail/plan_point__traits.hpp"

namespace roadwork_solution_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Plan & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: scene_stamp
  {
    out << "scene_stamp: ";
    to_flow_style_yaml(msg.scene_stamp, out);
    out << ", ";
  }

  // member: valid_until
  {
    out << "valid_until: ";
    to_flow_style_yaml(msg.valid_until, out);
    out << ", ";
  }

  // member: seq
  {
    out << "seq: ";
    rosidl_generator_traits::value_to_yaml(msg.seq, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: path
  {
    if (msg.path.size() == 0) {
      out << "path: []";
    } else {
      out << "path: [";
      size_t pending_items = msg.path.size();
      for (auto item : msg.path) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: speed_limit
  {
    out << "speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_limit, out);
    out << ", ";
  }

  // member: has_stop_line
  {
    out << "has_stop_line: ";
    rosidl_generator_traits::value_to_yaml(msg.has_stop_line, out);
    out << ", ";
  }

  // member: stop_line_x
  {
    out << "stop_line_x: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_line_x, out);
    out << ", ";
  }

  // member: decision_state
  {
    out << "decision_state: ";
    rosidl_generator_traits::value_to_yaml(msg.decision_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Plan & msg,
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

  // member: scene_stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scene_stamp:\n";
    to_block_style_yaml(msg.scene_stamp, out, indentation + 2);
  }

  // member: valid_until
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid_until:\n";
    to_block_style_yaml(msg.valid_until, out, indentation + 2);
  }

  // member: seq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seq: ";
    rosidl_generator_traits::value_to_yaml(msg.seq, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.path.size() == 0) {
      out << "path: []\n";
    } else {
      out << "path:\n";
      for (auto item : msg.path) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
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

  // member: has_stop_line
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "has_stop_line: ";
    rosidl_generator_traits::value_to_yaml(msg.has_stop_line, out);
    out << "\n";
  }

  // member: stop_line_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stop_line_x: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_line_x, out);
    out << "\n";
  }

  // member: decision_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "decision_state: ";
    rosidl_generator_traits::value_to_yaml(msg.decision_state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Plan & msg, bool use_flow_style = false)
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
  const roadwork_solution_msgs::msg::Plan & msg,
  std::ostream & out, size_t indentation = 0)
{
  roadwork_solution_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roadwork_solution_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const roadwork_solution_msgs::msg::Plan & msg)
{
  return roadwork_solution_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<roadwork_solution_msgs::msg::Plan>()
{
  return "roadwork_solution_msgs::msg::Plan";
}

template<>
inline const char * name<roadwork_solution_msgs::msg::Plan>()
{
  return "roadwork_solution_msgs/msg/Plan";
}

template<>
struct has_fixed_size<roadwork_solution_msgs::msg::Plan>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roadwork_solution_msgs::msg::Plan>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roadwork_solution_msgs::msg::Plan>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__TRAITS_HPP_
