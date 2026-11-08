# generated from rosidl_generator_py/resource/_idl.py.em
# with input from roadwork_solution_msgs:msg/ActStatus.idl
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


class Metaclass_ActStatus(type):
    """Metaclass of message 'ActStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'STATE_INIT': 0,
        'STATE_TRACKING': 1,
        'STATE_SAFE_STOP': 2,
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
                'roadwork_solution_msgs.msg.ActStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__act_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__act_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__act_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__act_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__act_status

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'STATE_INIT': cls.__constants['STATE_INIT'],
            'STATE_TRACKING': cls.__constants['STATE_TRACKING'],
            'STATE_SAFE_STOP': cls.__constants['STATE_SAFE_STOP'],
        }

    @property
    def STATE_INIT(self):
        """Message constant 'STATE_INIT'."""
        return Metaclass_ActStatus.__constants['STATE_INIT']

    @property
    def STATE_TRACKING(self):
        """Message constant 'STATE_TRACKING'."""
        return Metaclass_ActStatus.__constants['STATE_TRACKING']

    @property
    def STATE_SAFE_STOP(self):
        """Message constant 'STATE_SAFE_STOP'."""
        return Metaclass_ActStatus.__constants['STATE_SAFE_STOP']


class ActStatus(metaclass=Metaclass_ActStatus):
    """
    Message class 'ActStatus'.

    Constants:
      STATE_INIT
      STATE_TRACKING
      STATE_SAFE_STOP
    """

    __slots__ = [
        '_header',
        '_state',
        '_reason',
        '_plan_seq',
        '_plan_age',
        '_odom_age',
        '_target_index',
        '_cross_track_error',
        '_heading_error',
        '_speed_raw',
        '_steering_raw',
        '_speed_cmd',
        '_steering_cmd',
        '_limit_flags',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'state': 'uint8',
        'reason': 'string',
        'plan_seq': 'uint32',
        'plan_age': 'double',
        'odom_age': 'double',
        'target_index': 'uint32',
        'cross_track_error': 'double',
        'heading_error': 'double',
        'speed_raw': 'double',
        'steering_raw': 'double',
        'speed_cmd': 'double',
        'steering_cmd': 'double',
        'limit_flags': 'uint8',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.state = kwargs.get('state', int())
        self.reason = kwargs.get('reason', str())
        self.plan_seq = kwargs.get('plan_seq', int())
        self.plan_age = kwargs.get('plan_age', float())
        self.odom_age = kwargs.get('odom_age', float())
        self.target_index = kwargs.get('target_index', int())
        self.cross_track_error = kwargs.get('cross_track_error', float())
        self.heading_error = kwargs.get('heading_error', float())
        self.speed_raw = kwargs.get('speed_raw', float())
        self.steering_raw = kwargs.get('steering_raw', float())
        self.speed_cmd = kwargs.get('speed_cmd', float())
        self.steering_cmd = kwargs.get('steering_cmd', float())
        self.limit_flags = kwargs.get('limit_flags', int())

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
        if self.state != other.state:
            return False
        if self.reason != other.reason:
            return False
        if self.plan_seq != other.plan_seq:
            return False
        if self.plan_age != other.plan_age:
            return False
        if self.odom_age != other.odom_age:
            return False
        if self.target_index != other.target_index:
            return False
        if self.cross_track_error != other.cross_track_error:
            return False
        if self.heading_error != other.heading_error:
            return False
        if self.speed_raw != other.speed_raw:
            return False
        if self.steering_raw != other.steering_raw:
            return False
        if self.speed_cmd != other.speed_cmd:
            return False
        if self.steering_cmd != other.steering_cmd:
            return False
        if self.limit_flags != other.limit_flags:
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
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state' field must be an unsigned integer in [0, 255]"
        self._state = value

    @builtins.property
    def reason(self):
        """Message field 'reason'."""
        return self._reason

    @reason.setter
    def reason(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'reason' field must be of type 'str'"
        self._reason = value

    @builtins.property
    def plan_seq(self):
        """Message field 'plan_seq'."""
        return self._plan_seq

    @plan_seq.setter
    def plan_seq(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'plan_seq' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'plan_seq' field must be an unsigned integer in [0, 4294967295]"
        self._plan_seq = value

    @builtins.property
    def plan_age(self):
        """Message field 'plan_age'."""
        return self._plan_age

    @plan_age.setter
    def plan_age(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'plan_age' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'plan_age' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._plan_age = value

    @builtins.property
    def odom_age(self):
        """Message field 'odom_age'."""
        return self._odom_age

    @odom_age.setter
    def odom_age(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'odom_age' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'odom_age' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._odom_age = value

    @builtins.property
    def target_index(self):
        """Message field 'target_index'."""
        return self._target_index

    @target_index.setter
    def target_index(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'target_index' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'target_index' field must be an unsigned integer in [0, 4294967295]"
        self._target_index = value

    @builtins.property
    def cross_track_error(self):
        """Message field 'cross_track_error'."""
        return self._cross_track_error

    @cross_track_error.setter
    def cross_track_error(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'cross_track_error' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'cross_track_error' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._cross_track_error = value

    @builtins.property
    def heading_error(self):
        """Message field 'heading_error'."""
        return self._heading_error

    @heading_error.setter
    def heading_error(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'heading_error' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'heading_error' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._heading_error = value

    @builtins.property
    def speed_raw(self):
        """Message field 'speed_raw'."""
        return self._speed_raw

    @speed_raw.setter
    def speed_raw(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'speed_raw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_raw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_raw = value

    @builtins.property
    def steering_raw(self):
        """Message field 'steering_raw'."""
        return self._steering_raw

    @steering_raw.setter
    def steering_raw(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'steering_raw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steering_raw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steering_raw = value

    @builtins.property
    def speed_cmd(self):
        """Message field 'speed_cmd'."""
        return self._speed_cmd

    @speed_cmd.setter
    def speed_cmd(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'speed_cmd' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_cmd' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_cmd = value

    @builtins.property
    def steering_cmd(self):
        """Message field 'steering_cmd'."""
        return self._steering_cmd

    @steering_cmd.setter
    def steering_cmd(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'steering_cmd' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steering_cmd' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steering_cmd = value

    @builtins.property
    def limit_flags(self):
        """Message field 'limit_flags'."""
        return self._limit_flags

    @limit_flags.setter
    def limit_flags(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'limit_flags' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'limit_flags' field must be an unsigned integer in [0, 255]"
        self._limit_flags = value
