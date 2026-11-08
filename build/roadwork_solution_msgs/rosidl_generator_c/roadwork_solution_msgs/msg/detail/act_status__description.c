// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from roadwork_solution_msgs:msg/ActStatus.idl
// generated code does not contain a copyright notice

#include "roadwork_solution_msgs/msg/detail/act_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_roadwork_solution_msgs
const rosidl_type_hash_t *
roadwork_solution_msgs__msg__ActStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3f, 0xa7, 0xef, 0xb1, 0x0c, 0xe1, 0xa1, 0x7d,
      0xb5, 0x1f, 0x9f, 0x03, 0x29, 0x29, 0x68, 0xe9,
      0x46, 0x1a, 0xe5, 0x35, 0xd2, 0x79, 0x62, 0x42,
      0xf2, 0x53, 0x08, 0x4c, 0x38, 0x38, 0x84, 0x8b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char roadwork_solution_msgs__msg__ActStatus__TYPE_NAME[] = "roadwork_solution_msgs/msg/ActStatus";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__header[] = "header";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__state[] = "state";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__reason[] = "reason";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__plan_seq[] = "plan_seq";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__plan_age[] = "plan_age";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__odom_age[] = "odom_age";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__target_index[] = "target_index";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__cross_track_error[] = "cross_track_error";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__heading_error[] = "heading_error";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__speed_raw[] = "speed_raw";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__steering_raw[] = "steering_raw";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__speed_cmd[] = "speed_cmd";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__steering_cmd[] = "steering_cmd";
static char roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__limit_flags[] = "limit_flags";

static rosidl_runtime_c__type_description__Field roadwork_solution_msgs__msg__ActStatus__FIELDS[] = {
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__reason, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__plan_seq, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__plan_age, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__odom_age, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__target_index, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__cross_track_error, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__heading_error, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__speed_raw, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__steering_raw, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__speed_cmd, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__steering_cmd, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__ActStatus__FIELD_NAME__limit_flags, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription roadwork_solution_msgs__msg__ActStatus__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
roadwork_solution_msgs__msg__ActStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {roadwork_solution_msgs__msg__ActStatus__TYPE_NAME, 36, 36},
      {roadwork_solution_msgs__msg__ActStatus__FIELDS, 14, 14},
    },
    {roadwork_solution_msgs__msg__ActStatus__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "uint8 STATE_INIT = 0\n"
  "uint8 STATE_TRACKING = 1\n"
  "uint8 STATE_SAFE_STOP = 2\n"
  "uint8 state\n"
  "string reason                 # why SAFE_STOP, e.g. PLAN_EXPIRED, ODOM_STALE\n"
  "uint32 plan_seq               # seq of the plan in use\n"
  "float64 plan_age              # s, now minus plan header stamp\n"
  "float64 odom_age              # s, now minus odometry stamp\n"
  "uint32 target_index           # progress index on the path\n"
  "float64 cross_track_error     # m, signed, left positive\n"
  "float64 heading_error         # rad\n"
  "float64 speed_raw             # m/s, before limits\n"
  "float64 steering_raw          # rad, before limits\n"
  "float64 speed_cmd             # m/s, as published\n"
  "float64 steering_cmd          # rad, as published\n"
  "uint8 limit_flags             # bitmask: speed cap, stop line, steering clamp, slew";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
roadwork_solution_msgs__msg__ActStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {roadwork_solution_msgs__msg__ActStatus__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 800, 800},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
roadwork_solution_msgs__msg__ActStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *roadwork_solution_msgs__msg__ActStatus__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
