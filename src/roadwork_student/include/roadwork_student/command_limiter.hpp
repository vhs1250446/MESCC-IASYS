// Act command limiter: pure functions, no node, no clock.
//
// Last stage before /vehicle/command. Guarantees "What Act promises" 3-4 in
// team_docs/PLAN_ACT_CONTRACT.md whatever the controller or Plan asked for:
// speed cap, stop line, steering clamp and steering slew.
#pragma once

#include <cstdint>

namespace roadwork_student {

struct LimiterParams {
  double speed_cap;       // m/s, Act's own cap (3.9)
  double max_steer;       // rad (0.45)
  double max_steer_rate;  // rad/s (0.6)
  double front_offset;    // m, rear axle -> front of the collision disc (0.9)
  double stop_decel;      // m/s^2, braking curve used for the stop line (2.0)
  double stop_margin;     // m, the front stops this far before the line
  double control_delay;   // s, time before a new command takes effect
};

struct LimiterInput {
  double speed_raw;          // m/s, from the controller
  double steering_raw;       // rad, from the controller
  double previous_steering;  // rad, last published steering
  double dt;                 // s, sim time since the last published command
  double rear_x;             // m, map, odometry x (rear axle)
  double current_speed;      // m/s, odometry forward speed
  double speed_limit;        // m/s, from the plan
  bool has_stop_line;
  double stop_line_x;        // m, map
};

struct LimiterOutput {
  double speed;
  double steering;
  uint8_t flags;  // ActStatus::LIMIT_* bitmask
};

// Highest speed from which the front can still stop before stop_line_x - stop_margin,
// after travelling current_speed * control_delay at the current speed.
double stop_line_speed(double rear_x, double current_speed, double stop_line_x,
                       const LimiterParams & p);

// Order: speed cap, stop line, steering clamp, steering slew (last, so the
// published steering always respects the rate limit), non-finite guard.
LimiterOutput limit_command(const LimiterInput & in, const LimiterParams & p);

}  // namespace roadwork_student
