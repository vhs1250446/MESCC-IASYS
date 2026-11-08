// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from roadwork_interfaces:msg/RoadworkBeacon.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "roadwork_interfaces/msg/detail/roadwork_beacon__rosidl_typesupport_introspection_c.h"
#include "roadwork_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "roadwork_interfaces/msg/detail/roadwork_beacon__functions.h"
#include "roadwork_interfaces/msg/detail/roadwork_beacon__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roadwork_interfaces__msg__RoadworkBeacon__init(message_memory);
}

void roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_fini_function(void * message_memory)
{
  roadwork_interfaces__msg__RoadworkBeacon__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_interfaces__msg__RoadworkBeacon, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "valid_for",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_interfaces__msg__RoadworkBeacon, valid_for),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "entry_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_interfaces__msg__RoadworkBeacon, entry_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "work_start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_interfaces__msg__RoadworkBeacon, work_start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "work_end",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_interfaces__msg__RoadworkBeacon, work_end),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "exit_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_interfaces__msg__RoadworkBeacon, exit_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
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
    offsetof(roadwork_interfaces__msg__RoadworkBeacon, speed_limit),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pass_side",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_interfaces__msg__RoadworkBeacon, pass_side),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_members = {
  "roadwork_interfaces__msg",  // message namespace
  "RoadworkBeacon",  // message name
  8,  // number of fields
  sizeof(roadwork_interfaces__msg__RoadworkBeacon),
  false,  // has_any_key_member_
  roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_member_array,  // message members
  roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_init_function,  // function to initialize message memory (memory has to be allocated)
  roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_type_support_handle = {
  0,
  &roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_members,
  get_message_typesupport_handle_function,
  &roadwork_interfaces__msg__RoadworkBeacon__get_type_hash,
  &roadwork_interfaces__msg__RoadworkBeacon__get_type_description,
  &roadwork_interfaces__msg__RoadworkBeacon__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roadwork_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roadwork_interfaces, msg, RoadworkBeacon)() {
  roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_type_support_handle.typesupport_identifier) {
    roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roadwork_interfaces__msg__RoadworkBeacon__rosidl_typesupport_introspection_c__RoadworkBeacon_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
