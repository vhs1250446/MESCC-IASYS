// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roadwork_interfaces:msg/RadarDetections.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roadwork_interfaces/msg/radar_detections.h"


#ifndef ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__STRUCT_H_
#define ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__STRUCT_H_

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
// Member 'detections'
#include "roadwork_interfaces/msg/detail/radar_detection__struct.h"

/// Struct defined in msg/RadarDetections in the package roadwork_interfaces.
typedef struct roadwork_interfaces__msg__RadarDetections
{
  std_msgs__msg__Header header;
  roadwork_interfaces__msg__RadarDetection__Sequence detections;
} roadwork_interfaces__msg__RadarDetections;

// Struct for a sequence of roadwork_interfaces__msg__RadarDetections.
typedef struct roadwork_interfaces__msg__RadarDetections__Sequence
{
  roadwork_interfaces__msg__RadarDetections * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roadwork_interfaces__msg__RadarDetections__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__STRUCT_H_
