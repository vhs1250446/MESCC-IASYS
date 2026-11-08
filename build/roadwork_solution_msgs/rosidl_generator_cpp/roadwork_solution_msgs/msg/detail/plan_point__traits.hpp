// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roadwork_solution_msgs:msg/PlanPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/plan_point.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__TRAITS_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roadwork_solution_msgs/msg/detail/plan_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace roadwork_solution_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PlanPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PlanPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PlanPoint & msg, bool use_flow_style = false)
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
  const roadwork_solution_msgs::msg::PlanPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  roadwork_solution_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roadwork_solution_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const roadwork_solution_msgs::msg::PlanPoint & msg)
{
  return roadwork_solution_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<roadwork_solution_msgs::msg::PlanPoint>()
{
  return "roadwork_solution_msgs::msg::PlanPoint";
}

template<>
inline const char * name<roadwork_solution_msgs::msg::PlanPoint>()
{
  return "roadwork_solution_msgs/msg/PlanPoint";
}

template<>
struct has_fixed_size<roadwork_solution_msgs::msg::PlanPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<roadwork_solution_msgs::msg::PlanPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<roadwork_solution_msgs::msg::PlanPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__TRAITS_HPP_
