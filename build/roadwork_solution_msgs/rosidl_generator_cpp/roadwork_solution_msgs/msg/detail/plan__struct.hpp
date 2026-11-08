// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/plan.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__STRUCT_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__STRUCT_HPP_

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
// Member 'scene_stamp'
// Member 'valid_until'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'path'
#include "roadwork_solution_msgs/msg/detail/plan_point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__roadwork_solution_msgs__msg__Plan __attribute__((deprecated))
#else
# define DEPRECATED__roadwork_solution_msgs__msg__Plan __declspec(deprecated)
#endif

namespace roadwork_solution_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Plan_
{
  using Type = Plan_<ContainerAllocator>;

  explicit Plan_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    scene_stamp(_init),
    valid_until(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seq = 0ul;
      this->mode = 0;
      this->speed_limit = 0.0;
      this->has_stop_line = false;
      this->stop_line_x = 0.0;
      this->decision_state = "";
    }
  }

  explicit Plan_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    scene_stamp(_alloc, _init),
    valid_until(_alloc, _init),
    decision_state(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seq = 0ul;
      this->mode = 0;
      this->speed_limit = 0.0;
      this->has_stop_line = false;
      this->stop_line_x = 0.0;
      this->decision_state = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _scene_stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _scene_stamp_type scene_stamp;
  using _valid_until_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _valid_until_type valid_until;
  using _seq_type =
    uint32_t;
  _seq_type seq;
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _path_type =
    std::vector<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>>>;
  _path_type path;
  using _speed_limit_type =
    double;
  _speed_limit_type speed_limit;
  using _has_stop_line_type =
    bool;
  _has_stop_line_type has_stop_line;
  using _stop_line_x_type =
    double;
  _stop_line_x_type stop_line_x;
  using _decision_state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _decision_state_type decision_state;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__scene_stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->scene_stamp = _arg;
    return *this;
  }
  Type & set__valid_until(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->valid_until = _arg;
    return *this;
  }
  Type & set__seq(
    const uint32_t & _arg)
  {
    this->seq = _arg;
    return *this;
  }
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__path(
    const std::vector<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<roadwork_solution_msgs::msg::PlanPoint_<ContainerAllocator>>> & _arg)
  {
    this->path = _arg;
    return *this;
  }
  Type & set__speed_limit(
    const double & _arg)
  {
    this->speed_limit = _arg;
    return *this;
  }
  Type & set__has_stop_line(
    const bool & _arg)
  {
    this->has_stop_line = _arg;
    return *this;
  }
  Type & set__stop_line_x(
    const double & _arg)
  {
    this->stop_line_x = _arg;
    return *this;
  }
  Type & set__decision_state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->decision_state = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MODE_STOP =
    0u;
  static constexpr uint8_t MODE_TRACK =
    1u;

  // pointer types
  using RawPtr =
    roadwork_solution_msgs::msg::Plan_<ContainerAllocator> *;
  using ConstRawPtr =
    const roadwork_solution_msgs::msg::Plan_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roadwork_solution_msgs::msg::Plan_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roadwork_solution_msgs::msg::Plan_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roadwork_solution_msgs::msg::Plan_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roadwork_solution_msgs::msg::Plan_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roadwork_solution_msgs::msg::Plan_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roadwork_solution_msgs::msg::Plan_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roadwork_solution_msgs::msg::Plan_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roadwork_solution_msgs::msg::Plan_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roadwork_solution_msgs__msg__Plan
    std::shared_ptr<roadwork_solution_msgs::msg::Plan_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roadwork_solution_msgs__msg__Plan
    std::shared_ptr<roadwork_solution_msgs::msg::Plan_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Plan_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->scene_stamp != other.scene_stamp) {
      return false;
    }
    if (this->valid_until != other.valid_until) {
      return false;
    }
    if (this->seq != other.seq) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->path != other.path) {
      return false;
    }
    if (this->speed_limit != other.speed_limit) {
      return false;
    }
    if (this->has_stop_line != other.has_stop_line) {
      return false;
    }
    if (this->stop_line_x != other.stop_line_x) {
      return false;
    }
    if (this->decision_state != other.decision_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const Plan_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Plan_

// alias to use template instance with default allocator
using Plan =
  roadwork_solution_msgs::msg::Plan_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Plan_<ContainerAllocator>::MODE_STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Plan_<ContainerAllocator>::MODE_TRACK;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace roadwork_solution_msgs

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__STRUCT_HPP_
