// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roadwork_interfaces:msg/RadarDetection.idl
// generated code does not contain a copyright notice
#include "roadwork_interfaces/msg/detail/radar_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
roadwork_interfaces__msg__RadarDetection__init(roadwork_interfaces__msg__RadarDetection * msg)
{
  if (!msg) {
    return false;
  }
  // range
  // azimuth
  // radial_velocity
  return true;
}

void
roadwork_interfaces__msg__RadarDetection__fini(roadwork_interfaces__msg__RadarDetection * msg)
{
  if (!msg) {
    return;
  }
  // range
  // azimuth
  // radial_velocity
}

bool
roadwork_interfaces__msg__RadarDetection__are_equal(const roadwork_interfaces__msg__RadarDetection * lhs, const roadwork_interfaces__msg__RadarDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // range
  if (lhs->range != rhs->range) {
    return false;
  }
  // azimuth
  if (lhs->azimuth != rhs->azimuth) {
    return false;
  }
  // radial_velocity
  if (lhs->radial_velocity != rhs->radial_velocity) {
    return false;
  }
  return true;
}

bool
roadwork_interfaces__msg__RadarDetection__copy(
  const roadwork_interfaces__msg__RadarDetection * input,
  roadwork_interfaces__msg__RadarDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // range
  output->range = input->range;
  // azimuth
  output->azimuth = input->azimuth;
  // radial_velocity
  output->radial_velocity = input->radial_velocity;
  return true;
}

roadwork_interfaces__msg__RadarDetection *
roadwork_interfaces__msg__RadarDetection__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RadarDetection * msg = (roadwork_interfaces__msg__RadarDetection *)allocator.allocate(sizeof(roadwork_interfaces__msg__RadarDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roadwork_interfaces__msg__RadarDetection));
  bool success = roadwork_interfaces__msg__RadarDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roadwork_interfaces__msg__RadarDetection__destroy(roadwork_interfaces__msg__RadarDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roadwork_interfaces__msg__RadarDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roadwork_interfaces__msg__RadarDetection__Sequence__init(roadwork_interfaces__msg__RadarDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RadarDetection * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(roadwork_interfaces__msg__RadarDetection)) {
      return false;
    }
    data = (roadwork_interfaces__msg__RadarDetection *)allocator.zero_allocate(size, sizeof(roadwork_interfaces__msg__RadarDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roadwork_interfaces__msg__RadarDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roadwork_interfaces__msg__RadarDetection__fini(&data[i - 1]);
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
roadwork_interfaces__msg__RadarDetection__Sequence__fini(roadwork_interfaces__msg__RadarDetection__Sequence * array)
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
      roadwork_interfaces__msg__RadarDetection__fini(&array->data[i]);
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

roadwork_interfaces__msg__RadarDetection__Sequence *
roadwork_interfaces__msg__RadarDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RadarDetection__Sequence * array = (roadwork_interfaces__msg__RadarDetection__Sequence *)allocator.allocate(sizeof(roadwork_interfaces__msg__RadarDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roadwork_interfaces__msg__RadarDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roadwork_interfaces__msg__RadarDetection__Sequence__destroy(roadwork_interfaces__msg__RadarDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roadwork_interfaces__msg__RadarDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roadwork_interfaces__msg__RadarDetection__Sequence__are_equal(const roadwork_interfaces__msg__RadarDetection__Sequence * lhs, const roadwork_interfaces__msg__RadarDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roadwork_interfaces__msg__RadarDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roadwork_interfaces__msg__RadarDetection__Sequence__copy(
  const roadwork_interfaces__msg__RadarDetection__Sequence * input,
  roadwork_interfaces__msg__RadarDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(roadwork_interfaces__msg__RadarDetection)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(roadwork_interfaces__msg__RadarDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roadwork_interfaces__msg__RadarDetection * data =
      (roadwork_interfaces__msg__RadarDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roadwork_interfaces__msg__RadarDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roadwork_interfaces__msg__RadarDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roadwork_interfaces__msg__RadarDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
