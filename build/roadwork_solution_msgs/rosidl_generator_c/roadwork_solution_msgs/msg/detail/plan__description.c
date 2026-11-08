// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice

#include "roadwork_solution_msgs/msg/detail/plan__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_roadwork_solution_msgs
const rosidl_type_hash_t *
roadwork_solution_msgs__msg__Plan__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x88, 0x3d, 0x52, 0x1d, 0xa4, 0x01, 0xbc, 0x16,
      0xfc, 0x95, 0x36, 0x28, 0x1e, 0xb8, 0x35, 0x3a,
      0x3e, 0x66, 0xd3, 0x6c, 0x80, 0x1d, 0xe5, 0x2e,
      0x20, 0xa9, 0xd9, 0xe1, 0x88, 0x3a, 0xe0, 0x07,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "roadwork_solution_msgs/msg/detail/plan_point__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t roadwork_solution_msgs__msg__PlanPoint__EXPECTED_HASH = {1, {
    0x52, 0xb4, 0x64, 0x0a, 0x8a, 0x0c, 0x6a, 0xe7,
    0x0b, 0xa0, 0x15, 0x24, 0x78, 0x37, 0xd9, 0xf3,
    0x2a, 0x7c, 0xec, 0x55, 0x99, 0xee, 0xff, 0x19,
    0x65, 0x45, 0xcf, 0x90, 0x63, 0x08, 0x73, 0xbb,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char roadwork_solution_msgs__msg__Plan__TYPE_NAME[] = "roadwork_solution_msgs/msg/Plan";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char roadwork_solution_msgs__msg__PlanPoint__TYPE_NAME[] = "roadwork_solution_msgs/msg/PlanPoint";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__header[] = "header";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__scene_stamp[] = "scene_stamp";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__valid_until[] = "valid_until";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__seq[] = "seq";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__mode[] = "mode";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__path[] = "path";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__speed_limit[] = "speed_limit";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__has_stop_line[] = "has_stop_line";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__stop_line_x[] = "stop_line_x";
static char roadwork_solution_msgs__msg__Plan__FIELD_NAME__decision_state[] = "decision_state";

static rosidl_runtime_c__type_description__Field roadwork_solution_msgs__msg__Plan__FIELDS[] = {
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__scene_stamp, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__valid_until, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__seq, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__path, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {roadwork_solution_msgs__msg__PlanPoint__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__speed_limit, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__has_stop_line, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__stop_line_x, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__Plan__FIELD_NAME__decision_state, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription roadwork_solution_msgs__msg__Plan__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__PlanPoint__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
roadwork_solution_msgs__msg__Plan__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {roadwork_solution_msgs__msg__Plan__TYPE_NAME, 31, 31},
      {roadwork_solution_msgs__msg__Plan__FIELDS, 10, 10},
    },
    {roadwork_solution_msgs__msg__Plan__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&roadwork_solution_msgs__msg__PlanPoint__EXPECTED_HASH, roadwork_solution_msgs__msg__PlanPoint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = roadwork_solution_msgs__msg__PlanPoint__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header                # stamp: sim time of computation; frame_id: \"map\"\n"
  "builtin_interfaces/Time scene_stamp   # stamp of the Scene this plan was built from\n"
  "builtin_interfaces/Time valid_until   # Act must not execute this plan after this instant\n"
  "uint32 seq                            # increments by one on every publication\n"
  "\n"
  "uint8 MODE_STOP  = 0                  # brake to standstill now; ignore path\n"
  "uint8 MODE_TRACK = 1                  # track path under speed profile and constraints\n"
  "uint8 mode\n"
  "\n"
  "PlanPoint[] path                      # ordered in travel direction; non-empty if MODE_TRACK\n"
  "float64 speed_limit                   # m/s, from beacon or nominal 4.0\n"
  "\n"
  "bool has_stop_line\n"
  "float64 stop_line_x                   # m, map; vehicle front (x + 0.9) must stay below it\n"
  "\n"
  "string decision_state                 # Plan's state name, for logs and traceability only";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
roadwork_solution_msgs__msg__Plan__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {roadwork_solution_msgs__msg__Plan__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 885, 885},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
roadwork_solution_msgs__msg__Plan__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *roadwork_solution_msgs__msg__Plan__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *roadwork_solution_msgs__msg__PlanPoint__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
