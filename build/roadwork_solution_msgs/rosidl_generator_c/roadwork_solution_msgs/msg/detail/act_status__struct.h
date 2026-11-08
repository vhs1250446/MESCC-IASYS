// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roadwork_solution_msgs:msg/ActStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/act_status.h"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__STRUCT_H_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'STATE_INIT'.
enum
{
  roadwork_solution_msgs__msg__ActStatus__STATE_INIT = 0
};

/// Constant 'STATE_TRACKING'.
enum
{
  roadwork_solution_msgs__msg__ActStatus__STATE_TRACKING = 1
};

/// Constant 'STATE_SAFE_STOP'.
enum
{
  roadwork_solution_msgs__msg__ActStatus__STATE_SAFE_STOP = 2
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ActStatus in the package roadwork_solution_msgs.
typedef struct roadwork_solution_msgs__msg__ActStatus
{
  std_msgs__msg__Header header;
  uint8_t state;
  /// why SAFE_STOP, e.g. PLAN_EXPIRED, ODOM_STALE
  rosidl_runtime_c__String reason;
  /// seq of the plan in use
  uint32_t plan_seq;
  /// s, now minus plan header stamp
  double plan_age;
  /// s, now minus odometry stamp
  double odom_age;
  /// progress index on the path
  uint32_t target_index;
  /// m, signed, left positive
  double cross_track_error;
  /// rad
  double heading_error;
  /// m/s, before limits
  double speed_raw;
  /// rad, before limits
  double steering_raw;
  /// m/s, as published
  double speed_cmd;
  /// rad, as published
  double steering_cmd;
  /// bitmask: speed cap, stop line, steering clamp, slew
  uint8_t limit_flags;
} roadwork_solution_msgs__msg__ActStatus;

// Struct for a sequence of roadwork_solution_msgs__msg__ActStatus.
typedef struct roadwork_solution_msgs__msg__ActStatus__Sequence
{
  roadwork_solution_msgs__msg__ActStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roadwork_solution_msgs__msg__ActStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__ACT_STATUS__STRUCT_H_
