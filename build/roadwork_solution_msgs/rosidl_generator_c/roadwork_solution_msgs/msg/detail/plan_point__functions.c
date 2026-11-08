// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roadwork_solution_msgs:msg/PlanPoint.idl
// generated code does not contain a copyright notice
#include "roadwork_solution_msgs/msg/detail/plan_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
roadwork_solution_msgs__msg__PlanPoint__init(roadwork_solution_msgs__msg__PlanPoint * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // speed
  return true;
}

void
roadwork_solution_msgs__msg__PlanPoint__fini(roadwork_solution_msgs__msg__PlanPoint * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // speed
}

bool
roadwork_solution_msgs__msg__PlanPoint__are_equal(const roadwork_solution_msgs__msg__PlanPoint * lhs, const roadwork_solution_msgs__msg__PlanPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
roadwork_solution_msgs__msg__PlanPoint__copy(
  const roadwork_solution_msgs__msg__PlanPoint * input,
  roadwork_solution_msgs__msg__PlanPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // speed
  output->speed = input->speed;
  return true;
}

roadwork_solution_msgs__msg__PlanPoint *
roadwork_solution_msgs__msg__PlanPoint__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__PlanPoint * msg = (roadwork_solution_msgs__msg__PlanPoint *)allocator.allocate(sizeof(roadwork_solution_msgs__msg__PlanPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roadwork_solution_msgs__msg__PlanPoint));
  bool success = roadwork_solution_msgs__msg__PlanPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roadwork_solution_msgs__msg__PlanPoint__destroy(roadwork_solution_msgs__msg__PlanPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roadwork_solution_msgs__msg__PlanPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roadwork_solution_msgs__msg__PlanPoint__Sequence__init(roadwork_solution_msgs__msg__PlanPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__PlanPoint * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(roadwork_solution_msgs__msg__PlanPoint)) {
      return false;
    }
    data = (roadwork_solution_msgs__msg__PlanPoint *)allocator.zero_allocate(size, sizeof(roadwork_solution_msgs__msg__PlanPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roadwork_solution_msgs__msg__PlanPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roadwork_solution_msgs__msg__PlanPoint__fini(&data[i - 1]);
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
roadwork_solution_msgs__msg__PlanPoint__Sequence__fini(roadwork_solution_msgs__msg__PlanPoint__Sequence * array)
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
      roadwork_solution_msgs__msg__PlanPoint__fini(&array->data[i]);
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

roadwork_solution_msgs__msg__PlanPoint__Sequence *
roadwork_solution_msgs__msg__PlanPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_solution_msgs__msg__PlanPoint__Sequence * array = (roadwork_solution_msgs__msg__PlanPoint__Sequence *)allocator.allocate(sizeof(roadwork_solution_msgs__msg__PlanPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roadwork_solution_msgs__msg__PlanPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roadwork_solution_msgs__msg__PlanPoint__Sequence__destroy(roadwork_solution_msgs__msg__PlanPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roadwork_solution_msgs__msg__PlanPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roadwork_solution_msgs__msg__PlanPoint__Sequence__are_equal(const roadwork_solution_msgs__msg__PlanPoint__Sequence * lhs, const roadwork_solution_msgs__msg__PlanPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roadwork_solution_msgs__msg__PlanPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roadwork_solution_msgs__msg__PlanPoint__Sequence__copy(
  const roadwork_solution_msgs__msg__PlanPoint__Sequence * input,
  roadwork_solution_msgs__msg__PlanPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(roadwork_solution_msgs__msg__PlanPoint)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(roadwork_solution_msgs__msg__PlanPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roadwork_solution_msgs__msg__PlanPoint * data =
      (roadwork_solution_msgs__msg__PlanPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roadwork_solution_msgs__msg__PlanPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roadwork_solution_msgs__msg__PlanPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roadwork_solution_msgs__msg__PlanPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
