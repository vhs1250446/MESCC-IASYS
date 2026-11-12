// Path and speed-profile generation for the Plan node.
// Contract: team_docs/PLAN_ACT_CONTRACT.md "The path", team_docs/PLAN_NODE.md "Path".
// Pure functions: no ROS clock, no node.
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "roadwork_solution_msgs/msg/plan_point.hpp"

namespace roadwork_student {

using PlanPoint = roadwork_solution_msgs::msg::PlanPoint;

namespace path_const {
// Project contract (docs/INTERFACES.md, docs/SCENARIOS.md).
constexpr double kStartX = 5.0;            // m, start pose x
constexpr double kGoalX = 80.2;            // m, nominal aiming point
constexpr double kGoalY = -1.75;           // m
constexpr double kOwnLaneY = -1.75;        // m, own lane centre
constexpr double kOpposingLaneY = 1.75;    // m, opposing lane centre
constexpr double kFrontOffset = 0.9;       // m, collision disc radius / front of vehicle
constexpr double kWheelbase = 2.4;         // m
constexpr double kMaxSteer = 0.45;         // rad
constexpr double kMaxSteerRate = 0.6;      // rad/s
constexpr double kMaxAccel = 1.5;          // m/s^2, vehicle limit
constexpr double kDefaultSpeedLimit = 4.0; // m/s, when no beacon is cached
// Solution contract (team_docs/PLAN_ACT_CONTRACT.md).
constexpr std::size_t kMaxPoints = 250;    // PlanPoint[<=250]
constexpr double kMaxSpacing = 0.5;        // m, between consecutive points (arc length)
constexpr double kMaxPlanDecel = 2.0;      // m/s^2
// Design choices (team_docs/PLAN_NODE.md).
constexpr double kGridSpacing = 0.4;       // m in x; arc spacing stays <= 0.5 on the ramps
constexpr double kDenseSpacing = 0.2;      // m in x, in the stopping zones
constexpr double kDenseZone = 4.0;         // m before the stop point and the goal
constexpr double kRampStartOffset = 1.0;   // m after entry_x where the outbound ramp starts
constexpr double kMinOutRamp = 12.0;       // m, shortest outbound ramp accepted
constexpr double kPostWorkOffset = 2.0;    // m after work_end where the return ramp starts
constexpr double kReturnRamp = 16.0;       // m, return ramp length
}  // namespace path_const

// Work-zone geometry, from a validated beacon.
struct Geometry {
  double entry_x;
  double work_start;
  double work_end;
  double exit_x;
  double speed_limit;
};

struct PathParams {
  double v_cruise;     // m/s, profile cap below the speed limit
  double a_acc;        // m/s^2, forward pass
  double a_dec;        // m/s^2, backward pass
  double stop_margin;  // m, front stops this far before the stop line
  double slew_margin;  // fraction of the steering slew limit the profile may use
};

// Everything the path depends on. The node rebuilds only when this changes.
struct PathRequest {
  Geometry geo;
  bool stop_line;       // hold: speed 0 at the stop point and after it
  double accel_x;       // m, where the forward (acceleration) pass starts
  double accel_v;       // m/s, speed assumed at accel_x
  double v_max;         // m/s, min(speed_limit, v_cruise)
};

bool operator==(const PathRequest & a, const PathRequest & b);
inline bool operator!=(const PathRequest & a, const PathRequest & b) { return !(a == b); }

// Result of check_path(). OK = 0; anything else is an invariant violation.
enum class PathCheck : uint8_t {
  OK = 0,
  EMPTY,
  TOO_MANY_POINTS,
  NONFINITE,
  NEGATIVE_SPEED,
  NOT_FORWARD,
  SPACING,
  MISSING_STOP_POINT,
  BAD_GOAL,
  OVERSPEED,
  LANE_OCCUPANCY,
  CURVATURE,
  STEER_SLEW,
  DECEL,
  ACCEL,
  HOLD_NOT_ZERO,
};

const char * path_check_to_string(PathCheck c);

// Rear-axle x at which the vehicle must be stopped for a stop line at entry_x.
double stop_point_x(const Geometry & geo, const PathParams & p);

// True if this geometry can be served by the path builder (ramp lengths fit
// between entry, works and exit). Used by beacon validation.
bool geometry_supported(const Geometry & geo);

// Lateral position y(x) of the bypass path.
double lateral_y(const Geometry & geo, double x);

// Builds the full path from kStartX to the goal into `out` (cleared first;
// capacity is reused). Does not validate; call check_path() afterwards.
void build_path(const PathRequest & req, const PathParams & p, std::vector<PlanPoint> & out);

// Checks every invariant of the solution contract and team_docs/PLAN_NODE.md.
PathCheck check_path(const std::vector<PlanPoint> & path, const PathRequest & req,
                     const PathParams & p);

// Speed of the profile at x (linear between points; 0 outside the path).
double speed_at_x(const std::vector<PlanPoint> & path, double x);

}  // namespace roadwork_student
