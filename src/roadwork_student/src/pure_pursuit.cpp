#include "roadwork_student/pure_pursuit.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

namespace roadwork_student {

namespace {

constexpr double kEps = 1e-9;

// Result of walking `distance` metres forward along the path from a projection.
struct WalkResult {
  double x;
  double y;
  double speed;      // interpolated profile speed at (x, y)
  double overshoot;  // m left over after reaching the last point (0 if inside the path)
};

// Speed of the profile at the projection point (linear between the two vertices).
double speed_at_projection(const Path & path, const PathProjection & from) {
  if (path.size() == 1 || from.segment + 1 >= path.size()) {
    return path[std::min(from.segment, path.size() - 1)].speed;
  }
  const auto & a = path[from.segment];
  const auto & b = path[from.segment + 1];
  return a.speed + from.t * (b.speed - a.speed);
}

WalkResult walk_along(const Path & path, const PathProjection & from, double distance) {
  double x0 = from.px;
  double y0 = from.py;
  double s0 = speed_at_projection(path, from);
  double remaining = std::max(0.0, distance);

  for (std::size_t i = from.segment; i + 1 < path.size(); ++i) {
    const auto & next = path[i + 1];
    const double seg_len = std::hypot(next.x - x0, next.y - y0);
    if (remaining <= seg_len && seg_len > kEps) {
      const double r = remaining / seg_len;
      return {x0 + r * (next.x - x0), y0 + r * (next.y - y0),
              s0 + r * (next.speed - s0), 0.0};
    }
    remaining -= seg_len;
    x0 = next.x;
    y0 = next.y;
    s0 = next.speed;
  }
  return {x0, y0, s0, remaining};  // at the last point, `remaining` metres short
}

// Unit direction of the last non-degenerate segment; false if the path has none.
bool last_direction(const Path & path, double & ux, double & uy) {
  for (std::size_t i = path.size(); i >= 2; --i) {
    const double dx = path[i - 1].x - path[i - 2].x;
    const double dy = path[i - 1].y - path[i - 2].y;
    const double len = std::hypot(dx, dy);
    if (len > kEps) {
      ux = dx / len;
      uy = dy / len;
      return true;
    }
  }
  return false;
}

}  // namespace

double yaw_from_quaternion(const geometry_msgs::msg::Quaternion & q) {
  return std::atan2(2.0 * (q.w * q.z + q.x * q.y),
                    1.0 - 2.0 * (q.y * q.y + q.z * q.z));
}

double wrap_angle(double a) {
  return std::atan2(std::sin(a), std::cos(a));
}

PathProjection project_onto_path(const Path & path, double x, double y) {
  PathProjection best{0, 0.0, 0.0, 0.0, 0.0, 0.0};
  if (path.empty()) {
    return best;  // the validator rejects empty paths; defensive only
  }
  best.px = path[0].x;
  best.py = path[0].y;

  double best_d2 = std::numeric_limits<double>::infinity();
  double best_dx = 0.0;
  double best_dy = 0.0;

  for (std::size_t i = 0; i + 1 < path.size(); ++i) {
    const double dx = path[i + 1].x - path[i].x;
    const double dy = path[i + 1].y - path[i].y;
    const double len2 = dx * dx + dy * dy;
    if (len2 < kEps) {
      continue;  // duplicate points
    }
    const double t = std::clamp(
        ((x - path[i].x) * dx + (y - path[i].y) * dy) / len2, 0.0, 1.0);
    const double cx = path[i].x + t * dx;
    const double cy = path[i].y + t * dy;
    const double d2 = (x - cx) * (x - cx) + (y - cy) * (y - cy);
    if (d2 < best_d2) {
      best_d2 = d2;
      best = {i, t, cx, cy, 0.0, 0.0};
      best_dx = dx;
      best_dy = dy;
    }
  }

  if (best_d2 == std::numeric_limits<double>::infinity()) {
    return best;  // single point or all duplicates: no direction available
  }
  const double len = std::hypot(best_dx, best_dy);
  best.path_heading = std::atan2(best_dy, best_dx);
  // 2-D cross product of the unit path direction with (vehicle - closest): + = left.
  best.cross_track_error = (best_dx * (y - best.py) - best_dy * (x - best.px)) / len;
  return best;
}

void point_at_distance(const Path & path, const PathProjection & from, double distance,
                       double & out_x, double & out_y) {
  const WalkResult w = walk_along(path, from, distance);
  out_x = w.x;
  out_y = w.y;
  double ux = 0.0;
  double uy = 0.0;
  if (w.overshoot > 0.0 && last_direction(path, ux, uy)) {
    // Past the goal: extend along the last segment so the lookahead distance
    // does not collapse (which would make the curvature blow up near the goal).
    out_x += w.overshoot * ux;
    out_y += w.overshoot * uy;
  }
}

double speed_at_distance(const Path & path, const PathProjection & from, double distance) {
  if (path.empty()) {
    return 0.0;
  }
  const WalkResult w = walk_along(path, from, distance);
  return w.overshoot > 0.0 ? 0.0 : w.speed;  // beyond the end of the path: no motion
}

double pure_pursuit_steering(const Pose2D & pose, double tx, double ty, double wheelbase) {
  const double dx = tx - pose.x;
  const double dy = ty - pose.y;
  const double c = std::cos(pose.yaw);
  const double s = std::sin(pose.yaw);
  const double xv = c * dx + s * dy;   // map -> vehicle (base_link) frame
  const double yv = -s * dx + c * dy;
  const double ld2 = xv * xv + yv * yv;
  if (ld2 < 1e-6) {
    return 0.0;
  }
  const double curvature = 2.0 * yv / ld2;
  return std::atan(wheelbase * curvature);
}

TrackingOutput track_path(const Path & path, const Pose2D & pose, double v,
                          const PurePursuitParams & p) {
  TrackingOutput out{0.0, 0.0, 0.0, 0.0, 0, pose.x, pose.y};
  if (path.empty()) {
    return out;  // speed 0, steering 0
  }

  const PathProjection proj = project_onto_path(path, pose.x, pose.y);
  const double lookahead = std::clamp(p.lookahead_gain * std::fabs(v),
                                      p.lookahead_min, p.lookahead_max);

  point_at_distance(path, proj, lookahead, out.lookahead_x, out.lookahead_y);
  out.steering = pure_pursuit_steering(pose, out.lookahead_x, out.lookahead_y, p.wheelbase);

  // max() only raises the target where the profile rises ahead (e.g. a cleared
  // stop line whose current point has speed 0); it never delays braking.
  out.speed = std::max(speed_at_distance(path, proj, 0.0),
                       speed_at_distance(path, proj, p.speed_preview));

  out.cross_track_error = proj.cross_track_error;
  out.heading_error = wrap_angle(pose.yaw - proj.path_heading);
  const std::size_t nearest = (proj.t < 0.5 || proj.segment + 1 >= path.size())
                                  ? proj.segment : proj.segment + 1;
  out.nearest_index = static_cast<uint32_t>(nearest);
  return out;
}

}