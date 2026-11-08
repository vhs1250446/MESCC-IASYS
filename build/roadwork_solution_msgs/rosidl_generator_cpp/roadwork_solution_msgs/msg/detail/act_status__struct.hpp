// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roadwork_solution_msgs:msg/ActStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/act_status.hpp"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__STRUCT_HPP_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__STRUCT_HPP_

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
# define DEPRECATED__roadwork_solution_msgs__msg__ActStatus __attribute__((deprecated))
#else
# define DEPRECATED__roadwork_solution_msgs__msg__ActStatus __declspec(deprecated)
#endif

namespace roadwork_solution_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActStatus_
{
  using Type = ActStatus_<ContainerAllocator>;

  explicit ActStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->reason = "";
      this->plan_seq = 0ul;
      this->plan_age = 0.0;
      this->odom_age = 0.0;
      this->target_index = 0ul;
      this->cross_track_error = 0.0;
      this->heading_error = 0.0;
      this->speed_raw = 0.0;
      this->steering_raw = 0.0;
      this->speed_cmd = 0.0;
      this->steering_cmd = 0.0;
      this->limit_flags = 0;
    }
  }

  explicit ActStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->reason = "";
      this->plan_seq = 0ul;
      this->plan_age = 0.0;
      this->odom_age = 0.0;
      this->target_index = 0ul;
      this->cross_track_error = 0.0;
      this->heading_error = 0.0;
      this->speed_raw = 0.0;
      this->steering_raw = 0.0;
      this->speed_cmd = 0.0;
      this->steering_cmd = 0.0;
      this->limit_flags = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _state_type =
    uint8_t;
  _state_type state;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;
  using _plan_seq_type =
    uint32_t;
  _plan_seq_type plan_seq;
  using _plan_age_type =
    double;
  _plan_age_type plan_age;
  using _odom_age_type =
    double;
  _odom_age_type odom_age;
  using _target_index_type =
    uint32_t;
  _target_index_type target_index;
  using _cross_track_error_type =
    double;
  _cross_track_error_type cross_track_error;
  using _heading_error_type =
    double;
  _heading_error_type heading_error;
  using _speed_raw_type =
    double;
  _speed_raw_type speed_raw;
  using _steering_raw_type =
    double;
  _steering_raw_type steering_raw;
  using _speed_cmd_type =
    double;
  _speed_cmd_type speed_cmd;
  using _steering_cmd_type =
    double;
  _steering_cmd_type steering_cmd;
  using _limit_flags_type =
    uint8_t;
  _limit_flags_type limit_flags;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }
  Type & set__plan_seq(
    const uint32_t & _arg)
  {
    this->plan_seq = _arg;
    return *this;
  }
  Type & set__plan_age(
    const double & _arg)
  {
    this->plan_age = _arg;
    return *this;
  }
  Type & set__odom_age(
    const double & _arg)
  {
    this->odom_age = _arg;
    return *this;
  }
  Type & set__target_index(
    const uint32_t & _arg)
  {
    this->target_index = _arg;
    return *this;
  }
  Type & set__cross_track_error(
    const double & _arg)
  {
    this->cross_track_error = _arg;
    return *this;
  }
  Type & set__heading_error(
    const double & _arg)
  {
    this->heading_error = _arg;
    return *this;
  }
  Type & set__speed_raw(
    const double & _arg)
  {
    this->speed_raw = _arg;
    return *this;
  }
  Type & set__steering_raw(
    const double & _arg)
  {
    this->steering_raw = _arg;
    return *this;
  }
  Type & set__speed_cmd(
    const double & _arg)
  {
    this->speed_cmd = _arg;
    return *this;
  }
  Type & set__steering_cmd(
    const double & _arg)
  {
    this->steering_cmd = _arg;
    return *this;
  }
  Type & set__limit_flags(
    const uint8_t & _arg)
  {
    this->limit_flags = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t STATE_INIT =
    0u;
  static constexpr uint8_t STATE_TRACKING =
    1u;
  static constexpr uint8_t STATE_SAFE_STOP =
    2u;

  // pointer types
  using RawPtr =
    roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roadwork_solution_msgs__msg__ActStatus
    std::shared_ptr<roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roadwork_solution_msgs__msg__ActStatus
    std::shared_ptr<roadwork_solution_msgs::msg::ActStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    if (this->plan_seq != other.plan_seq) {
      return false;
    }
    if (this->plan_age != other.plan_age) {
      return false;
    }
    if (this->odom_age != other.odom_age) {
      return false;
    }
    if (this->target_index != other.target_index) {
      return false;
    }
    if (this->cross_track_error != other.cross_track_error) {
      return false;
    }
    if (this->heading_error != other.heading_error) {
      return false;
    }
    if (this->speed_raw != other.speed_raw) {
      return false;
    }
    if (this->steering_raw != other.steering_raw) {
      return false;
    }
    if (this->speed_cmd != other.speed_cmd) {
      return false;
    }
    if (this->steering_cmd != other.steering_cmd) {
      return false;
    }
    if (this->limit_flags != other.limit_flags) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActStatus_

// alias to use template instance with default allocator
using ActStatus =
  roadwork_solution_msgs::msg::ActStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ActStatus_<ContainerAllocator>::STATE_INIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ActStatus_<ContainerAllocator>::STATE_TRACKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ActStatus_<ContainerAllocator>::STATE_SAFE_STOP;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace roadwork_solution_msgs

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__STRUCT_HPP_
