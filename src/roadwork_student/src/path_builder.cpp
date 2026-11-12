#include "roadwork_student/path_builder.hpp"

#include <algorithm>
#include <cmath>

namespace roadwork_student {

using namespace path_const;

namespace {

constexpr double kEps = 1e-9;

// Lateral offset y(x) and its x-derivatives on one quintic ramp
// s(tau) = 10 tau^3 - 15 tau^4 + 6 tau^5: zero slope and zero curvature at
// both ends, so the path is C2 where the ramps join.
struct Lateral {
  double y, d1, d2, d3;
};

Lateral ramp(double x, double x0, double x1, double y0, double y1) {
  if (x <= x0) {
    return {y0, 0.0, 0.0, 0.0};
  }
  if (x >= x1) {
    return {y1, 0.0, 0.0, 0.0};
  }
  const double L = x1 - x0;
  const double d = y1 - y0;
  const double t = (x - x0) / L;
  const double s = t * t * t * (10.0 + t * (-15.0 + 6.0 * t));
  const double s1 = 30.0 * t * t * (1.0 - t) * (1.0 - t);
  const double s2 = 60.0 * t * (1.0 - t) * (1.0 - 2.0 * t);
  const double s3 = 60.0 - 360.0 * t + 360.0 * t * t;
  return {y0 + d * s, d * s1 / L, d * s2 / (L * L), d * s3 / (L * L * L)};
}

double out_ramp_start(const Geometry & g) { return g.entry_x + kRampStartOffset; }
double out_ramp_end(const Geometry & g) { return g.work_start; }
double back_ramp_start(const Geometry & g) { return g.work_end + kPostWorkOffset; }
double back_ramp_end(const Geometry & g) { return back_ramp_start(g) + kReturnRamp; }

Lateral lateral(const Geometry & g, double x) {
  if (x < back_ramp_start(g)) {
    return ramp(x, out_ramp_start(g), out_ramp_end(g), kOwnLaneY, kOpposingLaneY);
  }
  return ramp(x, back_ramp_start(g), back_ramp_end(g), kOpposingLaneY, kOwnLaneY);
}

// Exact |dkappa/ds| of y(x), with q = 1 + y'^2:
//   dkappa/ds = (y''' q - 3 y' y''^2) / q^3
double curvature_rate(const Geometry & g, double x) {
  const Lateral l = lateral(g, x);
  const double q = 1.0 + l.d1 * l.d1;
  return std::fabs(l.d3 * q - 3.0 * l.d1 * l.d2 * l.d2) / (q * q * q);
}

// Max |dkappa/ds| over [a, b]. The peak sits exactly at a ramp end, usually
// between grid points, and Act interpolates between points, so the whole
// neighbourhood of a point must respect the slew limit.
double max_curvature_rate(const Geometry & g, double a, double b) {
  constexpr int kSamples = 8;
  double m = 0.0;
  for (int k = 0; k <= kSamples; ++k) {
    m = std::max(m, curvature_rate(g, a + (b - a) * k / kSamples));
  }
  return m;
}

// Appends points from a (inclusive) to b (exclusive) with equal steps <= h.
void fill(std::vector<PlanPoint> & out, double a, double b, double h) {
  if (b - a <= kEps) {
    return;
  }
  const auto n = static_cast<std::size_t>(std::max(1.0, std::ceil((b - a) / h - kEps)));
  for (std::size_t i = 0; i < n; ++i) {
    PlanPoint p;
    p.x = a + static_cast<double>(i) * (b - a) / static_cast<double>(n);
    out.push_back(p);
  }
}

std::vector<double> segment_lengths(const std::vector<PlanPoint> & path) {
  std::vector<double> ds(path.size(), 0.0);
  for (std::size_t i = 0; i + 1 < path.size(); ++i) {
    ds[i] = std::hypot(path[i + 1].x - path[i].x, path[i + 1].y - path[i].y);
  }
  return ds;
}

// Signed curvature at every point (Menger, three-point circle); 0 at the ends.
std::vector<double> curvatures(const std::vector<PlanPoint> & path) {
  std::vector<double> k(path.size(), 0.0);
  for (std::size_t i = 1; i + 1 < path.size(); ++i) {
    const double ax = path[i].x - path[i - 1].x, ay = path[i].y - path[i - 1].y;
    const double bx = path[i + 1].x - path[i].x, by = path[i + 1].y - path[i].y;
    const double cx = path[i + 1].x - path[i - 1].x, cy = path[i + 1].y - path[i - 1].y;
    const double denom = std::hypot(ax, ay) * std::hypot(bx, by) * std::hypot(cx, cy);
    k[i] = denom > kEps ? 2.0 * (ax * by - ay * bx) / denom : 0.0;
  }
  return k;
}

// |dkappa/ds| at every point: the larger of the two one-sided differences, so a
// jump in curvature rate (ramp start/end) is not halved by averaging.
std::vector<double> curvature_rates(const std::vector<PlanPoint> & path,
                                    const std::vector<double> & ds) {
  const std::vector<double> k = curvatures(path);
  std::vector<double> kp(path.size(), 0.0);
  for (std::size_t i = 0; i < path.size(); ++i) {
    if (i > 0 && ds[i - 1] > kEps) {
      kp[i] = std::max(kp[i], std::fabs(k[i] - k[i - 1]) / ds[i - 1]);
    }
    if (i + 1 < path.size() && ds[i] > kEps) {
      kp[i] = std::max(kp[i], std::fabs(k[i + 1] - k[i]) / ds[i]);
    }
  }
  return kp;
}

// Index of the last point with x <= accel_x (0 if none).
std::size_t accel_index(const std::vector<PlanPoint> & path, double accel_x) {
  std::size_t i0 = 0;
  for (std::size_t i = 0; i < path.size(); ++i) {
    if (path[i].x <= accel_x + kEps) {
      i0 = i;
    }
  }
  return i0;
}

}  // namespace

bool operator==(const PathRequest & a, const PathRequest & b) {
  return a.geo.entry_x == b.geo.entry_x && a.geo.work_start == b.geo.work_start &&
         a.geo.work_end == b.geo.work_end && a.geo.exit_x == b.geo.exit_x &&
         a.geo.speed_limit == b.geo.speed_limit && a.stop_line == b.stop_line &&
         a.accel_x == b.accel_x && a.accel_v == b.accel_v && a.v_max == b.v_max;
}

const char * path_check_to_string(PathCheck c) {
  switch (c) {
    case PathCheck::OK:                 return "OK";
    case PathCheck::EMPTY:              return "EMPTY";
    case PathCheck::TOO_MANY_POINTS:    return "TOO_MANY_POINTS";
    case PathCheck::NONFINITE:          return "NONFINITE";
    case PathCheck::NEGATIVE_SPEED:     return "NEGATIVE_SPEED";
    case PathCheck::NOT_FORWARD:        return "NOT_FORWARD";
    case PathCheck::SPACING:            return "SPACING";
    case PathCheck::MISSING_STOP_POINT: return "MISSING_STOP_POINT";
    case PathCheck::BAD_GOAL:           return "BAD_GOAL";
    case PathCheck::OVERSPEED:          return "OVERSPEED";
    case PathCheck::LANE_OCCUPANCY:     return "LANE_OCCUPANCY";
    case PathCheck::CURVATURE:          return "CURVATURE";
    case PathCheck::STEER_SLEW:         return "STEER_SLEW";
    case PathCheck::DECEL:              return "DECEL";
    case PathCheck::ACCEL:              return "ACCEL";
    case PathCheck::HOLD_NOT_ZERO:      return "HOLD_NOT_ZERO";
  }
  return "UNKNOWN";
}

double stop_point_x(const Geometry & geo, const PathParams & p) {
  return geo.entry_x - kFrontOffset - p.stop_margin;
}

bool geometry_supported(const Geometry & g) {
  // Room for the dense stopping zone after the start (stop_margin <= 1 m).
  const bool approach_ok = g.entry_x - kFrontOffset - 1.0 - kDenseZone > kStartX;
  const bool out_ok = out_ramp_end(g) - out_ramp_start(g) >= kMinOutRamp;
  // Back in the own lane before the exit, and straight through the goal zone.
  const bool back_ok = back_ramp_end(g) <= g.exit_x &&
                       back_ramp_end(g) <= kGoalX - kDenseZone;
  return approach_ok && out_ok && back_ok;
}

double lateral_y(const Geometry & g, double x) {
  return lateral(g, x).y;
}

void build_path(const PathRequest & req, const PathParams & p, std::vector<PlanPoint> & out) {
  out.clear();
  const double stop_x = stop_point_x(req.geo, p);

  // 1. x grid: exact stop point and exact goal are always present.
  fill(out, kStartX, stop_x - kDenseZone, kGridSpacing);
  fill(out, std::max(kStartX, stop_x - kDenseZone), stop_x, kDenseSpacing);
  fill(out, stop_x, kGoalX - kDenseZone, kGridSpacing);
  fill(out, kGoalX - kDenseZone, kGoalX, kDenseSpacing);
  PlanPoint goal;
  goal.x = kGoalX;
  out.push_back(goal);

  // 2. Lateral bypass.
  for (auto & pt : out) {
    pt.y = lateral_y(req.geo, pt.x);
  }
  out.back().y = kGoalY;

  // 3. Speed caps: limit, steering slew, hold and goal.
  const std::size_t n = out.size();
  const std::vector<double> ds = segment_lengths(out);
  std::vector<double> cap(n, req.v_max);
  for (std::size_t i = 0; i < n; ++i) {
    // Steering rate ~ wheelbase * dkappa/ds * v must stay within the slew margin
    // (analytic, over the neighbourhood of the point).
    const double a = out[i > 0 ? i - 1 : i].x;
    const double b = out[i + 1 < n ? i + 1 : i].x;
    const double slew_term = kWheelbase * max_curvature_rate(req.geo, a, b);
    if (slew_term > kEps) {
      cap[i] = std::min(cap[i], p.slew_margin * kMaxSteerRate / slew_term);
    }
    if (req.stop_line && out[i].x >= stop_x - kEps) {
      cap[i] = 0.0;
    }
  }
  cap[n - 1] = 0.0;

  // 4. Forward pass from (accel_x, accel_v), then backward pass.
  std::vector<double> v(n, 0.0);
  const std::size_t i0 = accel_index(out, req.accel_x);
  for (std::size_t i = 0; i <= i0; ++i) {
    v[i] = std::min(cap[i], std::max(0.0, req.accel_v));
  }
  for (std::size_t i = i0; i + 1 < n; ++i) {
    v[i + 1] = std::min(cap[i + 1], std::sqrt(v[i] * v[i] + 2.0 * p.a_acc * ds[i]));
  }
  for (std::size_t i = n - 1; i-- > 0;) {
    v[i] = std::min(v[i], std::sqrt(v[i + 1] * v[i + 1] + 2.0 * p.a_dec * ds[i]));
  }
  for (std::size_t i = 0; i < n; ++i) {
    out[i].speed = v[i];
  }
}

PathCheck check_path(const std::vector<PlanPoint> & path, const PathRequest & req,
                     const PathParams & p) {
  constexpr double tol = 1e-6;
  if (path.empty()) {
    return PathCheck::EMPTY;
  }
  if (path.size() > kMaxPoints) {
    return PathCheck::TOO_MANY_POINTS;
  }
  for (const auto & pt : path) {
    if (!std::isfinite(pt.x) || !std::isfinite(pt.y) || !std::isfinite(pt.speed)) {
      return PathCheck::NONFINITE;
    }
    if (pt.speed < 0.0) {
      return PathCheck::NEGATIVE_SPEED;
    }
  }
  // First point at or behind the start pose; strictly forward afterwards.
  if (path.front().x > kStartX + tol) {
    return PathCheck::NOT_FORWARD;
  }
  const std::vector<double> ds = segment_lengths(path);
  for (std::size_t i = 0; i + 1 < path.size(); ++i) {
    if (path[i + 1].x <= path[i].x) {
      return PathCheck::NOT_FORWARD;
    }
    if (ds[i] > kMaxSpacing + tol) {
      return PathCheck::SPACING;
    }
  }
  const auto & last = path.back();
  if (std::fabs(last.x - kGoalX) > tol || std::fabs(last.y - kGoalY) > tol || last.speed != 0.0) {
    return PathCheck::BAD_GOAL;
  }
  const double v_allowed = std::min(req.v_max, req.geo.speed_limit);
  for (const auto & pt : path) {
    if (pt.speed > v_allowed + tol) {
      return PathCheck::OVERSPEED;
    }
  }
  if (req.stop_line) {
    const double stop_x = stop_point_x(req.geo, p);
    const bool found = std::any_of(path.begin(), path.end(), [stop_x](const PlanPoint & pt) {
      return std::fabs(pt.x - stop_x) < tol;
    });
    if (!found) {
      return PathCheck::MISSING_STOP_POINT;
    }
    for (const auto & pt : path) {
      if (pt.x >= stop_x - tol && pt.speed != 0.0) {
        return PathCheck::HOLD_NOT_ZERO;
      }
    }
  }
  // Opposing-lane occupancy only inside the entry..exit region (docs/INTERFACES.md).
  for (const auto & pt : path) {
    if (pt.y + kFrontOffset > 0.0) {
      if (pt.x + kFrontOffset < req.geo.entry_x || pt.x - kFrontOffset > req.geo.exit_x) {
        return PathCheck::LANE_OCCUPANCY;
      }
    }
  }
  const std::vector<double> k = curvatures(path);
  const std::vector<double> kp = curvature_rates(path, ds);
  for (std::size_t i = 0; i < path.size(); ++i) {
    if (std::atan(kWheelbase * std::fabs(k[i])) > kMaxSteer + tol) {
      return PathCheck::CURVATURE;
    }
    if (path[i].speed * kWheelbase * kp[i] > kMaxSteerRate + tol) {
      return PathCheck::STEER_SLEW;
    }
  }
  const std::size_t i0 = accel_index(path, req.accel_x);
  for (std::size_t i = 0; i + 1 < path.size(); ++i) {
    const double dv2 = path[i + 1].speed * path[i + 1].speed - path[i].speed * path[i].speed;
    if (-dv2 / (2.0 * ds[i]) > kMaxPlanDecel + tol) {
      return PathCheck::DECEL;
    }
    // Points behind the acceleration start are behind the vehicle; not checked.
    if (i >= i0 && dv2 / (2.0 * ds[i]) > kMaxAccel + tol) {
      return PathCheck::ACCEL;
    }
  }
  return PathCheck::OK;
}

double speed_at_x(const std::vector<PlanPoint> & path, double x) {
  for (std::size_t i = 0; i + 1 < path.size(); ++i) {
    if (x >= path[i].x && x <= path[i + 1].x) {
      const double t = (x - path[i].x) / (path[i + 1].x - path[i].x);
      return path[i].speed + t * (path[i + 1].speed - path[i].speed);
    }
  }
  return 0.0;
}

}  // namespace roadwork_student
