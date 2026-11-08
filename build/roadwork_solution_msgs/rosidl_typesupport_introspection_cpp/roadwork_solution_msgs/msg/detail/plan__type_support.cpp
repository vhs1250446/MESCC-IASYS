// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "roadwork_solution_msgs/msg/detail/plan__functions.h"
#include "roadwork_solution_msgs/msg/detail/plan__struct.hpp"
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

void Plan_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) roadwork_solution_msgs::msg::Plan(_init);
}

void Plan_fini_function(void * message_memory)
{
  auto typed_message = static_cast<roadwork_solution_msgs::msg::Plan *>(message_memory);
  typed_message->~Plan();
}

size_t size_function__Plan__path(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<roadwork_solution_msgs::msg::PlanPoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Plan__path(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<roadwork_solution_msgs::msg::PlanPoint> *>(untyped_member);
  return &member[index];
}

void * get_function__Plan__path(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<roadwork_solution_msgs::msg::PlanPoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__Plan__path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const roadwork_solution_msgs::msg::PlanPoint *>(
    get_const_function__Plan__path(untyped_member, index));
  auto & value = *reinterpret_cast<roadwork_solution_msgs::msg::PlanPoint *>(untyped_value);
  value = item;
}

void assign_function__Plan__path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<roadwork_solution_msgs::msg::PlanPoint *>(
    get_function__Plan__path(untyped_member, index));
  const auto & value = *reinterpret_cast<const roadwork_solution_msgs::msg::PlanPoint *>(untyped_value);
  item = value;
}

void resize_function__Plan__path(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<roadwork_solution_msgs::msg::PlanPoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Plan_message_member_array[10] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "scene_stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, scene_stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "valid_until",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, valid_until),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "seq",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, seq),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<roadwork_solution_msgs::msg::PlanPoint>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, path),  // bytes offset in struct
    nullptr,  // default value
    size_function__Plan__path,  // size() function pointer
    get_const_function__Plan__path,  // get_const(index) function pointer
    get_function__Plan__path,  // get(index) function pointer
    fetch_function__Plan__path,  // fetch(index, &value) function pointer
    assign_function__Plan__path,  // assign(index, value) function pointer
    resize_function__Plan__path  // resize(index) function pointer
  },
  {
    "speed_limit",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, speed_limit),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "has_stop_line",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, has_stop_line),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stop_line_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, stop_line_x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "decision_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roadwork_solution_msgs::msg::Plan, decision_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Plan_message_members = {
  "roadwork_solution_msgs::msg",  // message namespace
  "Plan",  // message name
  10,  // number of fields
  sizeof(roadwork_solution_msgs::msg::Plan),
  false,  // has_any_key_member_
  Plan_message_member_array,  // message members
  Plan_init_function,  // function to initialize message memory (memory has to be allocated)
  Plan_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Plan_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Plan_message_members,
  get_message_typesupport_handle_function,
  &roadwork_solution_msgs__msg__Plan__get_type_hash,
  &roadwork_solution_msgs__msg__Plan__get_type_description,
  &roadwork_solution_msgs__msg__Plan__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace roadwork_solution_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<roadwork_solution_msgs::msg::Plan>()
{
  return &::roadwork_solution_msgs::msg::rosidl_typesupport_introspection_cpp::Plan_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, roadwork_solution_msgs, msg, Plan)() {
  return &::roadwork_solution_msgs::msg::rosidl_typesupport_introspection_cpp::Plan_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
