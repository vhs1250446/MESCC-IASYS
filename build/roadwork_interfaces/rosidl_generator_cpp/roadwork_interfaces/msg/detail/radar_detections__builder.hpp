// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roadwork_interfaces:msg/RadarDetections.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/radar_detections.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__BUILDER_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roadwork_interfaces/msg/detail/radar_detections__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roadwork_interfaces
{

namespace msg
{

namespace builder
{

class Init_RadarDetections_detections
{
public:
  explicit Init_RadarDetections_detections(::roadwork_interfaces::msg::RadarDetections & msg)
  : msg_(msg)
  {}
  ::roadwork_interfaces::msg::RadarDetections detections(::roadwork_interfaces::msg::RadarDetections::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roadwork_interfaces::msg::RadarDetections msg_;
};

class Init_RadarDetections_header
{
public:
  Init_RadarDetections_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RadarDetections_detections header(::roadwork_interfaces::msg::RadarDetections::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RadarDetections_detections(msg_);
  }

private:
  ::roadwork_interfaces::msg::RadarDetections msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roadwork_interfaces::msg::RadarDetections>()
{
  return roadwork_interfaces::msg::builder::Init_RadarDetections_header();
}

}  // namespace roadwork_interfaces

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__BUILDER_HPP_
