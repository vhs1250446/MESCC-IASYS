// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roadwork_interfaces:msg/RadarDetections.idl
// generated code does not contain a copyright notice
#include "roadwork_interfaces/msg/detail/radar_detections__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `detections`
#include "roadwork_interfaces/msg/detail/radar_detection__functions.h"

bool
roadwork_interfaces__msg__RadarDetections__init(roadwork_interfaces__msg__RadarDetections * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    roadwork_interfaces__msg__RadarDetections__fini(msg);
    return false;
  }
  // detections
  if (!roadwork_interfaces__msg__RadarDetection__Sequence__init(&msg->detections, 0)) {
    roadwork_interfaces__msg__RadarDetections__fini(msg);
    return false;
  }
  return true;
}

void
roadwork_interfaces__msg__RadarDetections__fini(roadwork_interfaces__msg__RadarDetections * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // detections
  roadwork_interfaces__msg__RadarDetection__Sequence__fini(&msg->detections);
}

bool
roadwork_interfaces__msg__RadarDetections__are_equal(const roadwork_interfaces__msg__RadarDetections * lhs, const roadwork_interfaces__msg__RadarDetections * rhs)
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
  // detections
  if (!roadwork_interfaces__msg__RadarDetection__Sequence__are_equal(
      &(lhs->detections), &(rhs->detections)))
  {
    return false;
  }
  return true;
}

bool
roadwork_interfaces__msg__RadarDetections__copy(
  const roadwork_interfaces__msg__RadarDetections * input,
  roadwork_interfaces__msg__RadarDetections * output)
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
  // detections
  if (!roadwork_interfaces__msg__RadarDetection__Sequence__copy(
      &(input->detections), &(output->detections)))
  {
    return false;
  }
  return true;
}

roadwork_interfaces__msg__RadarDetections *
roadwork_interfaces__msg__RadarDetections__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RadarDetections * msg = (roadwork_interfaces__msg__RadarDetections *)allocator.allocate(sizeof(roadwork_interfaces__msg__RadarDetections), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roadwork_interfaces__msg__RadarDetections));
  bool success = roadwork_interfaces__msg__RadarDetections__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roadwork_interfaces__msg__RadarDetections__destroy(roadwork_interfaces__msg__RadarDetections * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roadwork_interfaces__msg__RadarDetections__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roadwork_interfaces__msg__RadarDetections__Sequence__init(roadwork_interfaces__msg__RadarDetections__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RadarDetections * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(roadwork_interfaces__msg__RadarDetections)) {
      return false;
    }
    data = (roadwork_interfaces__msg__RadarDetections *)allocator.zero_allocate(size, sizeof(roadwork_interfaces__msg__RadarDetections), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roadwork_interfaces__msg__RadarDetections__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roadwork_interfaces__msg__RadarDetections__fini(&data[i - 1]);
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
roadwork_interfaces__msg__RadarDetections__Sequence__fini(roadwork_interfaces__msg__RadarDetections__Sequence * array)
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
      roadwork_interfaces__msg__RadarDetections__fini(&array->data[i]);
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

roadwork_interfaces__msg__RadarDetections__Sequence *
roadwork_interfaces__msg__RadarDetections__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roadwork_interfaces__msg__RadarDetections__Sequence * array = (roadwork_interfaces__msg__RadarDetections__Sequence *)allocator.allocate(sizeof(roadwork_interfaces__msg__RadarDetections__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roadwork_interfaces__msg__RadarDetections__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roadwork_interfaces__msg__RadarDetections__Sequence__destroy(roadwork_interfaces__msg__RadarDetections__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roadwork_interfaces__msg__RadarDetections__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roadwork_interfaces__msg__RadarDetections__Sequence__are_equal(const roadwork_interfaces__msg__RadarDetections__Sequence * lhs, const roadwork_interfaces__msg__RadarDetections__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roadwork_interfaces__msg__RadarDetections__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roadwork_interfaces__msg__RadarDetections__Sequence__copy(
  const roadwork_interfaces__msg__RadarDetections__Sequence * input,
  roadwork_interfaces__msg__RadarDetections__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(roadwork_interfaces__msg__RadarDetections)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(roadwork_interfaces__msg__RadarDetections);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roadwork_interfaces__msg__RadarDetections * data =
      (roadwork_interfaces__msg__RadarDetections *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roadwork_interfaces__msg__RadarDetections__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roadwork_interfaces__msg__RadarDetections__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roadwork_interfaces__msg__RadarDetections__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
