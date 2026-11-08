// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from roadwork_solution_msgs:msg/PlanPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "roadwork_solution_msgs/msg/detail/plan_point__rosidl_typesupport_introspection_c.h"
#include "roadwork_solution_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "roadwork_solution_msgs/msg/detail/plan_point__functions.h"
#include "roadwork_solution_msgs/msg/detail/plan_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roadwork_solution_msgs__msg__PlanPoint__init(message_memory);
}

void roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_fini_function(void * message_memory)
{
  roadwork_solution_msgs__msg__PlanPoint__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__PlanPoint, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__PlanPoint, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__PlanPoint, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_message_members = {
  "roadwork_solution_msgs__msg",  // message namespace
  "PlanPoint",  // message name
  3,  // number of fields
  sizeof(roadwork_solution_msgs__msg__PlanPoint),
  false,  // has_any_key_member_
  roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_message_member_array,  // message members
  roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_message_type_support_handle = {
  0,
  &roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_message_members,
  get_message_typesupport_handle_function,
  &roadwork_solution_msgs__msg__PlanPoint__get_type_hash,
  &roadwork_solution_msgs__msg__PlanPoint__get_type_description,
  &roadwork_solution_msgs__msg__PlanPoint__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roadwork_solution_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roadwork_solution_msgs, msg, PlanPoint)() {
  if (!roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_message_type_support_handle.typesupport_identifier) {
    roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roadwork_solution_msgs__msg__PlanPoint__rosidl_typesupport_introspection_c__PlanPoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
