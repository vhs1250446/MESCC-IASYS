// Invariant tests for path_builder (team_docs/PLAN_NODE.md "Path").
#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <vector>

#include "roadwork_student/path_builder.hpp"

using namespace roadwork_student;
using namespace roadwork_student::path_const;

namespace {

const PathParams kParams{3.8, 1.4, 1.8, 0.3, 0.8};

Geometry nominal(double shift = 0.0) {
  return Geometry{25.0, 42.0 + shift, 49.0 + shift, 68.0 + shift, 4.0};
}

PathRequest request(const Geometry & g, bool stop_line, double ax = kStartX, double av = 0.0) {
  return PathRequest{g, stop_line, ax, av, std::min(g.speed_limit, kParams.v_cruise)};
}

std::vector<PlanPoint> build(const PathRequest & r) {
  std::vector<PlanPoint> out;
  build_path(r, kParams, out);
  return out;
}

double max_speed(const std::vector<PlanPoint> & p) {
  double v = 0.0;
  for (const auto & pt : p) {
    v = std::max(v, pt.speed);
  }
  return v;
}

}  // namespace

class ShiftTest : public ::testing::TestWithParam<double> {};

TEST_P(ShiftTest, AllInvariantsHoldWithAndWithoutStopLine) {
  const Geometry g = nominal(GetParam());
  ASSERT_TRUE(geometry_supported(g));
  for (bool stop : {false, true}) {
    const PathRequest r = request(g, stop);
    const auto path = build(r);
    EXPECT_EQ(check_path(path, r, kParams), PathCheck::OK)
        << "shift=" << GetParam() << " stop=" << stop << " -> "
        << path_check_to_string(check_path(path, r, kParams));
    EXPECT_LE(path.size(), kMaxPoints);
  }
}

INSTANTIATE_TEST_SUITE_P(WorkShift, ShiftTest, ::testing::Values(-2.0, -1.0, 0.0, 1.0, 2.0));

TEST(PathBuilder, ExactBoundaryPoints) {
  const PathRequest r = request(nominal(), true);
  const auto path = build(r);
  bool found_stop = false;
  for (const auto & pt : path) {
    if (std::fabs(pt.x - 23.8) < 1e-9) {
      found_stop = true;
      EXPECT_DOUBLE_EQ(pt.speed, 0.0);
      EXPECT_DOUBLE_EQ(pt.y, kOwnLaneY);
    }
  }
  EXPECT_TRUE(found_stop);
  EXPECT_DOUBLE_EQ(path.front().x, kStartX);
  EXPECT_DOUBLE_EQ(path.back().x, kGoalX);
  EXPECT_DOUBLE_EQ(path.back().y, kGoalY);
  EXPECT_DOUBLE_EQ(path.back().speed, 0.0);
}

TEST(PathBuilder, HoldStopsFrontBeforeEntryLine) {
  const auto path = build(request(nominal(), true));
  for (const auto & pt : path) {
    if (pt.speed > 0.0) {
      EXPECT_LT(pt.x + kFrontOffset, 25.0);
    }
  }
}

TEST(PathBuilder, ReachesCruiseOnNominalPath) {
  const auto path = build(request(nominal(), false));
  EXPECT_NEAR(max_speed(path), 3.8, 1e-9);
}

TEST(PathBuilder, BypassIsInOpposingLaneAlongTheWorks) {
  const Geometry g = nominal();
  for (double x = g.work_start; x <= g.work_end; x += 0.25) {
    EXPECT_DOUBLE_EQ(lateral_y(g, x), kOpposingLaneY) << "x=" << x;
  }
  // Own lane up to the ramp start and from the end of the return ramp.
  EXPECT_DOUBLE_EQ(lateral_y(g, g.entry_x + kRampStartOffset), kOwnLaneY);
  EXPECT_DOUBLE_EQ(lateral_y(g, g.work_end + kPostWorkOffset + kReturnRamp), kOwnLaneY);
}

TEST(PathBuilder, ShortRampIsSlowedBySlewCap) {
  // work_shift = -2: 14 m outbound ramp. dkappa/ds peaks at the ramp ends, where
  // cruise speed would exceed the 0.6 rad/s slew limit, so the profile dips there.
  const Geometry g = nominal(-2.0);
  const PathRequest r = request(g, false);
  const auto path = build(r);
  EXPECT_EQ(check_path(path, r, kParams), PathCheck::OK);
  const double ramp_start = g.entry_x + kRampStartOffset;
  EXPECT_LT(speed_at_x(path, ramp_start), 3.0);
  EXPECT_GT(speed_at_x(path, ramp_start), 1.5);
  // The nominal 16 m ramp is not slowed.
  const auto nominal_path = build(request(nominal(), false));
  EXPECT_NEAR(speed_at_x(nominal_path, ramp_start), 3.8, 1e-6);
}

TEST(PathBuilder, ReleaseFromStandstillAtStopPoint) {
  const Geometry g = nominal();
  const PathRequest r = request(g, false, 23.8, 0.0);
  const auto path = build(r);
  EXPECT_EQ(check_path(path, r, kParams), PathCheck::OK);
  EXPECT_NEAR(speed_at_x(path, 23.8), 0.0, 1e-9);
  // Act previews 0.5 m ahead; the profile must rise there so the vehicle starts.
  EXPECT_GT(speed_at_x(path, 24.3), 0.5);
}

TEST(PathBuilder, ReleaseFromStartDoesNotHoldAtZero) {
  // GO arriving at the start: everything up to the entry line must be drivable.
  const auto path = build(request(nominal(), false, kStartX, 0.0));
  EXPECT_GT(speed_at_x(path, 10.0), 2.0);
  EXPECT_GT(speed_at_x(path, 23.8), 3.0);
}

TEST(PathBuilder, ReleaseWhileRollingKeepsSpeed) {
  const Geometry g = nominal();
  const auto hold = build(request(g, true));
  const double v_at_15 = speed_at_x(hold, 15.0);
  ASSERT_GT(v_at_15, 2.0);
  const PathRequest r = request(g, false, 15.0, v_at_15);
  const auto path = build(r);
  EXPECT_EQ(check_path(path, r, kParams), PathCheck::OK);
  EXPECT_GE(speed_at_x(path, 15.4), v_at_15 - 1e-6);
}

TEST(PathBuilder, ReducedSpeedLimitIsRespected) {
  Geometry g = nominal();
  g.speed_limit = 3.0;
  const PathRequest r = request(g, false);
  const auto path = build(r);
  EXPECT_EQ(check_path(path, r, kParams), PathCheck::OK);
  EXPECT_LE(max_speed(path), 3.0 + 1e-9);
}

TEST(PathBuilder, GeometrySupport) {
  EXPECT_TRUE(geometry_supported(nominal()));
  Geometry tight = nominal();
  tight.work_start = 36.0;  // 10 m outbound ramp
  EXPECT_FALSE(geometry_supported(tight));
  Geometry late_exit = nominal();
  late_exit.exit_x = 60.0;  // return ramp would end beyond the exit
  EXPECT_FALSE(geometry_supported(late_exit));
}

TEST(PathCheck, DetectsCorruptedPaths) {
  const PathRequest r = request(nominal(), true);
  const auto good = build(r);
  ASSERT_EQ(check_path(good, r, kParams), PathCheck::OK);

  auto p = good;
  p[10].x = std::nan("");
  EXPECT_EQ(check_path(p, r, kParams), PathCheck::NONFINITE);

  p = good;
  p.back().speed = 0.5;
  EXPECT_EQ(check_path(p, r, kParams), PathCheck::BAD_GOAL);

  p = good;
  p[20].speed = 5.0;
  EXPECT_EQ(check_path(p, r, kParams), PathCheck::OVERSPEED);

  p = good;
  for (auto & pt : p) {
    if (pt.x > 23.8 && pt.x < 30.0) {
      pt.speed = 1.0;
    }
  }
  EXPECT_EQ(check_path(p, r, kParams), PathCheck::HOLD_NOT_ZERO);

  p = good;
  for (auto & pt : p) {
    if (pt.x < 20.0) {
      pt.y = 0.0;  // opposing-lane occupancy before the entry region
    }
  }
  EXPECT_NE(check_path(p, r, kParams), PathCheck::OK);

  p = good;
  p.resize(kMaxPoints + 1, good.back());
  EXPECT_EQ(check_path(p, r, kParams), PathCheck::TOO_MANY_POINTS);
}
