// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roadwork_interfaces:msg/RoadworkBeacon.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/roadwork_beacon.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__STRUCT_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__roadwork_interfaces__msg__RoadworkBeacon __attribute__((deprecated))
#else
# define DEPRECATED__roadwork_interfaces__msg__RoadworkBeacon __declspec(deprecated)
#endif

namespace roadwork_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoadworkBeacon_
{
  using Type = RoadworkBeacon_<ContainerAllocator>;

  explicit RoadworkBeacon_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->valid_for = 0.0;
      this->entry_x = 0.0;
      this->work_start = 0.0;
      this->work_end = 0.0;
      this->exit_x = 0.0;
      this->speed_limit = 0.0;
      this->pass_side = 0;
    }
  }

  explicit RoadworkBeacon_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->valid_for = 0.0;
      this->entry_x = 0.0;
      this->work_start = 0.0;
      this->work_end = 0.0;
      this->exit_x = 0.0;
      this->speed_limit = 0.0;
      this->pass_side = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _valid_for_type =
    double;
  _valid_for_type valid_for;
  using _entry_x_type =
    double;
  _entry_x_type entry_x;
  using _work_start_type =
    double;
  _work_start_type work_start;
  using _work_end_type =
    double;
  _work_end_type work_end;
  using _exit_x_type =
    double;
  _exit_x_type exit_x;
  using _speed_limit_type =
    double;
  _speed_limit_type speed_limit;
  using _pass_side_type =
    int8_t;
  _pass_side_type pass_side;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__valid_for(
    const double & _arg)
  {
    this->valid_for = _arg;
    return *this;
  }
  Type & set__entry_x(
    const double & _arg)
  {
    this->entry_x = _arg;
    return *this;
  }
  Type & set__work_start(
    const double & _arg)
  {
    this->work_start = _arg;
    return *this;
  }
  Type & set__work_end(
    const double & _arg)
  {
    this->work_end = _arg;
    return *this;
  }
  Type & set__exit_x(
    const double & _arg)
  {
    this->exit_x = _arg;
    return *this;
  }
  Type & set__speed_limit(
    const double & _arg)
  {
    this->speed_limit = _arg;
    return *this;
  }
  Type & set__pass_side(
    const int8_t & _arg)
  {
    this->pass_side = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator> *;
  using ConstRawPtr =
    const roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roadwork_interfaces__msg__RoadworkBeacon
    std::shared_ptr<roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roadwork_interfaces__msg__RoadworkBeacon
    std::shared_ptr<roadwork_interfaces::msg::RoadworkBeacon_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoadworkBeacon_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->valid_for != other.valid_for) {
      return false;
    }
    if (this->entry_x != other.entry_x) {
      return false;
    }
    if (this->work_start != other.work_start) {
      return false;
    }
    if (this->work_end != other.work_end) {
      return false;
    }
    if (this->exit_x != other.exit_x) {
      return false;
    }
    if (this->speed_limit != other.speed_limit) {
      return false;
    }
    if (this->pass_side != other.pass_side) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoadworkBeacon_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoadworkBeacon_

// alias to use template instance with default allocator
using RoadworkBeacon =
  roadwork_interfaces::msg::RoadworkBeacon_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace roadwork_interfaces

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__STRUCT_HPP_
