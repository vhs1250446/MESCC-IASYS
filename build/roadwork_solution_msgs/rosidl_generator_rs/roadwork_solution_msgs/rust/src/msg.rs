#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to roadwork_solution_msgs__msg__PlanPoint

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PlanPoint::default())
  }
}

impl rosidl_runtime_rs::Message for PlanPoint {
  type RmwMsg = super::msg::rmw::PlanPoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      speed: msg.speed,
    }
  }
}


// Corresponds to roadwork_solution_msgs__msg__Plan

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Plan {
    /// stamp: sim time of computation; frame_id: "map"
    pub header: std_msgs::msg::Header,

    /// stamp of the Scene this plan was built from
    pub scene_stamp: builtin_interfaces::msg::Time,

    /// Act must not execute this plan after this instant
    pub valid_until: builtin_interfaces::msg::Time,

    /// increments by one on every publication
    pub seq: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: u8,

    /// ordered in travel direction; non-empty if MODE_TRACK
    pub path: Vec<super::msg::PlanPoint>,

    /// m/s, from beacon or nominal 4.0
    pub speed_limit: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub has_stop_line: bool,

    /// m, map; vehicle front (x + 0.9) must stay below it
    pub stop_line_x: f64,

    /// Plan's state name, for logs and traceability only
    pub decision_state: std::string::String,

}

impl Plan {
    /// brake to standstill now; ignore path
    pub const MODE_STOP: u8 = 0;

    /// track path under speed profile and constraints
    pub const MODE_TRACK: u8 = 1;

}


impl Default for Plan {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Plan::default())
  }
}

impl rosidl_runtime_rs::Message for Plan {
  type RmwMsg = super::msg::rmw::Plan;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        scene_stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.scene_stamp)).into_owned(),
        valid_until: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.valid_until)).into_owned(),
        seq: msg.seq,
        mode: msg.mode,
        path: msg.path
          .into_iter()
          .map(|elem| super::msg::PlanPoint::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        speed_limit: msg.speed_limit,
        has_stop_line: msg.has_stop_line,
        stop_line_x: msg.stop_line_x,
        decision_state: msg.decision_state.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        scene_stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.scene_stamp)).into_owned(),
        valid_until: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.valid_until)).into_owned(),
      seq: msg.seq,
      mode: msg.mode,
        path: msg.path
          .iter()
          .map(|elem| super::msg::PlanPoint::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      speed_limit: msg.speed_limit,
      has_stop_line: msg.has_stop_line,
      stop_line_x: msg.stop_line_x,
        decision_state: msg.decision_state.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      scene_stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.scene_stamp),
      valid_until: builtin_interfaces::msg::Time::from_rmw_message(msg.valid_until),
      seq: msg.seq,
      mode: msg.mode,
      path: msg.path
          .into_iter()
          .map(super::msg::PlanPoint::from_rmw_message)
          .collect(),
      speed_limit: msg.speed_limit,
      has_stop_line: msg.has_stop_line,
      stop_line_x: msg.stop_line_x,
      decision_state: msg.decision_state.to_string(),
    }
  }
}


// Corresponds to roadwork_solution_msgs__msg__ActStatus

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ActStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: u8,

    /// why SAFE_STOP, e.g. PLAN_EXPIRED, ODOM_STALE
    pub reason: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ActStatus::default())
  }
}

impl rosidl_runtime_rs::Message for ActStatus {
  type RmwMsg = super::msg::rmw::ActStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        state: msg.state,
        reason: msg.reason.as_str().into(),
        plan_seq: msg.plan_seq,
        plan_age: msg.plan_age,
        odom_age: msg.odom_age,
        target_index: msg.target_index,
        cross_track_error: msg.cross_track_error,
        heading_error: msg.heading_error,
        speed_raw: msg.speed_raw,
        steering_raw: msg.steering_raw,
        speed_cmd: msg.speed_cmd,
        steering_cmd: msg.steering_cmd,
        limit_flags: msg.limit_flags,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      state: msg.state,
        reason: msg.reason.as_str().into(),
      plan_seq: msg.plan_seq,
      plan_age: msg.plan_age,
      odom_age: msg.odom_age,
      target_index: msg.target_index,
      cross_track_error: msg.cross_track_error,
      heading_error: msg.heading_error,
      speed_raw: msg.speed_raw,
      steering_raw: msg.steering_raw,
      speed_cmd: msg.speed_cmd,
      steering_cmd: msg.steering_cmd,
      limit_flags: msg.limit_flags,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      state: msg.state,
      reason: msg.reason.to_string(),
      plan_seq: msg.plan_seq,
      plan_age: msg.plan_age,
      odom_age: msg.odom_age,
      target_index: msg.target_index,
      cross_track_error: msg.cross_track_error,
      heading_error: msg.heading_error,
      speed_raw: msg.speed_raw,
      steering_raw: msg.steering_raw,
      speed_cmd: msg.speed_cmd,
      steering_cmd: msg.steering_cmd,
      limit_flags: msg.limit_flags,
    }
  }
}


