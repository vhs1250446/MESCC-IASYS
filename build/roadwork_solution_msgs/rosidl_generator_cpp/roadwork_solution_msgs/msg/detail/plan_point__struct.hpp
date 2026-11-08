// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roadwork_solution_msgs:msg/PlanPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/plan_point.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__STRUCT_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__roadwork_solution_msgs__msg__PlanPoint __attribute__((deprecated))
#else
# define DEPRECATED__roadwork_solution_msgs__msg__PlanPoint __declspec(deprecated)
#endif

namespace roadwork_solution_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PlanPoint_
{
  using Type = PlanPoint_<ContainerAllocator>;

  explicit PlanPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->speed = 0.0;
    }
  }

  explicit PlanPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->speed = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _speed_type =
    double;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roadwork_solution_msgs__msg__PlanPoint
    std::shared_ptr<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roadwork_solution_msgs__msg__PlanPoint
    std::shared_ptr<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanPoint_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanPoint_

// alias to use template instance with default allocator
using PlanPoint =
  roadwork_solution_msgs::msg::PlanPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace roadwork_solution_msgs

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__STRUCT_HPP_
