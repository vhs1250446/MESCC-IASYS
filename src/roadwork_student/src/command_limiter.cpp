#include "roadwork_student/command_limiter.hpp"

#include <algorithm>
#include <cmath>

#include "roadwork_solution_msgs/msg/act_status.hpp"

namespace roadwork_student {

using ActStatus = roadwork_solution_msgs::msg::ActStatus;

double stop_line_speed(double rear_x, double current_speed, double stop_line_x,
                       const LimiterParams & p) {
  const double front = rear_x + p.front_offset;
  double d = stop_line_x - p.stop_margin - front;
  d -= std::max(0.0, current_speed) * p.control_delay;
  if (d <= 0.0) {
    return 0.0;
  }
  return std::sqrt(2.0 * p.stop_decel * d);
}

LimiterOutput limit_command(const LimiterInput & in, const LimiterParams & p) {
  LimiterOutput out{in.speed_raw, in.steering_raw, 0};

  // Speed: never faster than the plan's limit or Act's own cap.
  const double cap = std::min(in.speed_limit, p.speed_cap);
  if (out.speed > cap) {
    out.speed = cap;
    out.flags |= ActStatus::LIMIT_SPEED;
  }

  // Stop line: enforced here even if Plan's speed profile ignores it.
  if (in.has_stop_line) {
    const double v_stop = stop_line_speed(in.rear_x, in.current_speed, in.stop_line_x, p);
    if (out.speed > v_stop) {
      out.speed = v_stop;
      out.flags |= ActStatus::LIMIT_STOP_LINE;
    }
  }
  out.speed = std::max(0.0, out.speed);  // reverse is out of scope

  // Steering clamp.
  if (std::fabs(out.steering) > p.max_steer) {
    out.steering = std::clamp(out.steering, -p.max_steer, p.max_steer);
    out.flags |= ActStatus::LIMIT_STEER_CLAMP;
  }

  // Steering slew, applied last.
  const double step = p.max_steer_rate * std::max(0.0, in.dt);
  const double delta = out.steering - in.previous_steering;
  if (std::fabs(delta) > step) {
    out.steering = in.previous_steering + std::copysign(step, delta);
    out.flags |= ActStatus::LIMIT_STEER_SLEW;
  }

  // Last-line guard: never publish a non-finite command.
  if (!std::isfinite(out.speed) || !std::isfinite(out.steering)) {
    out.speed = 0.0;
    out.steering = std::isfinite(in.previous_steering) ? in.previous_steering : 0.0;
  }
  return out;
}

}
