// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roadwork_interfaces:msg/RoadworkBeacon.idl
// generated code does not contain a copyright notice
#include "roadwork_interfaces/msg/detail/roadwork_beacon__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
roadwork_interfaces__msg__RoadworkBeacon__init(roadwork_interfaces__msg__RoadworkBeacon * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    roadwork_interfaces__msg__RoadworkBeacon__fini(msg);
    return false;
  }
  // valid_for
  // entry_x
  // work_start
  // work_end
  // exit_x
  // speed_limit
  // pass_side
  return true;
}

void
roadwork_interfaces__msg__RoadworkBeacon__fini(roadwork_interfaces__msg__RoadworkBeacon * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // valid_for
  // entry_x
  // work_start
  // work_end
  // exit_x
  // speed_limit
  // pass_side
}

bool
roadwork_interfaces__msg__RoadworkBeacon__are_equal(const roadwork_interfaces__msg__RoadworkBeacon * lhs, const roadwork_interfaces__msg__RoadworkBeacon * rhs)
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
  // valid_for
  if (lhs->valid_for != rhs->valid_for) {
    return false;
  }
  // entry_x
  if (lhs->entry_x != rhs->entry_x) {
    return false;
  }
  // work_start
  if (lhs->work_start != rhs->work_start) {
    return false;
  }
  // work_end
  if (lhs->work_end != rhs->work_end) {
    return false;
  }
  // exit_x
  if (lhs->exit_x != rhs->exit_x) {
    return false;
  }
  // speed_limit
  if (lhs->speed_limit != rhs->speed_limit) {
    return false;
  }
  // pass_side
  if (lhs->pass_side != rhs->pass_side) {
    return false;
  }
  return true;
}

bool
roadwork_interfaces__msg__RoadworkBeacon__copy(
  const roadwork_interfaces__msg__RoadworkBeacon * input,
  roadwork_interfaces__msg__RoadworkBeacon * output)
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
  // valid_for
  output->valid_for = input->valid_for;
  // entry_x
  output->entry_x = input->entry_x;
  // work_start
  output->work_start = input->work_start;
  // work_end
  output->work_end = input->work_end;
  // exit_x
  output->exit_x = input->exit_x;
  // speed_limit
  output->speed_limit = input->speed_limit;
  // pass_side
  output->pass_side = input->pass_side;
  return true;
}

roadwork_interfaces__msg__RoadworkBeacon *
roadwork_interfaces__msg__RoadworkBeacon__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RoadworkBeacon * msg = (roadwork_interfaces__msg__RoadworkBeacon *)allocator.allocate(sizeof(roadwork_interfaces__msg__RoadworkBeacon), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roadwork_interfaces__msg__RoadworkBeacon));
  bool success = roadwork_interfaces__msg__RoadworkBeacon__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roadwork_interfaces__msg__RoadworkBeacon__destroy(roadwork_interfaces__msg__RoadworkBeacon * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roadwork_interfaces__msg__RoadworkBeacon__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roadwork_interfaces__msg__RoadworkBeacon__Sequence__init(roadwork_interfaces__msg__RoadworkBeacon__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RoadworkBeacon * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(roadwork_interfaces__msg__RoadworkBeacon)) {
      return false;
    }
    data = (roadwork_interfaces__msg__RoadworkBeacon *)allocator.zero_allocate(size, sizeof(roadwork_interfaces__msg__RoadworkBeacon), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roadwork_interfaces__msg__RoadworkBeacon__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roadwork_interfaces__msg__RoadworkBeacon__fini(&data[i - 1]);
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
roadwork_interfaces__msg__RoadworkBeacon__Sequence__fini(roadwork_interfaces__msg__RoadworkBeacon__Sequence * array)
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
      roadwork_interfaces__msg__RoadworkBeacon__fini(&array->data[i]);
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

roadwork_interfaces__msg__RoadworkBeacon__Sequence *
roadwork_interfaces__msg__RoadworkBeacon__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RoadworkBeacon__Sequence * array = (roadwork_interfaces__msg__RoadworkBeacon__Sequence *)allocator.allocate(sizeof(roadwork_interfaces__msg__RoadworkBeacon__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roadwork_interfaces__msg__RoadworkBeacon__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roadwork_interfaces__msg__RoadworkBeacon__Sequence__destroy(roadwork_interfaces__msg__RoadworkBeacon__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roadwork_interfaces__msg__RoadworkBeacon__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roadwork_interfaces__msg__RoadworkBeacon__Sequence__are_equal(const roadwork_interfaces__msg__RoadworkBeacon__Sequence * lhs, const roadwork_interfaces__msg__RoadworkBeacon__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roadwork_interfaces__msg__RoadworkBeacon__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roadwork_interfaces__msg__RoadworkBeacon__Sequence__copy(
  const roadwork_interfaces__msg__RoadworkBeacon__Sequence * input,
  roadwork_interfaces__msg__RoadworkBeacon__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(roadwork_interfaces__msg__RoadworkBeacon)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(roadwork_interfaces__msg__RoadworkBeacon);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roadwork_interfaces__msg__RoadworkBeacon * data =
      (roadwork_interfaces__msg__RoadworkBeacon *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roadwork_interfaces__msg__RoadworkBeacon__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roadwork_interfaces__msg__RoadworkBeacon__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roadwork_interfaces__msg__RoadworkBeacon__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
