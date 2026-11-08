// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from roadwork_solution_msgs:msg/ActStatus.idl
// generated code does not contain a copyright notice
#include "roadwork_solution_msgs/msg/detail/act_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "roadwork_solution_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roadwork_solution_msgs/msg/detail/act_status__struct.h"
#include "roadwork_solution_msgs/msg/detail/act_status__functions.h"
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

#include "rosidl_runtime_c/string.h"  // reason
#include "rosidl_runtime_c/string_functions.h"  // reason
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

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


using _ActStatus__ros_msg_type = roadwork_solution_msgs__msg__ActStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_serialize_roadwork_solution_msgs__msg__ActStatus(
  const roadwork_solution_msgs__msg__ActStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: state
  {
    cdr << ros_message->state;
  }

  // Field name: reason
  {
    const rosidl_runtime_c__String * str = &ros_message->reason;
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

  // Field name: plan_seq
  {
    cdr << ros_message->plan_seq;
  }

  // Field name: plan_age
  {
    cdr << ros_message->plan_age;
  }

  // Field name: odom_age
  {
    cdr << ros_message->odom_age;
  }

  // Field name: target_index
  {
    cdr << ros_message->target_index;
  }

  // Field name: cross_track_error
  {
    cdr << ros_message->cross_track_error;
  }

  // Field name: heading_error
  {
    cdr << ros_message->heading_error;
  }

  // Field name: speed_raw
  {
    cdr << ros_message->speed_raw;
  }

  // Field name: steering_raw
  {
    cdr << ros_message->steering_raw;
  }

  // Field name: speed_cmd
  {
    cdr << ros_message->speed_cmd;
  }

  // Field name: steering_cmd
  {
    cdr << ros_message->steering_cmd;
  }

  // Field name: limit_flags
  {
    cdr << ros_message->limit_flags;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_deserialize_roadwork_solution_msgs__msg__ActStatus(
  eprosima::fastcdr::Cdr & cdr,
  roadwork_solution_msgs__msg__ActStatus * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: state
  {
    cdr >> ros_message->state;
  }

  // Field name: reason
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->reason.data) {
      rosidl_runtime_c__String__init(&ros_message->reason);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->reason,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'reason'\n");
      return false;
    }
  }

  // Field name: plan_seq
  {
    cdr >> ros_message->plan_seq;
  }

  // Field name: plan_age
  {
    cdr >> ros_message->plan_age;
  }

  // Field name: odom_age
  {
    cdr >> ros_message->odom_age;
  }

  // Field name: target_index
  {
    cdr >> ros_message->target_index;
  }

  // Field name: cross_track_error
  {
    cdr >> ros_message->cross_track_error;
  }

  // Field name: heading_error
  {
    cdr >> ros_message->heading_error;
  }

  // Field name: speed_raw
  {
    cdr >> ros_message->speed_raw;
  }

  // Field name: steering_raw
  {
    cdr >> ros_message->steering_raw;
  }

  // Field name: speed_cmd
  {
    cdr >> ros_message->speed_cmd;
  }

  // Field name: steering_cmd
  {
    cdr >> ros_message->steering_cmd;
  }

  // Field name: limit_flags
  {
    cdr >> ros_message->limit_flags;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t get_serialized_size_roadwork_solution_msgs__msg__ActStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ActStatus__ros_msg_type * ros_message = static_cast<const _ActStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: state
  {
    size_t item_size = sizeof(ros_message->state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->reason.size + 1);

  // Field name: plan_seq
  {
    size_t item_size = sizeof(ros_message->plan_seq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: plan_age
  {
    size_t item_size = sizeof(ros_message->plan_age);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: odom_age
  {
    size_t item_size = sizeof(ros_message->odom_age);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: target_index
  {
    size_t item_size = sizeof(ros_message->target_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cross_track_error
  {
    size_t item_size = sizeof(ros_message->cross_track_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: heading_error
  {
    size_t item_size = sizeof(ros_message->heading_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_raw
  {
    size_t item_size = sizeof(ros_message->speed_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steering_raw
  {
    size_t item_size = sizeof(ros_message->steering_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_cmd
  {
    size_t item_size = sizeof(ros_message->speed_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steering_cmd
  {
    size_t item_size = sizeof(ros_message->steering_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: limit_flags
  {
    size_t item_size = sizeof(ros_message->limit_flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t max_serialized_size_roadwork_solution_msgs__msg__ActStatus(
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

  // Field name: state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: reason
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

  // Field name: plan_seq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: plan_age
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: odom_age
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: target_index
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: cross_track_error
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: heading_error
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: speed_raw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steering_raw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: speed_cmd
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steering_cmd
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: limit_flags
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roadwork_solution_msgs__msg__ActStatus;
    is_plain =
      (
      offsetof(DataType, limit_flags) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
bool cdr_serialize_key_roadwork_solution_msgs__msg__ActStatus(
  const roadwork_solution_msgs__msg__ActStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: state
  {
    cdr << ros_message->state;
  }

  // Field name: reason
  {
    const rosidl_runtime_c__String * str = &ros_message->reason;
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

  // Field name: plan_seq
  {
    cdr << ros_message->plan_seq;
  }

  // Field name: plan_age
  {
    cdr << ros_message->plan_age;
  }

  // Field name: odom_age
  {
    cdr << ros_message->odom_age;
  }

  // Field name: target_index
  {
    cdr << ros_message->target_index;
  }

  // Field name: cross_track_error
  {
    cdr << ros_message->cross_track_error;
  }

  // Field name: heading_error
  {
    cdr << ros_message->heading_error;
  }

  // Field name: speed_raw
  {
    cdr << ros_message->speed_raw;
  }

  // Field name: steering_raw
  {
    cdr << ros_message->steering_raw;
  }

  // Field name: speed_cmd
  {
    cdr << ros_message->speed_cmd;
  }

  // Field name: steering_cmd
  {
    cdr << ros_message->steering_cmd;
  }

  // Field name: limit_flags
  {
    cdr << ros_message->limit_flags;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t get_serialized_size_key_roadwork_solution_msgs__msg__ActStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ActStatus__ros_msg_type * ros_message = static_cast<const _ActStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: state
  {
    size_t item_size = sizeof(ros_message->state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->reason.size + 1);

  // Field name: plan_seq
  {
    size_t item_size = sizeof(ros_message->plan_seq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: plan_age
  {
    size_t item_size = sizeof(ros_message->plan_age);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: odom_age
  {
    size_t item_size = sizeof(ros_message->odom_age);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: target_index
  {
    size_t item_size = sizeof(ros_message->target_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cross_track_error
  {
    size_t item_size = sizeof(ros_message->cross_track_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: heading_error
  {
    size_t item_size = sizeof(ros_message->heading_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_raw
  {
    size_t item_size = sizeof(ros_message->speed_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steering_raw
  {
    size_t item_size = sizeof(ros_message->steering_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_cmd
  {
    size_t item_size = sizeof(ros_message->speed_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: steering_cmd
  {
    size_t item_size = sizeof(ros_message->steering_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: limit_flags
  {
    size_t item_size = sizeof(ros_message->limit_flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_solution_msgs
size_t max_serialized_size_key_roadwork_solution_msgs__msg__ActStatus(
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

  // Field name: state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: reason
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

  // Field name: plan_seq
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: plan_age
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: odom_age
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: target_index
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: cross_track_error
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: heading_error
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: speed_raw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steering_raw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: speed_cmd
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: steering_cmd
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: limit_flags
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roadwork_solution_msgs__msg__ActStatus;
    is_plain =
      (
      offsetof(DataType, limit_flags) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ActStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roadwork_solution_msgs__msg__ActStatus * ros_message = static_cast<const roadwork_solution_msgs__msg__ActStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_roadwork_solution_msgs__msg__ActStatus(ros_message, cdr);
}

static bool _ActStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roadwork_solution_msgs__msg__ActStatus * ros_message = static_cast<roadwork_solution_msgs__msg__ActStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_roadwork_solution_msgs__msg__ActStatus(cdr, ros_message);
}

static uint32_t _ActStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_roadwork_solution_msgs__msg__ActStatus(
      untyped_ros_message, 0));
}

static size_t _ActStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_roadwork_solution_msgs__msg__ActStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ActStatus = {
  "roadwork_solution_msgs::msg",
  "ActStatus",
  _ActStatus__cdr_serialize,
  _ActStatus__cdr_deserialize,
  _ActStatus__get_serialized_size,
  _ActStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ActStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ActStatus,
  get_message_typesupport_handle_function,
  &roadwork_solution_msgs__msg__ActStatus__get_type_hash,
  &roadwork_solution_msgs__msg__ActStatus__get_type_description,
  &roadwork_solution_msgs__msg__ActStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roadwork_solution_msgs, msg, ActStatus)() {
  return &_ActStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
