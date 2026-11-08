// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from roadwork_interfaces:msg/RadarDetections.idl
// generated code does not contain a copyright notice
#ifndef ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "roadwork_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roadwork_interfaces/msg/detail/radar_detections__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
bool cdr_serialize_roadwork_interfaces__msg__RadarDetections(
  const roadwork_interfaces__msg__RadarDetections * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
bool cdr_deserialize_roadwork_interfaces__msg__RadarDetections(
  eprosima::fastcdr::Cdr &,
  roadwork_interfaces__msg__RadarDetections * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
size_t get_serialized_size_roadwork_interfaces__msg__RadarDetections(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
size_t max_serialized_size_roadwork_interfaces__msg__RadarDetections(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
bool cdr_serialize_key_roadwork_interfaces__msg__RadarDetections(
  const roadwork_interfaces__msg__RadarDetections * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
size_t get_serialized_size_key_roadwork_interfaces__msg__RadarDetections(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
size_t max_serialized_size_key_roadwork_interfaces__msg__RadarDetections(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roadwork_interfaces, msg, RadarDetections)();

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_INTERFACES__MSG__DETAIL__RADAR_DETECTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
