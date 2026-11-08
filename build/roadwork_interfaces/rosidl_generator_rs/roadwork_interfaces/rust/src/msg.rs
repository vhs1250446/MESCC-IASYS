#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to roadwork_interfaces__msg__VehicleCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VehicleCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// SI units. The simulator rejects nonfinite or stale commands (age > 0.30 s).
    pub speed: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub steering_angle: f64,

}



impl Default for VehicleCommand {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::VehicleCommand::default())
  }
}

impl rosidl_runtime_rs::Message for VehicleCommand {
  type RmwMsg = super::msg::rmw::VehicleCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        speed: msg.speed,
        steering_angle: msg.steering_angle,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      speed: msg.speed,
      steering_angle: msg.steering_angle,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      speed: msg.speed,
      steering_angle: msg.steering_angle,
    }
  }
}


// Corresponds to roadwork_interfaces__msg__RoadworkBeacon

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RoadworkBeacon {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RoadworkBeacon::default())
  }
}

impl rosidl_runtime_rs::Message for RoadworkBeacon {
  type RmwMsg = super::msg::rmw::RoadworkBeacon;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        valid_for: msg.valid_for,
        entry_x: msg.entry_x,
        work_start: msg.work_start,
        work_end: msg.work_end,
        exit_x: msg.exit_x,
        speed_limit: msg.speed_limit,
        pass_side: msg.pass_side,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      valid_for: msg.valid_for,
      entry_x: msg.entry_x,
      work_start: msg.work_start,
      work_end: msg.work_end,
      exit_x: msg.exit_x,
      speed_limit: msg.speed_limit,
      pass_side: msg.pass_side,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      valid_for: msg.valid_for,
      entry_x: msg.entry_x,
      work_start: msg.work_start,
      work_end: msg.work_end,
      exit_x: msg.exit_x,
      speed_limit: msg.speed_limit,
      pass_side: msg.pass_side,
    }
  }
}


// Corresponds to roadwork_interfaces__msg__RadarDetection

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RadarDetection::default())
  }
}

impl rosidl_runtime_rs::Message for RadarDetection {
  type RmwMsg = super::msg::rmw::RadarDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        range: msg.range,
        azimuth: msg.azimuth,
        radial_velocity: msg.radial_velocity,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      range: msg.range,
      azimuth: msg.azimuth,
      radial_velocity: msg.radial_velocity,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      range: msg.range,
      azimuth: msg.azimuth,
      radial_velocity: msg.radial_velocity,
    }
  }
}


// Corresponds to roadwork_interfaces__msg__RadarDetections

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RadarDetections {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detections: Vec<super::msg::RadarDetection>,

}



impl Default for RadarDetections {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RadarDetections::default())
  }
}

impl rosidl_runtime_rs::Message for RadarDetections {
  type RmwMsg = super::msg::rmw::RadarDetections;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        detections: msg.detections
          .into_iter()
          .map(|elem| super::msg::RadarDetection::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        detections: msg.detections
          .iter()
          .map(|elem| super::msg::RadarDetection::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      detections: msg.detections
          .into_iter()
          .map(super::msg::RadarDetection::from_rmw_message)
          .collect(),
    }
  }
}


