// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roadwork_interfaces:msg/RadarDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/radar_detection.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__BUILDER_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roadwork_interfaces/msg/detail/radar_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roadwork_interfaces
{

namespace msg
{

namespace builder
{

class Init_RadarDetection_radial_velocity
{
public:
  explicit Init_RadarDetection_radial_velocity(::roadwork_interfaces::msg::RadarDetection & msg)
  : msg_(msg)
  {}
  ::roadwork_interfaces::msg::RadarDetection radial_velocity(::roadwork_interfaces::msg::RadarDetection::_radial_velocity_type arg)
  {
    msg_.radial_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roadwork_interfaces::msg::RadarDetection msg_;
};

class Init_RadarDetection_azimuth
{
public:
  explicit Init_RadarDetection_azimuth(::roadwork_interfaces::msg::RadarDetection & msg)
  : msg_(msg)
  {}
  Init_RadarDetection_radial_velocity azimuth(::roadwork_interfaces::msg::RadarDetection::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_RadarDetection_radial_velocity(msg_);
  }

private:
  ::roadwork_interfaces::msg::RadarDetection msg_;
};

class Init_RadarDetection_range
{
public:
  Init_RadarDetection_range()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarDetection_azimuth range(::roadwork_interfaces::msg::RadarDetection::_range_type arg)
  {
    msg_.range = std::move(arg);
    return Init_RadarDetection_azimuth(msg_);
  }

private:
  ::roadwork_interfaces::msg::RadarDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roadwork_interfaces::msg::RadarDetection>()
{
  return roadwork_interfaces::msg::builder::Init_RadarDetection_range();
}

}  // namespace roadwork_interfaces

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__BUILDER_HPP_
