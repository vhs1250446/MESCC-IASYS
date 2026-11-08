// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roadwork_interfaces:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/vehicle_command.h"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_
#define ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_

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

/// Struct defined in msg/VehicleCommand in the package roadwork_interfaces.
typedef struct roadwork_interfaces__msg__VehicleCommand
{
  std_msgs__msg__Header header;
  /// SI units. The simulator rejects nonfinite or stale commands (age > 0.30 s).
  double speed;
  double steering_angle;
} roadwork_interfaces__msg__VehicleCommand;

// Struct for a sequence of roadwork_interfaces__msg__VehicleCommand.
typedef struct roadwork_interfaces__msg__VehicleCommand__Sequence
{
  roadwork_interfaces__msg__VehicleCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roadwork_interfaces__msg__VehicleCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_
