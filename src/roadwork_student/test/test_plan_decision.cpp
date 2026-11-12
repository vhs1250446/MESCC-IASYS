// Decision-table tests for plan_decision (team_docs/PLAN_NODE.md "Decisions").
#include <gtest/gtest.h>

#include <cmath>
#include <cstring>

#include "roadwork_solution_msgs/msg/plan.hpp"
#include "roadwork_solution_msgs/msg/plan_status.hpp"
#include "roadwork_student/plan_decision.hpp"

using namespace roadwork_student;
using Plan = roadwork_solution_msgs::msg::Plan;
using PlanStatus = roadwork_solution_msgs::msg::PlanStatus;

namespace {

const DecisionParams kP{0.5, 1e-6};
constexpr double kNow = 20.0;

builtin_interfaces::msg::Time stamp(double t) {
  builtin_interfaces::msg::Time s;
  s.sec = static_cast<int32_t>(t);
  s.nanosec = static_cast<uint32_t>((t - s.sec) * 1e9);
  return s;
}

// Fresh, fully permitted scene with the vehicle at rest before the entry line.
Scene good_scene(double ego_x = 10.0) {
  Scene s;
  s.header.stamp = stamp(kNow - 0.05);
  s.header.frame_id = "map";
  s.seq = 7;
  s.beacon_stamp = stamp(kNow - 0.3);
  s.beacon_valid = true;
  s.entry_x = 25.0;
  s.work_start = 42.0;
  s.work_end = 49.0;
  s.exit_x = 68.0;
  s.speed_limit = 4.0;
  s.pass_side = 1;
  s.panel_state = Scene::PANEL_GO;
  s.obstacle_in_lane = false;
  s.sense_status = Scene::SENSE_OK;
  s.stale_flags = 0;
  s.ego_x = ego_x;
  return s;
}

}  // namespace

// ── Rows 1-6 ────────────────────────────────────────────────────────────────

TEST(Decide, NoScene) {
  PlanMemory m;
  const Decision d = decide(nullptr, kNow, kP, m);
  EXPECT_EQ(d.mode, Plan::MODE_STOP);
  EXPECT_EQ(d.state, PlanStatus::STATE_INIT);
  EXPECT_EQ(d.reason, PlanStatus::REASON_NO_SCENE);
}

TEST(Decide, FutureScene) {
  PlanMemory m;
  Scene s = good_scene();
  s.header.stamp = stamp(kNow + 0.01);
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_EQ(d.mode, Plan::MODE_STOP);
  EXPECT_EQ(d.reason, PlanStatus::REASON_SCENE_FUTURE);
}

TEST(Decide, StaleScene) {
  PlanMemory m;
  Scene s = good_scene();
  s.header.stamp = stamp(kNow - 0.6);
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_EQ(d.mode, Plan::MODE_STOP);
  EXPECT_EQ(d.state, PlanStatus::STATE_SAFE_STOP);
  EXPECT_EQ(d.reason, PlanStatus::REASON_SCENE_STALE);
  EXPECT_STREQ(d.label, "SCENE_STALE");
}

TEST(Decide, SenseFault) {
  PlanMemory m;
  Scene s = good_scene();
  s.sense_status = Scene::SENSE_FAULT;
  EXPECT_EQ(decide(&s, kNow, kP, m).reason, PlanStatus::REASON_SENSE_FAULT);
}

TEST(Decide, NoGeometryWithoutValidBeacon) {
  PlanMemory m;
  Scene s = good_scene();
  s.beacon_valid = false;
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_EQ(d.mode, Plan::MODE_STOP);
  EXPECT_EQ(d.reason, PlanStatus::REASON_NO_GEOMETRY);
  EXPECT_FALSE(m.has_geometry);
}

TEST(Decide, LatchedFaultWins) {
  PlanMemory m;
  m.fault_latched = true;
  Scene s = good_scene();
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_EQ(d.mode, Plan::MODE_FAULT);
  EXPECT_EQ(d.state, PlanStatus::STATE_FAULT);
  EXPECT_EQ(d.reason, PlanStatus::REASON_FAULT);
}

// ── Beacon validation ───────────────────────────────────────────────────────

TEST(Beacon, InvalidGeometryIsRejected) {
  const auto rejected = [](Scene s) {
    Geometry g{};
    return !fresh_geometry(s, kNow, kP, g);
  };
  Scene s = good_scene();
  s.pass_side = -1;
  EXPECT_TRUE(rejected(s));
  s = good_scene();
  s.work_start = 50.0;  // not ordered
  EXPECT_TRUE(rejected(s));
  s = good_scene();
  s.exit_x = std::nan("");
  EXPECT_TRUE(rejected(s));
  s = good_scene();
  s.speed_limit = 5.0;
  EXPECT_TRUE(rejected(s));
  s = good_scene();
  s.speed_limit = 0.0;
  EXPECT_TRUE(rejected(s));
  s = good_scene();
  s.beacon_stamp = stamp(kNow - 1.3);  // older than valid_for even if Sense says valid
  EXPECT_TRUE(rejected(s));
  EXPECT_FALSE(rejected(good_scene()));
}

TEST(Beacon, RejectedBeaconKeepsPreviousCache) {
  PlanMemory m;
  Scene s = good_scene();
  decide(&s, kNow, kP, m);
  ASSERT_TRUE(m.has_geometry);
  s.work_start = 50.0;
  decide(&s, kNow, kP, m);
  EXPECT_DOUBLE_EQ(m.geo.work_start, 42.0);
}

// ── Rows 8-10: permission and commitment ───────────────────────────────────

TEST(Entry, PermittedWhenEverythingIsGood) {
  PlanMemory m;
  Scene s = good_scene();
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_EQ(d.mode, Plan::MODE_TRACK);
  EXPECT_EQ(d.state, PlanStatus::STATE_TRACKING);
  EXPECT_FALSE(d.stop_line);
  EXPECT_STREQ(d.label, "ENTRY_GO");
}

TEST(Entry, EachConditionDeniesWithItsFlag) {
  struct Case { void (*mutate)(Scene &); uint8_t flag; };
  const Case cases[] = {
    {[](Scene & s) { s.panel_state = Scene::PANEL_STOP; }, PlanStatus::DENY_PANEL},
    {[](Scene & s) { s.panel_state = Scene::PANEL_UNKNOWN; }, PlanStatus::DENY_PANEL},
    {[](Scene & s) { s.beacon_stamp = stamp(kNow - 1.3); }, PlanStatus::DENY_BEACON},
    {[](Scene & s) { s.stale_flags = Scene::STALE_CAMERA; }, PlanStatus::DENY_CAMERA_STALE},
    {[](Scene & s) { s.stale_flags = Scene::STALE_LIDAR; }, PlanStatus::DENY_LIDAR_STALE},
    {[](Scene & s) { s.obstacle_in_lane = true; }, PlanStatus::DENY_LANE_BLOCKED},
  };
  for (const auto & c : cases) {
    PlanMemory m;
    Scene ok = good_scene();
    decide(&ok, kNow, kP, m);  // cache geometry first
    Scene s = good_scene();
    c.mutate(s);
    const Decision d = decide(&s, kNow, kP, m);
    EXPECT_EQ(d.mode, Plan::MODE_TRACK);
    EXPECT_EQ(d.state, PlanStatus::STATE_HOLD);
    EXPECT_EQ(d.reason, PlanStatus::REASON_ENTRY_DENIED);
    EXPECT_TRUE(d.stop_line);
    EXPECT_EQ(d.deny_flags, c.flag);
  }
}

TEST(Entry, RadarStaleDoesNotDenyInD1) {
  PlanMemory m;
  Scene s = good_scene();
  s.stale_flags = Scene::STALE_RADAR;
  s.sense_status = Scene::SENSE_DEGRADED;
  EXPECT_FALSE(decide(&s, kNow, kP, m).stop_line);
}

TEST(Entry, PermissionLostBeforeLineRestoresStopLine) {
  PlanMemory m;
  Scene s = good_scene(20.0);
  EXPECT_FALSE(decide(&s, kNow, kP, m).stop_line);
  s.panel_state = Scene::PANEL_STOP;
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_TRUE(d.stop_line);
  EXPECT_FALSE(m.committed);
}

TEST(Commit, LatchesWhenFrontCrossesEntry) {
  PlanMemory m;
  Scene s = good_scene(24.2);  // front 25.1
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_TRUE(m.committed);
  EXPECT_FALSE(d.entry_violation);
  EXPECT_STREQ(d.label, "COMMITTED");
}

TEST(Commit, FrontAtLineIsNotCommitted) {
  PlanMemory m;
  Scene s = good_scene(24.1);  // front exactly 25.0: not past it
  decide(&s, kNow, kP, m);
  EXPECT_FALSE(m.committed);
}

TEST(Commit, PermissionLostAfterCommitKeepsTracking) {
  PlanMemory m;
  Scene s = good_scene(30.0);
  decide(&s, kNow, kP, m);
  s.panel_state = Scene::PANEL_UNKNOWN;
  s.beacon_valid = false;
  s.ego_x = 35.0;
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_EQ(d.mode, Plan::MODE_TRACK);
  EXPECT_FALSE(d.stop_line);
  EXPECT_EQ(d.deny_flags, 0);
}

TEST(Commit, CrossingWhileDeniedCommitsAndFlagsViolation) {
  PlanMemory m;
  Scene ok = good_scene(20.0);
  decide(&ok, kNow, kP, m);
  Scene s = good_scene(24.5);
  s.panel_state = Scene::PANEL_STOP;
  const Decision d = decide(&s, kNow, kP, m);
  EXPECT_TRUE(m.committed);
  EXPECT_TRUE(d.entry_violation);
  EXPECT_FALSE(d.stop_line);  // never a stop line behind the front
}

TEST(Commit, RestartMidCrossingCommitsImmediately) {
  PlanMemory fresh;
  Scene s = good_scene(40.0);
  s.panel_state = Scene::PANEL_UNKNOWN;  // whatever the panel shows now
  const Decision d = decide(&s, kNow, kP, fresh);
  EXPECT_TRUE(fresh.committed);
  EXPECT_FALSE(d.stop_line);
  EXPECT_EQ(d.mode, Plan::MODE_TRACK);
}

TEST(Commit, GeometryFrozenAfterCommit) {
  PlanMemory m;
  Scene s = good_scene(30.0);
  decide(&s, kNow, kP, m);
  s.work_start = 43.0;
  s.work_end = 50.0;
  s.exit_x = 69.0;
  decide(&s, kNow, kP, m);
  EXPECT_DOUBLE_EQ(m.geo.work_start, 42.0);
}

TEST(Commit, StaleSceneStillStopsAfterCommit) {
  PlanMemory m;
  Scene s = good_scene(30.0);
  decide(&s, kNow, kP, m);
  s.header.stamp = stamp(kNow - 0.7);
  EXPECT_EQ(decide(&s, kNow, kP, m).mode, Plan::MODE_STOP);
  EXPECT_TRUE(m.committed);
}

// ── Strings ─────────────────────────────────────────────────────────────────

TEST(Strings, AllLabelsFitStringBound) {
  for (uint8_t r : {PlanStatus::REASON_NONE, PlanStatus::REASON_NO_SCENE,
                    PlanStatus::REASON_SCENE_FUTURE, PlanStatus::REASON_SCENE_STALE,
                    PlanStatus::REASON_SENSE_FAULT, PlanStatus::REASON_NO_GEOMETRY,
                    PlanStatus::REASON_ENTRY_DENIED, PlanStatus::REASON_FAULT}) {
    EXPECT_LE(std::strlen(plan_reason_to_string(r)), 32u);
  }
  for (const char * l : {"HOLD_AT_ENTRY", "ENTRY_GO", "COMMITTED", "BYPASS", "RETURN",
                         "TO_GOAL", "GOAL", "NO_SCENE", "NO_GEOMETRY", "FAULT"}) {
    EXPECT_LE(std::strlen(l), 32u);
  }
}
