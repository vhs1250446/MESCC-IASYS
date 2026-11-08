// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from roadwork_interfaces:msg/RadarDetections.idl
// generated code does not contain a copyright notice

#include "roadwork_interfaces/msg/detail/radar_detections__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_roadwork_interfaces
const rosidl_type_hash_t *
roadwork_interfaces__msg__RadarDetections__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x31, 0x49, 0x7b, 0xb4, 0x2f, 0xa7, 0x78, 0xf0,
      0x17, 0x48, 0xfb, 0x3a, 0x8c, 0xaa, 0x60, 0x46,
      0x45, 0xf4, 0xb3, 0x07, 0xdb, 0x75, 0x0b, 0x18,
      0x6c, 0xca, 0xfc, 0xd1, 0x43, 0x76, 0x59, 0x7c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "roadwork_interfaces/msg/detail/radar_detection__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t roadwork_interfaces__msg__RadarDetection__EXPECTED_HASH = {1, {
    0xee, 0xd2, 0xdd, 0xab, 0x93, 0xa2, 0x38, 0xc7,
    0xbc, 0xe6, 0x17, 0x54, 0xf3, 0x92, 0xc6, 0x3f,
    0x2c, 0x15, 0x45, 0xc7, 0x47, 0x5f, 0x2f, 0x9a,
    0xd5, 0x69, 0x3b, 0x43, 0x9a, 0x29, 0x94, 0xb9,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char roadwork_interfaces__msg__RadarDetections__TYPE_NAME[] = "roadwork_interfaces/msg/RadarDetections";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char roadwork_interfaces__msg__RadarDetection__TYPE_NAME[] = "roadwork_interfaces/msg/RadarDetection";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char roadwork_interfaces__msg__RadarDetections__FIELD_NAME__header[] = "header";
static char roadwork_interfaces__msg__RadarDetections__FIELD_NAME__detections[] = "detections";

static rosidl_runtime_c__type_description__Field roadwork_interfaces__msg__RadarDetections__FIELDS[] = {
  {
    {roadwork_interfaces__msg__RadarDetections__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_interfaces__msg__RadarDetections__FIELD_NAME__detections, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {roadwork_interfaces__msg__RadarDetection__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription roadwork_interfaces__msg__RadarDetections__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {roadwork_interfaces__msg__RadarDetection__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
roadwork_interfaces__msg__RadarDetections__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {roadwork_interfaces__msg__RadarDetections__TYPE_NAME, 39, 39},
      {roadwork_interfaces__msg__RadarDetections__FIELDS, 2, 2},
    },
    {roadwork_interfaces__msg__RadarDetections__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&roadwork_interfaces__msg__RadarDetection__EXPECTED_HASH, roadwork_interfaces__msg__RadarDetection__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = roadwork_interfaces__msg__RadarDetection__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "roadwork_interfaces/RadarDetection[] detections";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
roadwork_interfaces__msg__RadarDetections__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {roadwork_interfaces__msg__RadarDetections__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 71, 71},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
roadwork_interfaces__msg__RadarDetections__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *roadwork_interfaces__msg__RadarDetections__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *roadwork_interfaces__msg__RadarDetection__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
