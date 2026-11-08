# generated from rosidl_generator_py/resource/_idl.py.em
# with input from roadwork_interfaces:msg/RoadworkBeacon.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RoadworkBeacon(type):
    """Metaclass of message 'RoadworkBeacon'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('roadwork_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'roadwork_interfaces.msg.RoadworkBeacon')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__roadwork_beacon
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__roadwork_beacon
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__roadwork_beacon
            cls._TYPE_SUPPORT = module.type_support_msg__msg__roadwork_beacon
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__roadwork_beacon

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RoadworkBeacon(metaclass=Metaclass_RoadworkBeacon):
    """Message class 'RoadworkBeacon'."""

    __slots__ = [
        '_header',
        '_valid_for',
        '_entry_x',
        '_work_start',
        '_work_end',
        '_exit_x',
        '_speed_limit',
        '_pass_side',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'valid_for': 'double',
        'entry_x': 'double',
        'work_start': 'double',
        'work_end': 'double',
        'exit_x': 'double',
        'speed_limit': 'double',
        'pass_side': 'int8',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.valid_for = kwargs.get('valid_for', float())
        self.entry_x = kwargs.get('entry_x', float())
        self.work_start = kwargs.get('work_start', float())
        self.work_end = kwargs.get('work_end', float())
        self.exit_x = kwargs.get('exit_x', float())
        self.speed_limit = kwargs.get('speed_limit', float())
        self.pass_side = kwargs.get('pass_side', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.valid_for != other.valid_for:
            return False
        if self.entry_x != other.entry_x:
            return False
        if self.work_start != other.work_start:
            return False
        if self.work_end != other.work_end:
            return False
        if self.exit_x != other.exit_x:
            return False
        if self.speed_limit != other.speed_limit:
            return False
        if self.pass_side != other.pass_side:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def valid_for(self):
        """Message field 'valid_for'."""
        return self._valid_for

    @valid_for.setter
    def valid_for(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'valid_for' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'valid_for' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._valid_for = value

    @builtins.property
    def entry_x(self):
        """Message field 'entry_x'."""
        return self._entry_x

    @entry_x.setter
    def entry_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'entry_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'entry_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._entry_x = value

    @builtins.property
    def work_start(self):
        """Message field 'work_start'."""
        return self._work_start

    @work_start.setter
    def work_start(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'work_start' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'work_start' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._work_start = value

    @builtins.property
    def work_end(self):
        """Message field 'work_end'."""
        return self._work_end

    @work_end.setter
    def work_end(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'work_end' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'work_end' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._work_end = value

    @builtins.property
    def exit_x(self):
        """Message field 'exit_x'."""
        return self._exit_x

    @exit_x.setter
    def exit_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'exit_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'exit_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._exit_x = value

    @builtins.property
    def speed_limit(self):
        """Message field 'speed_limit'."""
        return self._speed_limit

    @speed_limit.setter
    def speed_limit(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'speed_limit' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_limit' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_limit = value

    @builtins.property
    def pass_side(self):
        """Message field 'pass_side'."""
        return self._pass_side

    @pass_side.setter
    def pass_side(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'pass_side' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'pass_side' field must be an integer in [-128, 127]"
        self._pass_side = value
