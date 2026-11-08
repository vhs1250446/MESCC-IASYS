// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from roadwork_interfaces:msg/RoadworkBeacon.idl
// generated code does not contain a copyright notice
#include "roadwork_interfaces/msg/detail/roadwork_beacon__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "roadwork_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roadwork_interfaces/msg/detail/roadwork_beacon__struct.h"
#include "roadwork_interfaces/msg/detail/roadwork_beacon__functions.h"
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

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_interfaces
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_interfaces
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_interfaces
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_interfaces
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_interfaces
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roadwork_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _RoadworkBeacon__ros_msg_type = roadwork_interfaces__msg__RoadworkBeacon;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
bool cdr_serialize_roadwork_interfaces__msg__RoadworkBeacon(
  const roadwork_interfaces__msg__RoadworkBeacon * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: valid_for
  {
    cdr << ros_message->valid_for;
  }

  // Field name: entry_x
  {
    cdr << ros_message->entry_x;
  }

  // Field name: work_start
  {
    cdr << ros_message->work_start;
  }

  // Field name: work_end
  {
    cdr << ros_message->work_end;
  }

  // Field name: exit_x
  {
    cdr << ros_message->exit_x;
  }

  // Field name: speed_limit
  {
    cdr << ros_message->speed_limit;
  }

  // Field name: pass_side
  {
    cdr << ros_message->pass_side;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
bool cdr_deserialize_roadwork_interfaces__msg__RoadworkBeacon(
  eprosima::fastcdr::Cdr & cdr,
  roadwork_interfaces__msg__RoadworkBeacon * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: valid_for
  {
    cdr >> ros_message->valid_for;
  }

  // Field name: entry_x
  {
    cdr >> ros_message->entry_x;
  }

  // Field name: work_start
  {
    cdr >> ros_message->work_start;
  }

  // Field name: work_end
  {
    cdr >> ros_message->work_end;
  }

  // Field name: exit_x
  {
    cdr >> ros_message->exit_x;
  }

  // Field name: speed_limit
  {
    cdr >> ros_message->speed_limit;
  }

  // Field name: pass_side
  {
    cdr >> ros_message->pass_side;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
size_t get_serialized_size_roadwork_interfaces__msg__RoadworkBeacon(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RoadworkBeacon__ros_msg_type * ros_message = static_cast<const _RoadworkBeacon__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: valid_for
  {
    size_t item_size = sizeof(ros_message->valid_for);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: entry_x
  {
    size_t item_size = sizeof(ros_message->entry_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: work_start
  {
    size_t item_size = sizeof(ros_message->work_start);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: work_end
  {
    size_t item_size = sizeof(ros_message->work_end);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: exit_x
  {
    size_t item_size = sizeof(ros_message->exit_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_limit
  {
    size_t item_size = sizeof(ros_message->speed_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pass_side
  {
    size_t item_size = sizeof(ros_message->pass_side);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
size_t max_serialized_size_roadwork_interfaces__msg__RoadworkBeacon(
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

  // Field name: valid_for
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: entry_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: work_start
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: work_end
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: exit_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: speed_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: pass_side
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
    using DataType = roadwork_interfaces__msg__RoadworkBeacon;
    is_plain =
      (
      offsetof(DataType, pass_side) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
bool cdr_serialize_key_roadwork_interfaces__msg__RoadworkBeacon(
  const roadwork_interfaces__msg__RoadworkBeacon * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: valid_for
  {
    cdr << ros_message->valid_for;
  }

  // Field name: entry_x
  {
    cdr << ros_message->entry_x;
  }

  // Field name: work_start
  {
    cdr << ros_message->work_start;
  }

  // Field name: work_end
  {
    cdr << ros_message->work_end;
  }

  // Field name: exit_x
  {
    cdr << ros_message->exit_x;
  }

  // Field name: speed_limit
  {
    cdr << ros_message->speed_limit;
  }

  // Field name: pass_side
  {
    cdr << ros_message->pass_side;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
size_t get_serialized_size_key_roadwork_interfaces__msg__RoadworkBeacon(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RoadworkBeacon__ros_msg_type * ros_message = static_cast<const _RoadworkBeacon__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: valid_for
  {
    size_t item_size = sizeof(ros_message->valid_for);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: entry_x
  {
    size_t item_size = sizeof(ros_message->entry_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: work_start
  {
    size_t item_size = sizeof(ros_message->work_start);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: work_end
  {
    size_t item_size = sizeof(ros_message->work_end);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: exit_x
  {
    size_t item_size = sizeof(ros_message->exit_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed_limit
  {
    size_t item_size = sizeof(ros_message->speed_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pass_side
  {
    size_t item_size = sizeof(ros_message->pass_side);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roadwork_interfaces
size_t max_serialized_size_key_roadwork_interfaces__msg__RoadworkBeacon(
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

  // Field name: valid_for
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: entry_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: work_start
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: work_end
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: exit_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: speed_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: pass_side
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
    using DataType = roadwork_interfaces__msg__RoadworkBeacon;
    is_plain =
      (
      offsetof(DataType, pass_side) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _RoadworkBeacon__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roadwork_interfaces__msg__RoadworkBeacon * ros_message = static_cast<const roadwork_interfaces__msg__RoadworkBeacon *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_roadwork_interfaces__msg__RoadworkBeacon(ros_message, cdr);
}

static bool _RoadworkBeacon__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roadwork_interfaces__msg__RoadworkBeacon * ros_message = static_cast<roadwork_interfaces__msg__RoadworkBeacon *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_roadwork_interfaces__msg__RoadworkBeacon(cdr, ros_message);
}

static uint32_t _RoadworkBeacon__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_roadwork_interfaces__msg__RoadworkBeacon(
      untyped_ros_message, 0));
}

static size_t _RoadworkBeacon__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_roadwork_interfaces__msg__RoadworkBeacon(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RoadworkBeacon = {
  "roadwork_interfaces::msg",
  "RoadworkBeacon",
  _RoadworkBeacon__cdr_serialize,
  _RoadworkBeacon__cdr_deserialize,
  _RoadworkBeacon__get_serialized_size,
  _RoadworkBeacon__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _RoadworkBeacon__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RoadworkBeacon,
  get_message_typesupport_handle_function,
  &roadwork_interfaces__msg__RoadworkBeacon__get_type_hash,
  &roadwork_interfaces__msg__RoadworkBeacon__get_type_description,
  &roadwork_interfaces__msg__RoadworkBeacon__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roadwork_interfaces, msg, RoadworkBeacon)() {
  return &_RoadworkBeacon__type_support;
}

#if defined(__cplusplus)
}
#endif
