// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roadwork_interfaces:msg/VehicleCommand.idl
// generated code does not contain a copyright notice
#include "roadwork_interfaces/msg/detail/vehicle_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
roadwork_interfaces__msg__VehicleCommand__init(roadwork_interfaces__msg__VehicleCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    roadwork_interfaces__msg__VehicleCommand__fini(msg);
    return false;
  }
  // speed
  // steering_angle
  return true;
}

void
roadwork_interfaces__msg__VehicleCommand__fini(roadwork_interfaces__msg__VehicleCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // speed
  // steering_angle
}

bool
roadwork_interfaces__msg__VehicleCommand__are_equal(const roadwork_interfaces__msg__VehicleCommand * lhs, const roadwork_interfaces__msg__VehicleCommand * rhs)
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
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // steering_angle
  if (lhs->steering_angle != rhs->steering_angle) {
    return false;
  }
  return true;
}

bool
roadwork_interfaces__msg__VehicleCommand__copy(
  const roadwork_interfaces__msg__VehicleCommand * input,
  roadwork_interfaces__msg__VehicleCommand * output)
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
  // speed
  output->speed = input->speed;
  // steering_angle
  output->steering_angle = input->steering_angle;
  return true;
}

roadwork_interfaces__msg__VehicleCommand *
roadwork_interfaces__msg__VehicleCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__VehicleCommand * msg = (roadwork_interfaces__msg__VehicleCommand *)allocator.allocate(sizeof(roadwork_interfaces__msg__VehicleCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roadwork_interfaces__msg__VehicleCommand));
  bool success = roadwork_interfaces__msg__VehicleCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roadwork_interfaces__msg__VehicleCommand__destroy(roadwork_interfaces__msg__VehicleCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roadwork_interfaces__msg__VehicleCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roadwork_interfaces__msg__VehicleCommand__Sequence__init(roadwork_interfaces__msg__VehicleCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__VehicleCommand * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(roadwork_interfaces__msg__VehicleCommand)) {
      return false;
    }
    data = (roadwork_interfaces__msg__VehicleCommand *)allocator.zero_allocate(size, sizeof(roadwork_interfaces__msg__VehicleCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roadwork_interfaces__msg__VehicleCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roadwork_interfaces__msg__VehicleCommand__fini(&data[i - 1]);
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
roadwork_interfaces__msg__VehicleCommand__Sequence__fini(roadwork_interfaces__msg__VehicleCommand__Sequence * array)
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
      roadwork_interfaces__msg__VehicleCommand__fini(&array->data[i]);
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

roadwork_interfaces__msg__VehicleCommand__Sequence *
roadwork_interfaces__msg__VehicleCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__VehicleCommand__Sequence * array = (roadwork_interfaces__msg__VehicleCommand__Sequence *)allocator.allocate(sizeof(roadwork_interfaces__msg__VehicleCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roadwork_interfaces__msg__VehicleCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roadwork_interfaces__msg__VehicleCommand__Sequence__destroy(roadwork_interfaces__msg__VehicleCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roadwork_interfaces__msg__VehicleCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roadwork_interfaces__msg__VehicleCommand__Sequence__are_equal(const roadwork_interfaces__msg__VehicleCommand__Sequence * lhs, const roadwork_interfaces__msg__VehicleCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roadwork_interfaces__msg__VehicleCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roadwork_interfaces__msg__VehicleCommand__Sequence__copy(
  const roadwork_interfaces__msg__VehicleCommand__Sequence * input,
  roadwork_interfaces__msg__VehicleCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(roadwork_interfaces__msg__VehicleCommand)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(roadwork_interfaces__msg__VehicleCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roadwork_interfaces__msg__VehicleCommand * data =
      (roadwork_interfaces__msg__VehicleCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roadwork_interfaces__msg__VehicleCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roadwork_interfaces__msg__VehicleCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roadwork_interfaces__msg__VehicleCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
