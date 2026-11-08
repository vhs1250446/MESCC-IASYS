// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roadwork_interfaces:msg/RadarDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/radar_detection.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__TRAITS_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roadwork_interfaces/msg/detail/radar_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace roadwork_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RadarDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: range
  {
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << ", ";
  }

  // member: azimuth
  {
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << ", ";
  }

  // member: radial_velocity
  {
    out << "radial_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.radial_velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RadarDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << "\n";
  }

  // member: azimuth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << "\n";
  }

  // member: radial_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radial_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.radial_velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RadarDetection & msg, bool use_flow_style = false)
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
  const roadwork_interfaces::msg::RadarDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  roadwork_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roadwork_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const roadwork_interfaces::msg::RadarDetection & msg)
{
  return roadwork_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<roadwork_interfaces::msg::RadarDetection>()
{
  return "roadwork_interfaces::msg::RadarDetection";
}

template<>
inline const char * name<roadwork_interfaces::msg::RadarDetection>()
{
  return "roadwork_interfaces/msg/RadarDetection";
}

template<>
struct has_fixed_size<roadwork_interfaces::msg::RadarDetection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<roadwork_interfaces::msg::RadarDetection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<roadwork_interfaces::msg::RadarDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__TRAITS_HPP_
