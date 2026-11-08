#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "roadwork_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__roadwork_interfaces__msg__VehicleCommand() -> *const std::ffi::c_void;
}

#[link(name = "roadwork_interfaces__rosidl_generator_c")]
extern "C" {
    fn roadwork_interfaces__msg__VehicleCommand__init(msg: *mut VehicleCommand) -> bool;
    fn roadwork_interfaces__msg__VehicleCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VehicleCommand>, size: usize) -> bool;
    fn roadwork_interfaces__msg__VehicleCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VehicleCommand>);
    fn roadwork_interfaces__msg__VehicleCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VehicleCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<VehicleCommand>) -> bool;
}

// Corresponds to roadwork_interfaces__msg__VehicleCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VehicleCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// SI units. The simulator rejects nonfinite or stale commands (age > 0.30 s).
    pub speed: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub steering_angle: f64,

}



impl Default for VehicleCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !roadwork_interfaces__msg__VehicleCommand__init(&mut msg as *mut _) {
        panic!("Call to roadwork_interfaces__msg__VehicleCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VehicleCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__VehicleCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__VehicleCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__VehicleCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VehicleCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VehicleCommand where Self: Sized {
  const TYPE_NAME: &'static str = "roadwork_interfaces/msg/VehicleCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__roadwork_interfaces__msg__VehicleCommand() }
  }
}


#[link(name = "roadwork_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__roadwork_interfaces__msg__RoadworkBeacon() -> *const std::ffi::c_void;
}

#[link(name = "roadwork_interfaces__rosidl_generator_c")]
extern "C" {
    fn roadwork_interfaces__msg__RoadworkBeacon__init(msg: *mut RoadworkBeacon) -> bool;
    fn roadwork_interfaces__msg__RoadworkBeacon__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RoadworkBeacon>, size: usize) -> bool;
    fn roadwork_interfaces__msg__RoadworkBeacon__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RoadworkBeacon>);
    fn roadwork_interfaces__msg__RoadworkBeacon__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RoadworkBeacon>, out_seq: *mut rosidl_runtime_rs::Sequence<RoadworkBeacon>) -> bool;
}

// Corresponds to roadwork_interfaces__msg__RoadworkBeacon
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RoadworkBeacon {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub valid_for: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub entry_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_start: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_end: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub exit_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed_limit: f64,

    /// +1 means pass to the left. Only +1 is supported in challenge v1.
    pub pass_side: i8,

}



impl Default for RoadworkBeacon {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !roadwork_interfaces__msg__RoadworkBeacon__init(&mut msg as *mut _) {
        panic!("Call to roadwork_interfaces__msg__RoadworkBeacon__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RoadworkBeacon {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RoadworkBeacon__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RoadworkBeacon__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RoadworkBeacon__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RoadworkBeacon {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RoadworkBeacon where Self: Sized {
  const TYPE_NAME: &'static str = "roadwork_interfaces/msg/RoadworkBeacon";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__roadwork_interfaces__msg__RoadworkBeacon() }
  }
}


#[link(name = "roadwork_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__roadwork_interfaces__msg__RadarDetection() -> *const std::ffi::c_void;
}

#[link(name = "roadwork_interfaces__rosidl_generator_c")]
extern "C" {
    fn roadwork_interfaces__msg__RadarDetection__init(msg: *mut RadarDetection) -> bool;
    fn roadwork_interfaces__msg__RadarDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RadarDetection>, size: usize) -> bool;
    fn roadwork_interfaces__msg__RadarDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RadarDetection>);
    fn roadwork_interfaces__msg__RadarDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RadarDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<RadarDetection>) -> bool;
}

// Corresponds to roadwork_interfaces__msg__RadarDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RadarDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub range: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub azimuth: f64,

    /// Negative = closing. Includes the ego vehicle's motion.
    pub radial_velocity: f64,

}



impl Default for RadarDetection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !roadwork_interfaces__msg__RadarDetection__init(&mut msg as *mut _) {
        panic!("Call to roadwork_interfaces__msg__RadarDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RadarDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RadarDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RadarDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RadarDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RadarDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RadarDetection where Self: Sized {
  const TYPE_NAME: &'static str = "roadwork_interfaces/msg/RadarDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__roadwork_interfaces__msg__RadarDetection() }
  }
}


#[link(name = "roadwork_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__roadwork_interfaces__msg__RadarDetections() -> *const std::ffi::c_void;
}

#[link(name = "roadwork_interfaces__rosidl_generator_c")]
extern "C" {
    fn roadwork_interfaces__msg__RadarDetections__init(msg: *mut RadarDetections) -> bool;
    fn roadwork_interfaces__msg__RadarDetections__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RadarDetections>, size: usize) -> bool;
    fn roadwork_interfaces__msg__RadarDetections__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RadarDetections>);
    fn roadwork_interfaces__msg__RadarDetections__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RadarDetections>, out_seq: *mut rosidl_runtime_rs::Sequence<RadarDetections>) -> bool;
}

// Corresponds to roadwork_interfaces__msg__RadarDetections
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RadarDetections {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detections: rosidl_runtime_rs::Sequence<super::super::msg::rmw::RadarDetection>,

}



impl Default for RadarDetections {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !roadwork_interfaces__msg__RadarDetections__init(&mut msg as *mut _) {
        panic!("Call to roadwork_interfaces__msg__RadarDetections__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RadarDetections {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RadarDetections__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RadarDetections__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { roadwork_interfaces__msg__RadarDetections__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RadarDetections {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RadarDetections where Self: Sized {
  const TYPE_NAME: &'static str = "roadwork_interfaces/msg/RadarDetections";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__roadwork_interfaces__msg__RadarDetections() }
  }
}


