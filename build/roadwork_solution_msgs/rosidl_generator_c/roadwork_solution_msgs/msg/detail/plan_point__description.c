// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from roadwork_solution_msgs:msg/PlanPoint.idl
// generated code does not contain a copyright notice

#include "roadwork_solution_msgs/msg/detail/plan_point__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_roadwork_solution_msgs
const rosidl_type_hash_t *
roadwork_solution_msgs__msg__PlanPoint__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x52, 0xb4, 0x64, 0x0a, 0x8a, 0x0c, 0x6a, 0xe7,
      0x0b, 0xa0, 0x15, 0x24, 0x78, 0x37, 0xd9, 0xf3,
      0x2a, 0x7c, 0xec, 0x55, 0x99, 0xee, 0xff, 0x19,
      0x65, 0x45, 0xcf, 0x90, 0x63, 0x08, 0x73, 0xbb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char roadwork_solution_msgs__msg__PlanPoint__TYPE_NAME[] = "roadwork_solution_msgs/msg/PlanPoint";

// Define type names, field names, and default values
static char roadwork_solution_msgs__msg__PlanPoint__FIELD_NAME__x[] = "x";
static char roadwork_solution_msgs__msg__PlanPoint__FIELD_NAME__y[] = "y";
static char roadwork_solution_msgs__msg__PlanPoint__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field roadwork_solution_msgs__msg__PlanPoint__FIELDS[] = {
  {
    {roadwork_solution_msgs__msg__PlanPoint__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__PlanPoint__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roadwork_solution_msgs__msg__PlanPoint__FIELD_NAME__speed, 5, 5},
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
roadwork_solution_msgs__msg__PlanPoint__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {roadwork_solution_msgs__msg__PlanPoint__TYPE_NAME, 36, 36},
      {roadwork_solution_msgs__msg__PlanPoint__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x        # m, map frame, rear-axle reference\n"
  "float64 y        # m, map frame\n"
  "float64 speed    # m/s, target speed when the rear axle is at this point, >= 0";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
roadwork_solution_msgs__msg__PlanPoint__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {roadwork_solution_msgs__msg__PlanPoint__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 164, 164},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
roadwork_solution_msgs__msg__PlanPoint__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *roadwork_solution_msgs__msg__PlanPoint__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
