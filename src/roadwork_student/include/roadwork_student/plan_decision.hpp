// Plan decision logic: scene validation, beacon geometry cache, entry
// permission and commitment. Contract: team_docs/PLAN_NODE.md.
// Pure functions: no ROS clock, no node.
#pragma once

#include <cstdint>

#include "roadwork_solution_msgs/msg/scene.hpp"
#include "roadwork_student/path_builder.hpp"

namespace roadwork_student {

using Scene = roadwork_solution_msgs::msg::Scene;

namespace decision_const {
constexpr double kBeaconValidFor = 1.2;  // s, project contract (docs/INTERFACES.md)
}  // namespace decision_const

struct DecisionParams {
  double scene_timeout;     // s, max scene age
  double future_tolerance;  // s
};

// Plan's memory across ticks. Cleared only by a reset (sim time going backwards).
struct PlanMemory {
  bool has_geometry = false;
  Geometry geo{};
  bool committed = false;
  bool fault_latched = false;
};

struct Decision {
  uint8_t mode;          // Plan::MODE_*
  uint8_t state;         // PlanStatus::STATE_*
  uint8_t reason;        // PlanStatus::REASON_*
  uint8_t deny_flags;    // PlanStatus::DENY_*
  bool stop_line;        // has_stop_line at geo.entry_x
  bool entry_violation;  // committed on this tick while entry was denied
  const char * label;    // decision_state, <= 32 characters
};

// Rows 2-5 of the decision table: REASON_NONE if the scene is usable.
uint8_t validate_scene(const Scene * scene, double now, const DecisionParams & p);

// Geometry from the scene's beacon fields, if the beacon is fresh (Plan's own
// stamp + 1.2 s check) and the geometry passes validation. False otherwise.
bool fresh_geometry(const Scene & scene, double now, const DecisionParams & p, Geometry & out);

// Bitmask of PlanStatus::DENY_* for the entry conditions that fail.
uint8_t entry_denials(const Scene & scene, double now, const DecisionParams & p);

// One tick of the decision table. Updates `mem` (geometry cache unless
// committed; commitment latch). Path faults are applied by the caller through
// fault_decision() because they are detected after the path is built.
Decision decide(const Scene * scene, double now, const DecisionParams & p, PlanMemory & mem);

// Row 1 / row 7: MODE_FAULT, STATE_FAULT, REASON_FAULT.
Decision fault_decision();

const char * plan_reason_to_string(uint8_t reason);

}  // namespace roadwork_student
