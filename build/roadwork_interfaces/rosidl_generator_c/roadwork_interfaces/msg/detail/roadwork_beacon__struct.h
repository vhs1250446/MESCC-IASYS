// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roadwork_interfaces:msg/RoadworkBeacon.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/roadwork_beacon.h"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__STRUCT_H_
#define ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/RoadworkBeacon in the package roadwork_interfaces.
typedef struct roadwork_interfaces__msg__RoadworkBeacon
{
  std_msgs__msg__Header header;
  double valid_for;
  double entry_x;
  double work_start;
  double work_end;
  double exit_x;
  double speed_limit;
  /// +1 means pass to the left. Only +1 is supported in challenge v1.
  int8_t pass_side;
} roadwork_interfaces__msg__RoadworkBeacon;

// Struct for a sequence of roadwork_interfaces__msg__RoadworkBeacon.
typedef struct roadwork_interfaces__msg__RoadworkBeacon__Sequence
{
  roadwork_interfaces__msg__RoadworkBeacon * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roadwork_interfaces__msg__RoadworkBeacon__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__ROADWORK_BEACON__STRUCT_H_
