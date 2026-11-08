// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from roadwork_solution_msgs:msg/ActStatus.idl
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
#include "roadwork_solution_msgs/msg/detail/act_status__struct.h"
#include "roadwork_solution_msgs/msg/detail/act_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool roadwork_solution_msgs__msg__act_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
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
    assert(strncmp("roadwork_solution_msgs.msg._act_status.ActStatus", full_classname_dest, 48) == 0);
  }
  roadwork_solution_msgs__msg__ActStatus * ros_message = _ros_message;
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
  {  // state
    PyObject * field = PyObject_GetAttrString(_pymsg, "state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reason
    PyObject * field = PyObject_GetAttrString(_pymsg, "reason");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->reason, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // plan_seq
    PyObject * field = PyObject_GetAttrString(_pymsg, "plan_seq");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->plan_seq = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // plan_age
    PyObject * field = PyObject_GetAttrString(_pymsg, "plan_age");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->plan_age = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // odom_age
    PyObject * field = PyObject_GetAttrString(_pymsg, "odom_age");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->odom_age = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->target_index = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cross_track_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "cross_track_error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cross_track_error = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heading_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading_error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heading_error = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_raw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_raw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // steering_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering_raw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steering_raw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_cmd
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_cmd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_cmd = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // steering_cmd
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering_cmd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steering_cmd = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // limit_flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "limit_flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->limit_flags = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * roadwork_solution_msgs__msg__act_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ActStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("roadwork_solution_msgs.msg._act_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ActStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  roadwork_solution_msgs__msg__ActStatus * ros_message = (roadwork_solution_msgs__msg__ActStatus *)raw_ros_message;
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
  {  // state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reason
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->reason.data,
      strlen(ros_message->reason.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "reason", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // plan_seq
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->plan_seq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "plan_seq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // plan_age
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->plan_age);
    {
      int rc = PyObject_SetAttrString(_pymessage, "plan_age", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // odom_age
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->odom_age);
    {
      int rc = PyObject_SetAttrString(_pymessage, "odom_age", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_index
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->target_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cross_track_error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cross_track_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cross_track_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading_error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heading_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_raw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steering_raw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steering_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_cmd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_cmd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_cmd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steering_cmd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steering_cmd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering_cmd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // limit_flags
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->limit_flags);
    {
      int rc = PyObject_SetAttrString(_pymessage, "limit_flags", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
