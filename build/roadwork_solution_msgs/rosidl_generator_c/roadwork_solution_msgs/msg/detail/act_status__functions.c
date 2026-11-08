// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roadwork_solution_msgs:msg/ActStatus.idl
// generated code does not contain a copyright notice
#include "roadwork_solution_msgs/msg/detail/act_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"

bool
roadwork_solution_msgs__msg__ActStatus__init(roadwork_solution_msgs__msg__ActStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    roadwork_solution_msgs__msg__ActStatus__fini(msg);
    return false;
  }
  // state
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    roadwork_solution_msgs__msg__ActStatus__fini(msg);
    return false;
  }
  // plan_seq
  // plan_age
  // odom_age
  // target_index
  // cross_track_error
  // heading_error
  // speed_raw
  // steering_raw
  // speed_cmd
  // steering_cmd
  // limit_flags
  return true;
}

void
roadwork_solution_msgs__msg__ActStatus__fini(roadwork_solution_msgs__msg__ActStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // state
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
  // plan_seq
  // plan_age
  // odom_age
  // target_index
  // cross_track_error
  // heading_error
  // speed_raw
  // steering_raw
  // speed_cmd
  // steering_cmd
  // limit_flags
}

bool
roadwork_solution_msgs__msg__ActStatus__are_equal(const roadwork_solution_msgs__msg__ActStatus * lhs, const roadwork_solution_msgs__msg__ActStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->reason), &(rhs->reason)))
  {
    return false;
  }
  // plan_seq
  if (lhs->plan_seq != rhs->plan_seq) {
    return false;
  }
  // plan_age
  if (lhs->plan_age != rhs->plan_age) {
    return false;
  }
  // odom_age
  if (lhs->odom_age != rhs->odom_age) {
    return false;
  }
  // target_index
  if (lhs->target_index != rhs->target_index) {
    return false;
  }
  // cross_track_error
  if (lhs->cross_track_error != rhs->cross_track_error) {
    return false;
  }
  // heading_error
  if (lhs->heading_error != rhs->heading_error) {
    return false;
  }
  // speed_raw
  if (lhs->speed_raw != rhs->speed_raw) {
    return false;
  }
  // steering_raw
  if (lhs->steering_raw != rhs->steering_raw) {
    return false;
  }
  // speed_cmd
  if (lhs->speed_cmd != rhs->speed_cmd) {
    return false;
  }
  // steering_cmd
  if (lhs->steering_cmd != rhs->steering_cmd) {
    return false;
  }
  // limit_flags
  if (lhs->limit_flags != rhs->limit_flags) {
    return false;
  }
  return true;
}

bool
roadwork_solution_msgs__msg__ActStatus__copy(
  const roadwork_solution_msgs__msg__ActStatus * input,
  roadwork_solution_msgs__msg__ActStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // state
  output->state = input->state;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  // plan_seq
  output->plan_seq = input->plan_seq;
  // plan_age
  output->plan_age = input->plan_age;
  // odom_age
  output->odom_age = input->odom_age;
  // target_index
  output->target_index = input->target_index;
  // cross_track_error
  output->cross_track_error = input->cross_track_error;
  // heading_error
  output->heading_error = input->heading_error;
  // speed_raw
  output->speed_raw = input->speed_raw;
  // steering_raw
  output->steering_raw = input->steering_raw;
  // speed_cmd
  output->speed_cmd = input->speed_cmd;
  // steering_cmd
  output->steering_cmd = input->steering_cmd;
  // limit_flags
  output->limit_flags = input->limit_flags;
  return true;
}

roadwork_solution_msgs__msg__ActStatus *
roadwork_solution_msgs__msg__ActStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__ActStatus * msg = (roadwork_solution_msgs__msg__ActStatus *)allocator.allocate(sizeof(roadwork_solution_msgs__msg__ActStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roadwork_solution_msgs__msg__ActStatus));
  bool success = roadwork_solution_msgs__msg__ActStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roadwork_solution_msgs__msg__ActStatus__destroy(roadwork_solution_msgs__msg__ActStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roadwork_solution_msgs__msg__ActStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roadwork_solution_msgs__msg__ActStatus__Sequence__init(roadwork_solution_msgs__msg__ActStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__ActStatus * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(roadwork_solution_msgs__msg__ActStatus)) {
      return false;
    }
    data = (roadwork_solution_msgs__msg__ActStatus *)allocator.zero_allocate(size, sizeof(roadwork_solution_msgs__msg__ActStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roadwork_solution_msgs__msg__ActStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roadwork_solution_msgs__msg__ActStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
roadwork_solution_msgs__msg__ActStatus__Sequence__fini(roadwork_solution_msgs__msg__ActStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      roadwork_solution_msgs__msg__ActStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

roadwork_solution_msgs__msg__ActStatus__Sequence *
roadwork_solution_msgs__msg__ActStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__ActStatus__Sequence * array = (roadwork_solution_msgs__msg__ActStatus__Sequence *)allocator.allocate(sizeof(roadwork_solution_msgs__msg__ActStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roadwork_solution_msgs__msg__ActStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roadwork_solution_msgs__msg__ActStatus__Sequence__destroy(roadwork_solution_msgs__msg__ActStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roadwork_solution_msgs__msg__ActStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roadwork_solution_msgs__msg__ActStatus__Sequence__are_equal(const roadwork_solution_msgs__msg__ActStatus__Sequence * lhs, const roadwork_solution_msgs__msg__ActStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roadwork_solution_msgs__msg__ActStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roadwork_solution_msgs__msg__ActStatus__Sequence__copy(
  const roadwork_solution_msgs__msg__ActStatus__Sequence * input,
  roadwork_solution_msgs__msg__ActStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(roadwork_solution_msgs__msg__ActStatus)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(roadwork_solution_msgs__msg__ActStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roadwork_solution_msgs__msg__ActStatus * data =
      (roadwork_solution_msgs__msg__ActStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roadwork_solution_msgs__msg__ActStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roadwork_solution_msgs__msg__ActStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roadwork_solution_msgs__msg__ActStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
