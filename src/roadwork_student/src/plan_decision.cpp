#include "roadwork_student/plan_decision.hpp"

#include <cmath>

#include "roadwork_solution_msgs/msg/plan.hpp"
#include "roadwork_solution_msgs/msg/plan_status.hpp"
#include "roadwork_student/time_utils.hpp"

namespace roadwork_student {

using Plan = roadwork_solution_msgs::msg::Plan;
using PlanStatus = roadwork_solution_msgs::msg::PlanStatus;

namespace {

Decision make(uint8_t mode, uint8_t state, uint8_t reason, const char * label) {
  return Decision{mode, state, reason, 0, false, false, label};
}

// Log label for a committed vehicle, from its rear-axle x (logs only).
const char * committed_label(const Geometry & g, double ego_x) {
  if (ego_x >= path_const::kGoalX - 0.2) {
    return "GOAL";
  }
  if (ego_x + path_const::kFrontOffset < g.work_start) {
    return "COMMITTED";
  }
  if (ego_x < g.work_end + path_const::kPostWorkOffset) {
    return "BYPASS";
  }
  if (ego_x < g.work_end + path_const::kPostWorkOffset + path_const::kReturnRamp) {
    return "RETURN";
  }
  return "TO_GOAL";
}

}  // namespace

uint8_t validate_scene(const Scene * scene, double now, const DecisionParams & p) {
  if (scene == nullptr) {
    return PlanStatus::REASON_NO_SCENE;
  }
  const double stamp = to_seconds(scene->header.stamp);
  if (is_future(stamp, now, p.future_tolerance)) {
    return PlanStatus::REASON_SCENE_FUTURE;
  }
  if (now - stamp > p.scene_timeout) {
    return PlanStatus::REASON_SCENE_STALE;
  }
  if (scene->sense_status == Scene::SENSE_FAULT) {
    return PlanStatus::REASON_SENSE_FAULT;
  }
  if (!std::isfinite(scene->ego_x)) {
    return PlanStatus::REASON_SENSE_FAULT;  // Sense promises finite fields
  }
  return PlanStatus::REASON_NONE;
}

bool fresh_geometry(const Scene & s, double now, const DecisionParams & p, Geometry & out) {
  if (!s.beacon_valid) {
    return false;
  }
  const double beacon_stamp = to_seconds(s.beacon_stamp);
  if (is_future(beacon_stamp, now, p.future_tolerance) ||
      now > beacon_stamp + decision_const::kBeaconValidFor) {
    return false;
  }
  const Geometry g{s.entry_x, s.work_start, s.work_end, s.exit_x, s.speed_limit};
  const bool finite = std::isfinite(g.entry_x) && std::isfinite(g.work_start) &&
                      std::isfinite(g.work_end) && std::isfinite(g.exit_x) &&
                      std::isfinite(g.speed_limit);
  if (!finite) {
    return false;
  }
  const bool ordered = g.entry_x < g.work_start && g.work_start < g.work_end &&
                       g.work_end < g.exit_x;
  const bool limit_ok = g.speed_limit > 0.0 && g.speed_limit <= path_const::kDefaultSpeedLimit;
  if (!ordered || !limit_ok || s.pass_side != 1 || !geometry_supported(g)) {
    return false;
  }
  out = g;
  return true;
}

uint8_t entry_denials(const Scene & s, double now, const DecisionParams & p) {
  uint8_t flags = 0;
  if (s.panel_state != Scene::PANEL_GO) {
    flags |= PlanStatus::DENY_PANEL;
  }
  Geometry unused{};
  if (!fresh_geometry(s, now, p, unused)) {
    flags |= PlanStatus::DENY_BEACON;
  }
  if (s.stale_flags & Scene::STALE_CAMERA) {
    flags |= PlanStatus::DENY_CAMERA_STALE;
  }
  if (s.stale_flags & Scene::STALE_LIDAR) {
    flags |= PlanStatus::DENY_LIDAR_STALE;
  }
  if (s.obstacle_in_lane) {
    flags |= PlanStatus::DENY_LANE_BLOCKED;
  }
  return flags;
}

Decision fault_decision() {
  return make(Plan::MODE_FAULT, PlanStatus::STATE_FAULT, PlanStatus::REASON_FAULT, "FAULT");
}

Decision decide(const Scene * scene, double now, const DecisionParams & p, PlanMemory & mem) {
  // Row 1: latched fault.
  if (mem.fault_latched) {
    return fault_decision();
  }
  // Rows 2-5: scene problems -> MODE_STOP (recoverable).
  const uint8_t scene_reason = validate_scene(scene, now, p);
  switch (scene_reason) {
    case PlanStatus::REASON_NONE:
      break;
    case PlanStatus::REASON_NO_SCENE:
      return make(Plan::MODE_STOP, PlanStatus::STATE_INIT, scene_reason, "NO_SCENE");
    default:
      return make(Plan::MODE_STOP, PlanStatus::STATE_SAFE_STOP, scene_reason,
                  plan_reason_to_string(scene_reason));
  }

  // Geometry cache: refreshed from every valid beacon, frozen once committed.
  Geometry g{};
  if (!mem.committed && fresh_geometry(*scene, now, p, g)) {
    mem.geo = g;
    mem.has_geometry = true;
  }
  // Row 6.
  if (!mem.has_geometry) {
    return make(Plan::MODE_STOP, PlanStatus::STATE_INIT, PlanStatus::REASON_NO_GEOMETRY,
                "NO_GEOMETRY");
  }

  // Commitment: decided by position alone, so a restarted Plan (or a crossing
  // on a denied tick) never places the stop line behind the vehicle front.
  const uint8_t deny = entry_denials(*scene, now, p);
  bool entry_violation = false;
  if (!mem.committed && scene->ego_x + path_const::kFrontOffset > mem.geo.entry_x) {
    mem.committed = true;
    entry_violation = deny != 0;
  }

  // Row 10.
  if (mem.committed) {
    Decision d = make(Plan::MODE_TRACK, PlanStatus::STATE_TRACKING, PlanStatus::REASON_NONE,
                      committed_label(mem.geo, scene->ego_x));
    d.entry_violation = entry_violation;
    return d;
  }
  // Row 8.
  if (deny != 0) {
    Decision d = make(Plan::MODE_TRACK, PlanStatus::STATE_HOLD, PlanStatus::REASON_ENTRY_DENIED,
                      "HOLD_AT_ENTRY");
    d.deny_flags = deny;
    d.stop_line = true;
    return d;
  }
  // Row 9.
  return make(Plan::MODE_TRACK, PlanStatus::STATE_TRACKING, PlanStatus::REASON_NONE, "ENTRY_GO");
}

const char * plan_reason_to_string(uint8_t reason) {
  switch (reason) {
    case PlanStatus::REASON_NONE:         return "NONE";
    case PlanStatus::REASON_NO_SCENE:     return "NO_SCENE";
    case PlanStatus::REASON_SCENE_FUTURE: return "SCENE_FUTURE";
    case PlanStatus::REASON_SCENE_STALE:  return "SCENE_STALE";
    case PlanStatus::REASON_SENSE_FAULT:  return "SENSE_FAULT";
    case PlanStatus::REASON_NO_GEOMETRY:  return "NO_GEOMETRY";
    case PlanStatus::REASON_ENTRY_DENIED: return "ENTRY_DENIED";
    case PlanStatus::REASON_FAULT:        return "FAULT";
    default:                              return "UNKNOWN";
  }
}

}  // namespace roadwork_student
