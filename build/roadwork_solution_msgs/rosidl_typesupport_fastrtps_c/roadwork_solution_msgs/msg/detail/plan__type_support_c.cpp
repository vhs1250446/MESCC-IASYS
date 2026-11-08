// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice
#include "roadwork_solution_msgs/msg/detail/plan__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "roadwork_solution_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roadwork_solution_msgs/msg/detail/plan__struct.h"
#include "roadwork_solution_msgs/msg/detail/plan__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "builtin_interfaces/msg/detail/time__functions.h"  // scene_stamp, valid_until
#include "roadwork_solution_msgs/msg/detail/plan_point__functions.h"  // path
#include "rosidl_runtime_c/string.h"  // decision_state
#include "rosidl_runtime_c/string_functions.h"  // decision_state
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
bool cdr_serialize_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
bool cdr_deserialize_builtin_interfaces__msg__Time(
  eprosima::fastcdr::Cdr & cdr,
  builtin_interfaces__msg__Time * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
bool cdr_serialize_key_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
size_t get_serialized_size_key_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
size_t max_serialized_size_key_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();

bool cdr_serialize_roadwork_solution_msgs__msg__PlanPoint(
  const roadwork_solution_msgs__msg__PlanPoint * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_roadwork_solution_msgs__msg__PlanPoint(
  eprosima::fastcdr::Cdr & cdr,
  roadwork_solution_msgs__msg__PlanPoint * ros_message);

size_t get_serialized_size_roadwork_solution_msgs__msg__PlanPoint(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_roadwork_solution_msgs__msg__PlanPoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_roadwork_solution_msgs__msg__PlanPoint(
  const roadwork_solution_msgs__msg__PlanPoint * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_roadwork_solution_msgs__msg__PlanPoint(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_roadwork_solution_msgs__msg__PlanPoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roadwork_solution_msgs, msg, PlanPoint)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_solution_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _Plan__ros_msg_type = roadwork_solution_msgs__msg__Plan;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_serialize_roadwork_solution_msgs__msg__Plan(
  const roadwork_solution_msgs__msg__Plan * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: scene_stamp
  {
    cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->scene_stamp, cdr);
  }

  // Field name: valid_until
  {
    cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->valid_until, cdr);
  }

  // Field name: seq
  {
    cdr << ros_message->seq;
  }

  // Field name: mode
  {
    cdr << ros_message->mode;
  }

  // Field name: path
  {
    size_t size = ros_message->path.size;
    auto array_ptr = ros_message->path.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_roadwork_solution_msgs__msg__PlanPoint(
        &array_ptr[i], cdr);
    }
  }

  // Field name: speed_limit
  {
    cdr << ros_message->speed_limit;
  }

  // Field name: has_stop_line
  {
    cdr << (ros_message->has_stop_line ? true : false);
  }

  // Field name: stop_line_x
  {
    cdr << ros_message->stop_line_x;
  }

  // Field name: decision_state
  {
    const rosidl_runtime_c__String * str = &ros_message->decision_state;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_deserialize_roadwork_solution_msgs__msg__Plan(
  eprosima::fastcdr::Cdr & cdr,
  roadwork_solution_msgs__msg__Plan * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: scene_stamp
  {
    cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->scene_stamp);
  }

  // Field name: valid_until
  {
    cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->valid_until);
  }

  // Field name: seq
  {
    cdr >> ros_message->seq;
  }

  // Field name: mode
  {
    cdr >> ros_message->mode;
  }

  // Field name: path
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->path.data) {
      roadwork_solution_msgs__msg__PlanPoint__Sequence__fini(&ros_message->path);
    }
    if (!roadwork_solution_msgs__msg__PlanPoint__Sequence__init(&ros_message->path, size)) {
      fprintf(stderr, "failed to create array for field 'path'");
      return false;
    }
    auto array_ptr = ros_message->path.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_roadwork_solution_msgs__msg__PlanPoint(cdr, &array_ptr[i]);
    }
  }

  // Field name: speed_limit
  {
    cdr >> ros_message->speed_limit;
  }

  // Field name: has_stop_line
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->has_stop_line = tmp ? true : false;
  }

  // Field name: stop_line_x
  {
    cdr >> ros_message->stop_line_x;
  }

  // Field name: decision_state
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->decision_state.data) {
      rosidl_runtime_c__String__init(&ros_message->decision_state);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->decision_state,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'decision_state'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t get_serialized_size_roadwork_solution_msgs__msg__Plan(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Plan__ros_msg_type * ros_message = static_cast<const _Plan__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: scene_stamp
  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->scene_stamp), current_alignment);

  // Field name: valid_until
  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->valid_until), current_alignment);

  // Field name: seq
  {
    size_t item_size = sizeof(ros_message->seq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mode
  {
    size_t item_size = sizeof(ros_message->mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: path
  {
    size_t array_size = ros_message->path.size;
    auto array_ptr = ros_message->path.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_roadwork_solution_msgs__msg__PlanPoint(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: speed_limit
  {
    size_t item_size = sizeof(ros_message->speed_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: has_stop_line
  {
    size_t item_size = sizeof(ros_message->has_stop_line);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: stop_line_x
  {
    size_t item_size = sizeof(ros_message->stop_line_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: decision_state
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->decision_state.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t max_serialized_size_roadwork_solution_msgs__msg__Plan(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: scene_stamp
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: valid_until
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: seq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: path
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_roadwork_solution_msgs__msg__PlanPoint(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: speed_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: has_stop_line
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: stop_line_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: decision_state
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roadwork_solution_msgs__msg__Plan;
    is_plain =
      (
      offsetof(DataType, decision_state) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_serialize_key_roadwork_solution_msgs__msg__Plan(
  const roadwork_solution_msgs__msg__Plan * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: scene_stamp
  {
    cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->scene_stamp, cdr);
  }

  // Field name: valid_until
  {
    cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->valid_until, cdr);
  }

  // Field name: seq
  {
    cdr << ros_message->seq;
  }

  // Field name: mode
  {
    cdr << ros_message->mode;
  }

  // Field name: path
  {
    size_t size = ros_message->path.size;
    auto array_ptr = ros_message->path.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_roadwork_solution_msgs__msg__PlanPoint(
        &array_ptr[i], cdr);
    }
  }

  // Field name: speed_limit
  {
    cdr << ros_message->speed_limit;
  }

  // Field name: has_stop_line
  {
    cdr << (ros_message->has_stop_line ? true : false);
  }

  // Field name: stop_line_x
  {
    cdr << ros_message->stop_line_x;
  }

  // Field name: decision_state
  {
    const rosidl_runtime_c__String * str = &ros_message->decision_state;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t get_serialized_size_key_roadwork_solution_msgs__msg__Plan(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Plan__ros_msg_type * ros_message = static_cast<const _Plan__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: scene_stamp
  current_alignment += get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->scene_stamp), current_alignment);

  // Field name: valid_until
  current_alignment += get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->valid_until), current_alignment);

  // Field name: seq
  {
    size_t item_size = sizeof(ros_message->seq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: mode
  {
    size_t item_size = sizeof(ros_message->mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: path
  {
    size_t array_size = ros_message->path.size;
    auto array_ptr = ros_message->path.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_roadwork_solution_msgs__msg__PlanPoint(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: speed_limit
  {
    size_t item_size = sizeof(ros_message->speed_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: has_stop_line
  {
    size_t item_size = sizeof(ros_message->has_stop_line);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: stop_line_x
  {
    size_t item_size = sizeof(ros_message->stop_line_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: decision_state
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->decision_state.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t max_serialized_size_key_roadwork_solution_msgs__msg__Plan(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: scene_stamp
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: valid_until
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: seq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: path
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_roadwork_solution_msgs__msg__PlanPoint(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: speed_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: has_stop_line
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: stop_line_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: decision_state
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roadwork_solution_msgs__msg__Plan;
    is_plain =
      (
      offsetof(DataType, decision_state) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Plan__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roadwork_solution_msgs__msg__Plan * ros_message = static_cast<const roadwork_solution_msgs__msg__Plan *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_roadwork_solution_msgs__msg__Plan(ros_message, cdr);
}

static bool _Plan__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roadwork_solution_msgs__msg__Plan * ros_message = static_cast<roadwork_solution_msgs__msg__Plan *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_roadwork_solution_msgs__msg__Plan(cdr, ros_message);
}

static uint32_t _Plan__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_roadwork_solution_msgs__msg__Plan(
      untyped_ros_message, 0));
}

static size_t _Plan__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_roadwork_solution_msgs__msg__Plan(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Plan = {
  "roadwork_solution_msgs::msg",
  "Plan",
  _Plan__cdr_serialize,
  _Plan__cdr_deserialize,
  _Plan__get_serialized_size,
  _Plan__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Plan__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Plan,
  get_message_typesupport_handle_function,
  &roadwork_solution_msgs__msg__Plan__get_type_hash,
  &roadwork_solution_msgs__msg__Plan__get_type_description,
  &roadwork_solution_msgs__msg__Plan__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roadwork_solution_msgs, msg, Plan)() {
  return &_Plan__type_support;
}

#if defined(__cplusplus)
}
#endif
