#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "roadwork_solution_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__roadwork_solution_msgs__msg__PlanPoint() -> *const std::ffi::c_void;
}

#[link(name = "roadwork_solution_msgs__rosidl_generator_c")]
extern "C" {
    fn roadwork_solution_msgs__msg__PlanPoint__init(msg: *mut PlanPoint) -> bool;
    fn roadwork_solution_msgs__msg__PlanPoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanPoint>, size: usize) -> bool;
    fn roadwork_solution_msgs__msg__PlanPoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanPoint>);
    fn roadwork_solution_msgs__msg__PlanPoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanPoint>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanPoint>) -> bool;
}

// Corresponds to roadwork_solution_msgs__msg__PlanPoint
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanPoint {
    /// m, map frame, rear-axle reference
    pub x: f64,

    /// m, map frame
    pub y: f64,

    /// m/s, target speed when the rear axle is at this point, >= 0
    pub speed: f64,

}



impl Default for PlanPoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !roadwork_solution_msgs__msg__PlanPoint__init(&mut msg as *mut _) {
        panic!("Call to roadwork_solution_msgs__msg__PlanPoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanPoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__PlanPoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__PlanPoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__PlanPoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanPoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanPoint where Self: Sized {
  const TYPE_NAME: &'static str = "roadwork_solution_msgs/msg/PlanPoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__roadwork_solution_msgs__msg__PlanPoint() }
  }
}


#[link(name = "roadwork_solution_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__roadwork_solution_msgs__msg__Plan() -> *const std::ffi::c_void;
}

#[link(name = "roadwork_solution_msgs__rosidl_generator_c")]
extern "C" {
    fn roadwork_solution_msgs__msg__Plan__init(msg: *mut Plan) -> bool;
    fn roadwork_solution_msgs__msg__Plan__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Plan>, size: usize) -> bool;
    fn roadwork_solution_msgs__msg__Plan__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Plan>);
    fn roadwork_solution_msgs__msg__Plan__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Plan>, out_seq: *mut rosidl_runtime_rs::Sequence<Plan>) -> bool;
}

// Corresponds to roadwork_solution_msgs__msg__Plan
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Plan {
    /// stamp: sim time of computation; frame_id: "map"
    pub header: std_msgs::msg::rmw::Header,

    /// stamp of the Scene this plan was built from
    pub scene_stamp: builtin_interfaces::msg::rmw::Time,

    /// Act must not execute this plan after this instant
    pub valid_until: builtin_interfaces::msg::rmw::Time,

    /// increments by one on every publication
    pub seq: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: u8,

    /// ordered in travel direction; non-empty if MODE_TRACK
    pub path: rosidl_runtime_rs::Sequence<super::super::msg::rmw::PlanPoint>,

    /// m/s, from beacon or nominal 4.0
    pub speed_limit: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub has_stop_line: bool,

    /// m, map; vehicle front (x + 0.9) must stay below it
    pub stop_line_x: f64,

    /// Plan's state name, for logs and traceability only
    pub decision_state: rosidl_runtime_rs::String,

}

impl Plan {
    /// brake to standstill now; ignore path
    pub const MODE_STOP: u8 = 0;

    /// track path under speed profile and constraints
    pub const MODE_TRACK: u8 = 1;

}


impl Default for Plan {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !roadwork_solution_msgs__msg__Plan__init(&mut msg as *mut _) {
        panic!("Call to roadwork_solution_msgs__msg__Plan__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Plan {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__Plan__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__Plan__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__Plan__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Plan {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Plan where Self: Sized {
  const TYPE_NAME: &'static str = "roadwork_solution_msgs/msg/Plan";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__roadwork_solution_msgs__msg__Plan() }
  }
}


#[link(name = "roadwork_solution_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__roadwork_solution_msgs__msg__ActStatus() -> *const std::ffi::c_void;
}

#[link(name = "roadwork_solution_msgs__rosidl_generator_c")]
extern "C" {
    fn roadwork_solution_msgs__msg__ActStatus__init(msg: *mut ActStatus) -> bool;
    fn roadwork_solution_msgs__msg__ActStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ActStatus>, size: usize) -> bool;
    fn roadwork_solution_msgs__msg__ActStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ActStatus>);
    fn roadwork_solution_msgs__msg__ActStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ActStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<ActStatus>) -> bool;
}

// Corresponds to roadwork_solution_msgs__msg__ActStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ActStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: u8,

    /// why SAFE_STOP, e.g. PLAN_EXPIRED, ODOM_STALE
    pub reason: rosidl_runtime_rs::String,

    /// seq of the plan in use
    pub plan_seq: u32,

    /// s, now minus plan header stamp
    pub plan_age: f64,

    /// s, now minus odometry stamp
    pub odom_age: f64,

    /// progress index on the path
    pub target_index: u32,

    /// m, signed, left positive
    pub cross_track_error: f64,

    /// rad
    pub heading_error: f64,

    /// m/s, before limits
    pub speed_raw: f64,

    /// rad, before limits
    pub steering_raw: f64,

    /// m/s, as published
    pub speed_cmd: f64,

    /// rad, as published
    pub steering_cmd: f64,

    /// bitmask: speed cap, stop line, steering clamp, slew
    pub limit_flags: u8,

}

impl ActStatus {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATE_INIT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATE_TRACKING: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATE_SAFE_STOP: u8 = 2;

}


impl Default for ActStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !roadwork_solution_msgs__msg__ActStatus__init(&mut msg as *mut _) {
        panic!("Call to roadwork_solution_msgs__msg__ActStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ActStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__ActStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__ActStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_solution_msgs__msg__ActStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ActStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ActStatus where Self: Sized {
  const TYPE_NAME: &'static str = "roadwork_solution_msgs/msg/ActStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__roadwork_solution_msgs__msg__ActStatus() }
  }
}


