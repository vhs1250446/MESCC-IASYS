// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roadwork_interfaces:msg/RadarDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/radar_detection.h"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__STRUCT_H_
#define ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/RadarDetection in the package roadwork_interfaces.
typedef struct roadwork_interfaces__msg__RadarDetection
{
  double range;
  double azimuth;
  /// Negative = closing. Includes the ego vehicle's motion.
  double radial_velocity;
} roadwork_interfaces__msg__RadarDetection;

// Struct for a sequence of roadwork_interfaces__msg__RadarDetection.
typedef struct roadwork_interfaces__msg__RadarDetection__Sequence
{
  roadwork_interfaces__msg__RadarDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roadwork_interfaces__msg__RadarDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTION__STRUCT_H_
