# generated from rosidl_generator_py/resource/_idl.py.em
# with input from roadwork_solution_msgs:msg/Plan.idl
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


class Metaclass_Plan(type):
    """Metaclass of message 'Plan'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'MODE_STOP': 0,
        'MODE_TRACK': 1,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('roadwork_solution_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'roadwork_solution_msgs.msg.Plan')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__plan
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__plan
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__plan
            cls._TYPE_SUPPORT = module.type_support_msg__msg__plan
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__plan

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

            from roadwork_solution_msgs.msg import PlanPoint
            if PlanPoint.__class__._TYPE_SUPPORT is None:
                PlanPoint.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MODE_STOP': cls.__constants['MODE_STOP'],
            'MODE_TRACK': cls.__constants['MODE_TRACK'],
        }

    @property
    def MODE_STOP(self):
        """Message constant 'MODE_STOP'."""
        return Metaclass_Plan.__constants['MODE_STOP']

    @property
    def MODE_TRACK(self):
        """Message constant 'MODE_TRACK'."""
        return Metaclass_Plan.__constants['MODE_TRACK']


class Plan(metaclass=Metaclass_Plan):
    """
    Message class 'Plan'.

    Constants:
      MODE_STOP
      MODE_TRACK
    """

    __slots__ = [
        '_header',
        '_scene_stamp',
        '_valid_until',
        '_seq',
        '_mode',
        '_path',
        '_speed_limit',
        '_has_stop_line',
        '_stop_line_x',
        '_decision_state',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'scene_stamp': 'builtin_interfaces/Time',
        'valid_until': 'builtin_interfaces/Time',
        'seq': 'uint32',
        'mode': 'uint8',
        'path': 'sequence<roadwork_solution_msgs/PlanPoint>',
        'speed_limit': 'double',
        'has_stop_line': 'boolean',
        'stop_line_x': 'double',
        'decision_state': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['roadwork_solution_msgs', 'msg'], 'PlanPoint')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        from builtin_interfaces.msg import Time
        self.scene_stamp = kwargs.get('scene_stamp', Time())
        from builtin_interfaces.msg import Time
        self.valid_until = kwargs.get('valid_until', Time())
        self.seq = kwargs.get('seq', int())
        self.mode = kwargs.get('mode', int())
        self.path = kwargs.get('path', [])
        self.speed_limit = kwargs.get('speed_limit', float())
        self.has_stop_line = kwargs.get('has_stop_line', bool())
        self.stop_line_x = kwargs.get('stop_line_x', float())
        self.decision_state = kwargs.get('decision_state', str())

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
        if self.scene_stamp != other.scene_stamp:
            return False
        if self.valid_until != other.valid_until:
            return False
        if self.seq != other.seq:
            return False
        if self.mode != other.mode:
            return False
        if self.path != other.path:
            return False
        if self.speed_limit != other.speed_limit:
            return False
        if self.has_stop_line != other.has_stop_line:
            return False
        if self.stop_line_x != other.stop_line_x:
            return False
        if self.decision_state != other.decision_state:
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
    def scene_stamp(self):
        """Message field 'scene_stamp'."""
        return self._scene_stamp

    @scene_stamp.setter
    def scene_stamp(self, value):
        if self._check_fields:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'scene_stamp' field must be a sub message of type 'Time'"
        self._scene_stamp = value

    @builtins.property
    def valid_until(self):
        """Message field 'valid_until'."""
        return self._valid_until

    @valid_until.setter
    def valid_until(self, value):
        if self._check_fields:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'valid_until' field must be a sub message of type 'Time'"
        self._valid_until = value

    @builtins.property
    def seq(self):
        """Message field 'seq'."""
        return self._seq

    @seq.setter
    def seq(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'seq' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'seq' field must be an unsigned integer in [0, 4294967295]"
        self._seq = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mode' field must be an unsigned integer in [0, 255]"
        self._mode = value

    @builtins.property
    def path(self):
        """Message field 'path'."""
        return self._path

    @path.setter
    def path(self, value):
        if self._check_fields:
            from roadwork_solution_msgs.msg import PlanPoint
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, PlanPoint) for v in value) and
                 True), \
                "The 'path' field must be a set or sequence and each value of type 'PlanPoint'"
        self._path = value

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
    def has_stop_line(self):
        """Message field 'has_stop_line'."""
        return self._has_stop_line

    @has_stop_line.setter
    def has_stop_line(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'has_stop_line' field must be of type 'bool'"
        self._has_stop_line = value

    @builtins.property
    def stop_line_x(self):
        """Message field 'stop_line_x'."""
        return self._stop_line_x

    @stop_line_x.setter
    def stop_line_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'stop_line_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'stop_line_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._stop_line_x = value

    @builtins.property
    def decision_state(self):
        """Message field 'decision_state'."""
        return self._decision_state

    @decision_state.setter
    def decision_state(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'decision_state' field must be of type 'str'"
        self._decision_state = value
