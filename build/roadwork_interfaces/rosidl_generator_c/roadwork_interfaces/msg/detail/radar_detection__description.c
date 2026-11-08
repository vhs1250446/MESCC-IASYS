// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from roadwork_interfaces:msg/RadarDetection.idl
// generated code does not contain a copyright notice

#include "roadwork_interfaces/msg/detail/radar_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_roadwork_interfaces
const rosidl_type_hash_t *
roadwork_interfaces__msg__RadarDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xee, 0xd2, 0xdd, 0xab, 0x93, 0xa2, 0x38, 0xc7,
      0xbc, 0xe6, 0x17, 0x54, 0xf3, 0x92, 0xc6, 0x3f,
      0x2c, 0x15, 0x45, 0xc7, 0x47, 0x5f, 0x2f, 0x9a,
      0xd5, 0x69, 0x3b, 0x43, 0x9a, 0x29, 0x94, 0xb9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char roadwork_interfaces__msg__RadarDetection__TYPE_NAME[] = "roadwork_interfaces/msg/RadarDetection";

// Define type names, field names, and default values
static char roadwork_interfaces__msg__RadarDetection__FIELD_NAME__range[] = "range";
static char roadwork_interfaces__msg__RadarDetection__FIELD_NAME__azimuth[] = "azimuth";
static char roadwork_interfaces__msg__RadarDetection__FIELD_NAME__radial_velocity[] = "radial_velocity";

static rosidl_runtime_c__type_description__Field roadwork_interfaces__msg__RadarDetection__FIELDS[] = {
  {
    {roadwork_interfaces__msg__RadarDetection__FIELD_NAME__range, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_interfaces__msg__RadarDetection__FIELD_NAME__azimuth, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_interfaces__msg__RadarDetection__FIELD_NAME__radial_velocity, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
roadwork_interfaces__msg__RadarDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {roadwork_interfaces__msg__RadarDetection__TYPE_NAME, 38, 38},
      {roadwork_interfaces__msg__RadarDetection__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 range\n"
  "float64 azimuth\n"
  "# Negative = closing. Includes the ego vehicle's motion.\n"
  "float64 radial_velocity";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
roadwork_interfaces__msg__RadarDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {roadwork_interfaces__msg__RadarDetection__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 111, 111},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
roadwork_interfaces__msg__RadarDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *roadwork_interfaces__msg__RadarDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
