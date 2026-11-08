// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice
#include "roadwork_solution_msgs/msg/detail/plan__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `scene_stamp`
// Member `valid_until`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `path`
#include "roadwork_solution_msgs/msg/detail/plan_point__functions.h"
// Member `decision_state`
#include "rosidl_runtime_c/string_functions.h"

bool
roadwork_solution_msgs__msg__Plan__init(roadwork_solution_msgs__msg__Plan * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    roadwork_solution_msgs__msg__Plan__fini(msg);
    return false;
  }
  // scene_stamp
  if (!builtin_interfaces__msg__Time__init(&msg->scene_stamp)) {
    roadwork_solution_msgs__msg__Plan__fini(msg);
    return false;
  }
  // valid_until
  if (!builtin_interfaces__msg__Time__init(&msg->valid_until)) {
    roadwork_solution_msgs__msg__Plan__fini(msg);
    return false;
  }
  // seq
  // mode
  // path
  if (!roadwork_solution_msgs__msg__PlanPoint__Sequence__init(&msg->path, 0)) {
    roadwork_solution_msgs__msg__Plan__fini(msg);
    return false;
  }
  // speed_limit
  // has_stop_line
  // stop_line_x
  // decision_state
  if (!rosidl_runtime_c__String__init(&msg->decision_state)) {
    roadwork_solution_msgs__msg__Plan__fini(msg);
    return false;
  }
  return true;
}

void
roadwork_solution_msgs__msg__Plan__fini(roadwork_solution_msgs__msg__Plan * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // scene_stamp
  builtin_interfaces__msg__Time__fini(&msg->scene_stamp);
  // valid_until
  builtin_interfaces__msg__Time__fini(&msg->valid_until);
  // seq
  // mode
  // path
  roadwork_solution_msgs__msg__PlanPoint__Sequence__fini(&msg->path);
  // speed_limit
  // has_stop_line
  // stop_line_x
  // decision_state
  rosidl_runtime_c__String__fini(&msg->decision_state);
}

bool
roadwork_solution_msgs__msg__Plan__are_equal(const roadwork_solution_msgs__msg__Plan * lhs, const roadwork_solution_msgs__msg__Plan * rhs)
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
  // scene_stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->scene_stamp), &(rhs->scene_stamp)))
  {
    return false;
  }
  // valid_until
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->valid_until), &(rhs->valid_until)))
  {
    return false;
  }
  // seq
  if (lhs->seq != rhs->seq) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // path
  if (!roadwork_solution_msgs__msg__PlanPoint__Sequence__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  // speed_limit
  if (lhs->speed_limit != rhs->speed_limit) {
    return false;
  }
  // has_stop_line
  if (lhs->has_stop_line != rhs->has_stop_line) {
    return false;
  }
  // stop_line_x
  if (lhs->stop_line_x != rhs->stop_line_x) {
    return false;
  }
  // decision_state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->decision_state), &(rhs->decision_state)))
  {
    return false;
  }
  return true;
}

bool
roadwork_solution_msgs__msg__Plan__copy(
  const roadwork_solution_msgs__msg__Plan * input,
  roadwork_solution_msgs__msg__Plan * output)
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
  // scene_stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->scene_stamp), &(output->scene_stamp)))
  {
    return false;
  }
  // valid_until
  if (!builtin_interfaces__msg__Time__copy(
      &(input->valid_until), &(output->valid_until)))
  {
    return false;
  }
  // seq
  output->seq = input->seq;
  // mode
  output->mode = input->mode;
  // path
  if (!roadwork_solution_msgs__msg__PlanPoint__Sequence__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  // speed_limit
  output->speed_limit = input->speed_limit;
  // has_stop_line
  output->has_stop_line = input->has_stop_line;
  // stop_line_x
  output->stop_line_x = input->stop_line_x;
  // decision_state
  if (!rosidl_runtime_c__String__copy(
      &(input->decision_state), &(output->decision_state)))
  {
    return false;
  }
  return true;
}

roadwork_solution_msgs__msg__Plan *
roadwork_solution_msgs__msg__Plan__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__Plan * msg = (roadwork_solution_msgs__msg__Plan *)allocator.allocate(sizeof(roadwork_solution_msgs__msg__Plan), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roadwork_solution_msgs__msg__Plan));
  bool success = roadwork_solution_msgs__msg__Plan__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roadwork_solution_msgs__msg__Plan__destroy(roadwork_solution_msgs__msg__Plan * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roadwork_solution_msgs__msg__Plan__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roadwork_solution_msgs__msg__Plan__Sequence__init(roadwork_solution_msgs__msg__Plan__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__Plan * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(roadwork_solution_msgs__msg__Plan)) {
      return false;
    }
    data = (roadwork_solution_msgs__msg__Plan *)allocator.zero_allocate(size, sizeof(roadwork_solution_msgs__msg__Plan), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roadwork_solution_msgs__msg__Plan__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roadwork_solution_msgs__msg__Plan__fini(&data[i - 1]);
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
roadwork_solution_msgs__msg__Plan__Sequence__fini(roadwork_solution_msgs__msg__Plan__Sequence * array)
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
      roadwork_solution_msgs__msg__Plan__fini(&array->data[i]);
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

roadwork_solution_msgs__msg__Plan__Sequence *
roadwork_solution_msgs__msg__Plan__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__Plan__Sequence * array = (roadwork_solution_msgs__msg__Plan__Sequence *)allocator.allocate(sizeof(roadwork_solution_msgs__msg__Plan__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roadwork_solution_msgs__msg__Plan__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roadwork_solution_msgs__msg__Plan__Sequence__destroy(roadwork_solution_msgs__msg__Plan__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roadwork_solution_msgs__msg__Plan__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roadwork_solution_msgs__msg__Plan__Sequence__are_equal(const roadwork_solution_msgs__msg__Plan__Sequence * lhs, const roadwork_solution_msgs__msg__Plan__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roadwork_solution_msgs__msg__Plan__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roadwork_solution_msgs__msg__Plan__Sequence__copy(
  const roadwork_solution_msgs__msg__Plan__Sequence * input,
  roadwork_solution_msgs__msg__Plan__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(roadwork_solution_msgs__msg__Plan)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(roadwork_solution_msgs__msg__Plan);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roadwork_solution_msgs__msg__Plan * data =
      (roadwork_solution_msgs__msg__Plan *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roadwork_solution_msgs__msg__Plan__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roadwork_solution_msgs__msg__Plan__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roadwork_solution_msgs__msg__Plan__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
