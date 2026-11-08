// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from roadwork_solution_msgs:msg/Plan.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "roadwork_solution_msgs/msg/detail/plan__struct.h"
#include "roadwork_solution_msgs/msg/detail/plan__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

// Nested array functions includes
#include "roadwork_solution_msgs/msg/detail/plan_point__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);
bool roadwork_solution_msgs__msg__plan_point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * roadwork_solution_msgs__msg__plan_point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool roadwork_solution_msgs__msg__plan__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("roadwork_solution_msgs.msg._plan.Plan", full_classname_dest, 37) == 0);
  }
  roadwork_solution_msgs__msg__Plan * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // scene_stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "scene_stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->scene_stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // valid_until
    PyObject * field = PyObject_GetAttrString(_pymsg, "valid_until");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->valid_until)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // seq
    PyObject * field = PyObject_GetAttrString(_pymsg, "seq");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->seq = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // path
    PyObject * field = PyObject_GetAttrString(_pymsg, "path");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'path'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!roadwork_solution_msgs__msg__PlanPoint__Sequence__init(&(ros_message->path), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create roadwork_solution_msgs__msg__PlanPoint__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    roadwork_solution_msgs__msg__PlanPoint * dest = ros_message->path.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!roadwork_solution_msgs__msg__plan_point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // speed_limit
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_limit");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_limit = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // has_stop_line
    PyObject * field = PyObject_GetAttrString(_pymsg, "has_stop_line");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->has_stop_line = (Py_True == field);
    Py_DECREF(field);
  }
  {  // stop_line_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "stop_line_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->stop_line_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // decision_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "decision_state");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->decision_state, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * roadwork_solution_msgs__msg__plan__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Plan */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("roadwork_solution_msgs.msg._plan");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Plan");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  roadwork_solution_msgs__msg__Plan * ros_message = (roadwork_solution_msgs__msg__Plan *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // scene_stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->scene_stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "scene_stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // valid_until
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->valid_until);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "valid_until", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // seq
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->seq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "seq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // path
    PyObject * field = NULL;
    size_t size = ros_message->path.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    roadwork_solution_msgs__msg__PlanPoint * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->path.data[i]);
      PyObject * pyitem = roadwork_solution_msgs__msg__plan_point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_limit
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_limit);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_limit", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // has_stop_line
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->has_stop_line ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "has_stop_line", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stop_line_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->stop_line_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stop_line_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // decision_state
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->decision_state.data,
      strlen(ros_message->decision_state.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "decision_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
