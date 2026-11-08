// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from roadwork_interfaces:msg/RoadworkBeacon.idl
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
#include "roadwork_interfaces/msg/detail/roadwork_beacon__struct.h"
#include "roadwork_interfaces/msg/detail/roadwork_beacon__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool roadwork_interfaces__msg__roadwork_beacon__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
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
    assert(strncmp("roadwork_interfaces.msg._roadwork_beacon.RoadworkBeacon", full_classname_dest, 55) == 0);
  }
  roadwork_interfaces__msg__RoadworkBeacon * ros_message = _ros_message;
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
  {  // valid_for
    PyObject * field = PyObject_GetAttrString(_pymsg, "valid_for");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->valid_for = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // entry_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "entry_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->entry_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // work_start
    PyObject * field = PyObject_GetAttrString(_pymsg, "work_start");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->work_start = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // work_end
    PyObject * field = PyObject_GetAttrString(_pymsg, "work_end");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->work_end = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // exit_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "exit_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->exit_x = PyFloat_AS_DOUBLE(field);
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
  {  // pass_side
    PyObject * field = PyObject_GetAttrString(_pymsg, "pass_side");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pass_side = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * roadwork_interfaces__msg__roadwork_beacon__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RoadworkBeacon */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("roadwork_interfaces.msg._roadwork_beacon");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RoadworkBeacon");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  roadwork_interfaces__msg__RoadworkBeacon * ros_message = (roadwork_interfaces__msg__RoadworkBeacon *)raw_ros_message;
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
  {  // valid_for
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->valid_for);
    {
      int rc = PyObject_SetAttrString(_pymessage, "valid_for", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // entry_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->entry_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "entry_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // work_start
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->work_start);
    {
      int rc = PyObject_SetAttrString(_pymessage, "work_start", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // work_end
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->work_end);
    {
      int rc = PyObject_SetAttrString(_pymessage, "work_end", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // exit_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->exit_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "exit_x", field);
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
  {  // pass_side
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pass_side);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pass_side", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
