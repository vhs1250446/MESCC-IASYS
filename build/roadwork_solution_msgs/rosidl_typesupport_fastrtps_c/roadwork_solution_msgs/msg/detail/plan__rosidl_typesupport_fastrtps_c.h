// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice
#ifndef ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "roadwork_solution_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roadwork_solution_msgs/msg/detail/plan__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_serialize_roadwork_solution_msgs__msg__Plan(
  const roadwork_solution_msgs__msg__Plan * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_deserialize_roadwork_solution_msgs__msg__Plan(
  eprosima::fastcdr::Cdr &,
  roadwork_solution_msgs__msg__Plan * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t get_serialized_size_roadwork_solution_msgs__msg__Plan(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t max_serialized_size_roadwork_solution_msgs__msg__Plan(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_serialize_key_roadwork_solution_msgs__msg__Plan(
  const roadwork_solution_msgs__msg__Plan * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t get_serialized_size_key_roadwork_solution_msgs__msg__Plan(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t max_serialized_size_key_roadwork_solution_msgs__msg__Plan(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roadwork_solution_msgs, msg, Plan)();

#ifdef __cplusplus
}
#endif

#endif  // ROADWORK_SOLUTION_MSGS__MSG__DETAIL__PLAN__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
