// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from roadwork_solution_msgs:msg/PlanPoint.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "roadwork_solution_msgs/msg/detail/plan_point__functions.h"
#include "roadwork_solution_msgs/msg/detail/plan_point__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace roadwork_solution_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PlanPoint_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) roadwork_solution_msgs::msg::PlanPoint(_init);
}

void PlanPoint_fini_function(void * message_memory)
{
  auto typed_message = static_cast<roadwork_solution_msgs::msg::PlanPoint *>(message_memory);
  typed_message->~PlanPoint();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PlanPoint_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::PlanPoint, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::PlanPoint, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::PlanPoint, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PlanPoint_message_members = {
  "roadwork_solution_msgs::msg",  // message namespace
  "PlanPoint",  // message name
  3,  // number of fields
  sizeof(roadwork_solution_msgs::msg::PlanPoint),
  false,  // has_any_key_member_
  PlanPoint_message_member_array,  // message members
  PlanPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  PlanPoint_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PlanPoint_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PlanPoint_message_members,
  get_message_typesupport_handle_function,
  &roadwork_solution_msgs__msg__PlanPoint__get_type_hash,
  &roadwork_solution_msgs__msg__PlanPoint__get_type_description,
  &roadwork_solution_msgs__msg__PlanPoint__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace roadwork_solution_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<roadwork_solution_msgs::msg::PlanPoint>()
{
  return &::roadwork_solution_msgs::msg::rosidl_typesupport_introspection_cpp::PlanPoint_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, roadwork_solution_msgs, msg, PlanPoint)() {
  return &::roadwork_solution_msgs::msg::rosidl_typesupport_introspection_cpp::PlanPoint_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
