// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roadwork_interfaces:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/vehicle_command.hpp"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_HPP_
#define ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_HPP_

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
# define DEPRECATED__roadwork_interfaces__msg__VehicleCommand __attribute__((deprecated))
#else
# define DEPRECATED__roadwork_interfaces__msg__VehicleCommand __declspec(deprecated)
#endif

namespace roadwork_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleCommand_
{
  using Type = VehicleCommand_<ContainerAllocator>;

  explicit VehicleCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0;
      this->steering_angle = 0.0;
    }
  }

  explicit VehicleCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0;
      this->steering_angle = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _speed_type =
    double;
  _speed_type speed;
  using _steering_angle_type =
    double;
  _steering_angle_type steering_angle;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__steering_angle(
    const double & _arg)
  {
    this->steering_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roadwork_interfaces__msg__VehicleCommand
    std::shared_ptr<roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roadwork_interfaces__msg__VehicleCommand
    std::shared_ptr<roadwork_interfaces::msg::VehicleCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->steering_angle != other.steering_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleCommand_

// alias to use template instance with default allocator
using VehicleCommand =
  roadwork_interfaces::msg::VehicleCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace roadwork_interfaces

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_HPP_
