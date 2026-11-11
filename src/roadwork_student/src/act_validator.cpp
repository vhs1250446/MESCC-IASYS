#include "roadwork_student/act_validator.hpp"

#include <cmath>

#include "roadwork_solution_msgs/msg/act_status.hpp"

namespace roadwork_student {

using ActStatus = roadwork_solution_msgs::msg::ActStatus;
using Plan = roadwork_solution_msgs::msg::Plan;
using Odometry = nav_msgs::msg::Odometry;

double to_seconds(const builtin_interfaces::msg::Time & t) {
  return static_cast<double>(t.sec) + static_cast<double>(t.nanosec) * 1e-9;
}

namespace {

bool plan_is_well_formed(const Plan & plan) {
  if (plan.mode != Plan::MODE_TRACK) {
    return false;  // MODE_STOP / MODE_FAULT are handled before this; anything else is unknown
  }
  if (plan.header.frame_id != "map") {
    return false;
  }
  if (plan.path.empty()) {
    return false;
  }
  for (const auto & pt : plan.path) {
    if (!std::isfinite(pt.x) || !std::isfinite(pt.y) ||
        !std::isfinite(pt.speed) || pt.speed < 0.0) {
      return false;
    }
  }
  if (!std::isfinite(plan.speed_limit) || plan.speed_limit <= 0.0) {
    return false;
  }
  if (plan.has_stop_line && !std::isfinite(plan.stop_line_x)) {
    return false;
  }
  return true;
}

bool odometry_is_finite(const Odometry & odom) {
  const auto & pos = odom.pose.pose.position;
  const auto & q = odom.pose.pose.orientation;
  const auto & v = odom.twist.twist.linear;
  return std::isfinite(pos.x) && std::isfinite(pos.y) &&
         std::isfinite(q.x) && std::isfinite(q.y) &&
         std::isfinite(q.z) && std::isfinite(q.w) &&
         std::isfinite(v.x);
}

}  // namespace

uint8_t validate_plan(const Plan * plan, double now, const ValidatorParams & p) {
  if (plan == nullptr) {
    return ActStatus::REASON_NO_PLAN;
  }
  if (plan->mode == Plan::MODE_FAULT) {
    return ActStatus::REASON_FAULT;
  }

  const double stamp = to_seconds(plan->header.stamp);
  if (stamp - now > p.future_tolerance) {
    return ActStatus::REASON_PLAN_FUTURE;
  }
  if (now > to_seconds(plan->valid_until) || now - stamp > p.plan_timeout) {
    return ActStatus::REASON_PLAN_EXPIRED;
  }
  if (now - to_seconds(plan->scene_stamp) > p.scene_timeout) {
    return ActStatus::REASON_SCENE_STALE;
  }
  if (plan->mode == Plan::MODE_STOP) {
    return ActStatus::REASON_PLAN_MODE_STOP;
  }
  if (!plan_is_well_formed(*plan)) {
    return ActStatus::REASON_PLAN_MALFORMED;
  }
  return ActStatus::REASON_NONE;
}

uint8_t validate_odometry(const Odometry * odom, double now, const ValidatorParams & p) {
  if (odom == nullptr) {
    return ActStatus::REASON_ODOM_STALE;  // the contract has no separate NO_ODOM code
  }
  if (!odometry_is_finite(*odom)) {
    return ActStatus::REASON_ODOM_MALFORMED;
  }
  if (now - to_seconds(odom->header.stamp) > p.odom_timeout) {
    return ActStatus::REASON_ODOM_STALE;
  }
  return ActStatus::REASON_NONE;
}

uint8_t validate_inputs(
  const Plan * plan, const Odometry * odom, double now, const ValidatorParams & p)
{
  const uint8_t plan_reason = validate_plan(plan, now, p);
  if (plan_reason != ActStatus::REASON_NONE) {
    return plan_reason;
  }
  return validate_odometry(odom, now, p);
}

bool is_newer_plan(const Plan & plan, double stopped_plan_stamp) {
  return to_seconds(plan.header.stamp) > stopped_plan_stamp;
}

const char * reason_to_string(uint8_t reason_code) {
  switch (reason_code) {
    case ActStatus::REASON_NONE:            return "NONE";
    case ActStatus::REASON_NO_PLAN:         return "NO_PLAN";
    case ActStatus::REASON_PLAN_EXPIRED:    return "PLAN_EXPIRED";
    case ActStatus::REASON_PLAN_FUTURE:     return "PLAN_FUTURE";
    case ActStatus::REASON_PLAN_MALFORMED:  return "PLAN_MALFORMED";
    case ActStatus::REASON_SCENE_STALE:     return "SCENE_STALE";
    case ActStatus::REASON_ODOM_STALE:      return "ODOM_STALE";
    case ActStatus::REASON_ODOM_MALFORMED:  return "ODOM_MALFORMED";
    case ActStatus::REASON_PLAN_MODE_STOP:  return "PLAN_MODE_STOP";
    case ActStatus::REASON_WAITING_NEW_SEQ: return "WAITING_NEW_SEQ";
    case ActStatus::REASON_FAULT:           return "FAULT";
    default:                                return "UNKNOWN_REASON";
  }
}

}
