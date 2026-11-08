// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "roadwork_solution_msgs/msg/detail/plan__rosidl_typesupport_introspection_c.h"
#include "roadwork_solution_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "roadwork_solution_msgs/msg/detail/plan__functions.h"
#include "roadwork_solution_msgs/msg/detail/plan__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `scene_stamp`
// Member `valid_until`
#include "builtin_interfaces/msg/time.h"
// Member `scene_stamp`
// Member `valid_until`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `path`
#include "roadwork_solution_msgs/msg/plan_point.h"
// Member `path`
#include "roadwork_solution_msgs/msg/detail/plan_point__rosidl_typesupport_introspection_c.h"
// Member `decision_state`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roadwork_solution_msgs__msg__Plan__init(message_memory);
}

void roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_fini_function(void * message_memory)
{
  roadwork_solution_msgs__msg__Plan__fini(message_memory);
}

size_t roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__size_function__Plan__path(
  const void * untyped_member)
{
  const roadwork_solution_msgs__msg__PlanPoint__Sequence * member =
    (const roadwork_solution_msgs__msg__PlanPoint__Sequence *)(untyped_member);
  return member->size;
}

const void * roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__get_const_function__Plan__path(
  const void * untyped_member, size_t index)
{
  const roadwork_solution_msgs__msg__PlanPoint__Sequence * member =
    (const roadwork_solution_msgs__msg__PlanPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__get_function__Plan__path(
  void * untyped_member, size_t index)
{
  roadwork_solution_msgs__msg__PlanPoint__Sequence * member =
    (roadwork_solution_msgs__msg__PlanPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__fetch_function__Plan__path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const roadwork_solution_msgs__msg__PlanPoint * item =
    ((const roadwork_solution_msgs__msg__PlanPoint *)
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__get_const_function__Plan__path(untyped_member, index));
  roadwork_solution_msgs__msg__PlanPoint * value =
    (roadwork_solution_msgs__msg__PlanPoint *)(untyped_value);
  *value = *item;
}

void roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__assign_function__Plan__path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  roadwork_solution_msgs__msg__PlanPoint * item =
    ((roadwork_solution_msgs__msg__PlanPoint *)
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__get_function__Plan__path(untyped_member, index));
  const roadwork_solution_msgs__msg__PlanPoint * value =
    (const roadwork_solution_msgs__msg__PlanPoint *)(untyped_value);
  *item = *value;
}

bool roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__resize_function__Plan__path(
  void * untyped_member, size_t size)
{
  roadwork_solution_msgs__msg__PlanPoint__Sequence * member =
    (roadwork_solution_msgs__msg__PlanPoint__Sequence *)(untyped_member);
  roadwork_solution_msgs__msg__PlanPoint__Sequence__fini(member);
  return roadwork_solution_msgs__msg__PlanPoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_member_array[10] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scene_stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, scene_stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "valid_until",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, valid_until),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "seq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, seq),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, path),  // bytes offset in struct
    NULL,  // default value
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__size_function__Plan__path,  // size() function pointer
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__get_const_function__Plan__path,  // get_const(index) function pointer
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__get_function__Plan__path,  // get(index) function pointer
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__fetch_function__Plan__path,  // fetch(index, &value) function pointer
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__assign_function__Plan__path,  // assign(index, value) function pointer
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__resize_function__Plan__path  // resize(index) function pointer
  },
  {
    "speed_limit",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, speed_limit),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "has_stop_line",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, has_stop_line),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stop_line_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, stop_line_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "decision_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs__msg__Plan, decision_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_members = {
  "roadwork_solution_msgs__msg",  // message namespace
  "Plan",  // message name
  10,  // number of fields
  sizeof(roadwork_solution_msgs__msg__Plan),
  false,  // has_any_key_member_
  roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_member_array,  // message members
  roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_init_function,  // function to initialize message memory (memory has to be allocated)
  roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_type_support_handle = {
  0,
  &roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_members,
  get_message_typesupport_handle_function,
  &roadwork_solution_msgs__msg__Plan__get_type_hash,
  &roadwork_solution_msgs__msg__Plan__get_type_description,
  &roadwork_solution_msgs__msg__Plan__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roadwork_solution_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roadwork_solution_msgs, msg, Plan)() {
  roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roadwork_solution_msgs, msg, PlanPoint)();
  if (!roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_type_support_handle.typesupport_identifier) {
    roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roadwork_solution_msgs__msg__Plan__rosidl_typesupport_introspection_c__Plan_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
