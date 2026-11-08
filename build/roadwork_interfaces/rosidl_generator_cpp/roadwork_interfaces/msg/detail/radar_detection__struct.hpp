// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roadwork_interfaces:msg/RadarDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/radar_detection.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__STRUCT_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__roadwork_interfaces__msg__RadarDetection __attribute__((deprecated))
#else
# define DEPRECATED__roadwork_interfaces__msg__RadarDetection __declspec(deprecated)
#endif

namespace roadwork_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RadarDetection_
{
  using Type = RadarDetection_<ContainerAllocator>;

  explicit RadarDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->range = 0.0;
      this->azimuth = 0.0;
      this->radial_velocity = 0.0;
    }
  }

  explicit RadarDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->range = 0.0;
      this->azimuth = 0.0;
      this->radial_velocity = 0.0;
    }
  }

  // field types and members
  using _range_type =
    double;
  _range_type range;
  using _azimuth_type =
    double;
  _azimuth_type azimuth;
  using _radial_velocity_type =
    double;
  _radial_velocity_type radial_velocity;

  // setters for named parameter idiom
  Type & set__range(
    const double & _arg)
  {
    this->range = _arg;
    return *this;
  }
  Type & set__azimuth(
    const double & _arg)
  {
    this->azimuth = _arg;
    return *this;
  }
  Type & set__radial_velocity(
    const double & _arg)
  {
    this->radial_velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roadwork_interfaces::msg::RadarDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const roadwork_interfaces::msg::RadarDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roadwork_interfaces::msg::RadarDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roadwork_interfaces::msg::RadarDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roadwork_interfaces::msg::RadarDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roadwork_interfaces::msg::RadarDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roadwork_interfaces::msg::RadarDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roadwork_interfaces::msg::RadarDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roadwork_interfaces::msg::RadarDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roadwork_interfaces::msg::RadarDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roadwork_interfaces__msg__RadarDetection
    std::shared_ptr<roadwork_interfaces::msg::RadarDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roadwork_interfaces__msg__RadarDetection
    std::shared_ptr<roadwork_interfaces::msg::RadarDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RadarDetection_ & other) const
  {
    if (this->range != other.range) {
      return false;
    }
    if (this->azimuth != other.azimuth) {
      return false;
    }
    if (this->radial_velocity != other.radial_velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const RadarDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RadarDetection_

// alias to use template instance with default allocator
using RadarDetection =
  roadwork_interfaces::msg::RadarDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace roadwork_interfaces

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__STRUCT_HPP_
