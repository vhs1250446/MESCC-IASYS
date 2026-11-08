// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/plan.h"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__STRUCT_H_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'MODE_STOP'.
/**
  * brake to standstill now; ignore path
 */
enum
{
  roadwork_solution_msgs__msg__Plan__MODE_STOP = 0
};

/// Constant 'MODE_TRACK'.
/**
  * track path under speed profile and constraints
 */
enum
{
  roadwork_solution_msgs__msg__Plan__MODE_TRACK = 1
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'scene_stamp'
// Member 'valid_until'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'path'
#include "roadwork_solution_msgs/msg/detail/plan_point__struct.h"
// Member 'decision_state'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Plan in the package roadwork_solution_msgs.
typedef struct roadwork_solution_msgs__msg__Plan
{
  /// stamp: sim time of computation; frame_id: "map"
  std_msgs__msg__Header header;
  /// stamp of the Scene this plan was built from
  builtin_interfaces__msg__Time scene_stamp;
  /// Act must not execute this plan after this instant
  builtin_interfaces__msg__Time valid_until;
  /// increments by one on every publication
  uint32_t seq;
  uint8_t mode;
  /// ordered in travel direction; non-empty if MODE_TRACK
  roadwork_solution_msgs__msg__PlanPoint__Sequence path;
  /// m/s, from beacon or nominal 4.0
  double speed_limit;
  bool has_stop_line;
  /// m, map; vehicle front (x + 0.9) must stay below it
  double stop_line_x;
  /// Plan's state name, for logs and traceability only
  rosidl_runtime_c__String decision_state;
} roadwork_solution_msgs__msg__Plan;

// Struct for a sequence of roadwork_solution_msgs__msg__Plan.
typedef struct roadwork_solution_msgs__msg__Plan__Sequence
{
  roadwork_solution_msgs__msg__Plan * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roadwork_solution_msgs__msg__Plan__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__STRUCT_H_
