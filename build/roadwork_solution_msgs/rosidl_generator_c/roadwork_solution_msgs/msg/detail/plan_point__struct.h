// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roadwork_solution_msgs:msg/PlanPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_solution_msgs/msg/plan_point.h"


#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__STRUCT_H_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/PlanPoint in the package roadwork_solution_msgs.
typedef struct roadwork_solution_msgs__msg__PlanPoint
{
  /// m, map frame, rear-axle reference
  double x;
  /// m, map frame
  double y;
  /// m/s, target speed when the rear axle is at this point, >= 0
  double speed;
} roadwork_solution_msgs__msg__PlanPoint;

// Struct for a sequence of roadwork_solution_msgs__msg__PlanPoint.
typedef struct roadwork_solution_msgs__msg__PlanPoint__Sequence
{
  roadwork_solution_msgs__msg__PlanPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roadwork_solution_msgs__msg__PlanPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN_POINT__STRUCT_H_
