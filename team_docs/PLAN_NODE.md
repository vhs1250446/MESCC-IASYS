# Plan node

This document is the Plan node's own contract: how it decides when the vehicle
may enter the work zone, when it is committed, what it does when information is
missing, and how it builds the path. The wire formats it uses are defined in
[SENSE_PLAN_CONTRACT.md](SENSE_PLAN_CONTRACT.md) (input) and
[PLAN_ACT_CONTRACT.md](PLAN_ACT_CONTRACT.md) (output). Scope: D1 (S1–S2).

Code: `src/roadwork_student/src/plan_node.cpp` (wiring),
`plan_decision.cpp` (decisions) and `path_builder.cpp` (path), the last two as
the pure `plan_logic` library with gtests in `src/roadwork_student/test/`.

## Inputs and outputs

| Direction | Topic | Type | QoS | Rate |
|---|---|---|---|---|
| in | `/solution/scene` | `roadwork_solution_msgs/msg/Scene` | reliable, volatile, keep last 1 | 10 Hz |
| out | `/solution/plan` | `roadwork_solution_msgs/msg/Plan` | reliable, volatile, keep last 1 | 10 Hz |
| out | `/solution/plan_status` | `roadwork_solution_msgs/msg/PlanStatus` | reliable, volatile, keep last 10 | 10 Hz |
| out | `/solution/state` | `std_msgs/msg/String` (= `decision_state`) | reliable, volatile, keep last 10 | 10 Hz |
| out | `/solution/path` | `nav_msgs/msg/Path` | reliable, volatile, keep last 1 | 10 Hz, **debug only** |

A 10 Hz timer on the sim clock drives publishing, not the scene callback. Plan
therefore keeps publishing `MODE_STOP` when Sense goes silent. `/solution/path`
has an unbounded `poses[]` and is read only by RViz; no algorithm uses it.

## Decisions

The checks run in this order on every tick, and the first match wins.

| # | Condition | `mode` | `PlanStatus.state` | `reason_code` / `decision_state` |
|---|---|---|---|---|
| 1 | FAULT latched | FAULT | FAULT | 255 `FAULT` |
| 2 | No scene received | STOP | INIT | 1 `NO_SCENE` |
| 3 | Scene stamp > now + 1e-6 s | STOP | SAFE_STOP | 2 `SCENE_FUTURE` |
| 4 | now − scene stamp > 0.5 s | STOP | SAFE_STOP | 3 `SCENE_STALE` |
| 5 | `sense_status == SENSE_FAULT` or `ego_x` not finite | STOP | SAFE_STOP | 4 `SENSE_FAULT` |
| 6 | No valid beacon geometry cached | STOP | INIT | 5 `NO_GEOMETRY` |
| 7 | Built path breaks an invariant | FAULT (latched) | FAULT | 255 `FAULT` |
| 8 | Not committed, entry denied | TRACK + stop line at `entry_x` | HOLD | 6 `ENTRY_DENIED` + `deny_flags` |
| 9 | Not committed, entry permitted | TRACK | TRACKING | 0 / `ENTRY_GO` |
| 10 | Committed | TRACK | TRACKING | 0 / `COMMITTED`, `BYPASS`, `RETURN`, `TO_GOAL`, `GOAL` |

The row 10 labels come from `ego_x` and are for logs only.

**Bad external input never causes FAULT.** Rows 2–6 are recoverable stops. Row 7
means Plan's own code produced an invalid path from geometry it had already
accepted. The fault is latched until sim time goes backwards (episode reset),
which matches "unrecoverable" in the Plan–Act contract.

### Beacon geometry

Plan caches `entry_x`, `work_start`, `work_end`, `exit_x` and `speed_limit` from
a scene only when **all** of the following hold:

- `beacon_valid` is true, and Plan's own check also passes: the beacon stamp is
  not in the future, and `now ≤ beacon_stamp + 1.2 s`.
- All five values are finite.
- `entry_x < work_start < work_end < exit_x`.
- `0 < speed_limit ≤ 4.0` m/s.
- `pass_side == +1`.
- The path builder can serve the geometry: the outbound ramp is at least 12 m,
  the return ramp ends at or before `exit_x`, and the return ramp ends at least
  4 m before the goal.

A rejected beacon leaves the previous cache in place. **Once committed, the
cache is frozen**, so the path never changes shape during the crossing.

### Entry permission

Entry is permitted only when every condition below holds on the current tick.
Each failed condition sets its bit in `PlanStatus.deny_flags`:

| Condition | Bit |
|---|---|
| `panel_state == PANEL_GO` (UNKNOWN is treated like STOP) | `DENY_PANEL = 1` |
| Fresh, accepted beacon (as above) | `DENY_BEACON = 2` |
| Camera not stale | `DENY_CAMERA_STALE = 4` |
| LiDAR not stale | `DENY_LIDAR_STALE = 8` |
| `!obstacle_in_lane` | `DENY_LANE_BLOCKED = 16` |

Plan adds no hysteresis of its own, because Sense already requires 3 consistent
camera frames before it reports GO. Permission is withdrawn on the first tick
that any condition fails, and the stop line comes back. A stale radar
(`SENSE_DEGRADED`) does not deny entry in D1.

### Commitment

`committed` is latched as soon as the scene is valid and
`ego_x + 0.9 > entry_x`. It depends on **position only**, never on permission:

- If the front crosses while entry is denied, Plan logs an `ENTRY_VIOLATION`
  warning but still commits.
- A restarted Plan finds itself committed on its first valid scene.

The reason: a stop line behind the front makes Act command speed 0
(`command_limiter.cpp`), which would leave the vehicle stopped in the opposing
lane.

### After commitment (beacon-loss policy)

- Plan keeps tracking with the frozen geometry. A fresh beacon and the panel are
  no longer required (docs/INTERFACES.md: "blanket braking on a lost beacon is
  not required").
- A stale scene or `SENSE_FAULT` still causes `MODE_STOP`, because the evidence
  behind the plan can no longer be trusted.
- Known limitation: if Plan restarts mid-crossing **and** no valid beacon is
  available yet, row 6 stops the vehicle until one arrives.

## Path

The path depends only on (geometry, stop line on/off, acceleration start, v_max).
Plan rebuilds it only when one of these changes. Every build is checked
(`check_path`) before it is published.

**Grid**

- 0.4 m spacing in x from the start (5.0, −1.75). The arc length stays ≤ 0.5 m
  on the ramps (max 0.43 m).
- 0.2 m spacing over the 4 m before the stop point and before the goal.
- Always contains the exact stop point `entry_x − 0.9 − stop_margin` (23.8 m) and
  the exact goal (80.2, −1.75).
- 209 points (bound 250).

**Lateral profile** (quintic smooth steps, so the path is C2 where the ramps join):

| Section | From | To | y |
|---|---|---|---|
| own lane | start | `entry_x + 1` | −1.75 |
| outbound ramp | `entry_x + 1` | `work_start` | −1.75 → +1.75 |
| bypass | `work_start` | `work_end + 2` | +1.75 |
| return ramp (16 m) | `work_end + 2` | `work_end + 18` | +1.75 → −1.75 |
| own lane | | goal | −1.75 |

The outbound ramp is 16 m at the nominal geometry, 14 m at `work_shift = −2`
and 18 m at +2. Opposing-lane occupancy (y + 0.9 > 0) is limited to
x ∈ [31.8, 61.0] m at the nominal geometry. Simulated clearance to the works is
≥ 1.64 m.

**Speed profile**

- **Cap:** each point is capped at `min(speed_limit, v_cruise)`.
- **Steering slew cap:** `v · 2.4 · max|dκ/ds| ≤ slew_margin · 0.6 rad/s`. Here
  dκ/ds is the exact quintic derivative, maximised over each point's
  neighbourhood. Its peak sits exactly at a ramp end, which is usually between
  two grid points.
  - The nominal 16 m ramps are not slowed: the cap is 3.9 m/s and the peak
    steering rate at 3.8 m/s is 0.47 rad/s.
  - The 14 m ramp at shift −2 is slowed to 2.6 m/s at its ends.
- **Hold:** while the stop line is on, the speed is 0 at and after the stop point.
- **Goal:** the speed is 0 at the goal.
- **Passes:** a forward pass at `a_acc` starts from the acceleration start point
  `(accel_x, accel_v)`, then a backward pass runs at `a_dec ≤ 2.0 m/s²`.
- **Acceleration start:** initially (5.0, 0). When the stop line is released, it
  becomes (`ego_x`, the hold profile's speed at `ego_x`). That is 0 when the
  vehicle waited at the line, and the approach speed when GO arrives while it is
  still rolling. Scene has no ego speed, so Plan uses the speed it had commanded
  at that point.
- **Low speed:** leaving a standstill, the first 0.4 m step jumps to about
  1.06 m/s. Act interpolates speed along the path and previews it 0.5 m ahead,
  which is also what lets it start from a 0 m/s point.

**Checks in `check_path`** (any failure triggers row 7):

- size ≤ 250
- all values finite and speeds non-negative
- strictly forward, starting at or behind 5.0
- spacing ≤ 0.5 m
- exact goal with speed 0
- speed ≤ limit
- stop point present, with speed 0 at and after it, while held
- lane occupancy only inside the entry..exit region
- `atan(2.4·|κ|) ≤ 0.45`
- `v·2.4·|dκ/ds| ≤ 0.6`, using an independent three-point discrete estimate
- deceleration ≤ 2.0 m/s²
- acceleration ≤ 1.5 m/s² from the acceleration start onwards

`scripts/generate_plan_test_data.py` implements the same model, and its
fixtures match `build_path` to within their rounding (5e-4).

## Parameters

Only tuning values are ROS parameters (`config/plan.yaml`). The node checks the
bounds at startup.

| Parameter | Value | Bounds | Source |
|---|---|---|---|
| `plan_period` | 0.1 s | > 0 | PLAN_ACT_CONTRACT (10 Hz) |
| `plan_validity` | 0.3 s | > 0 | PLAN_ACT_CONTRACT |
| `scene_timeout` | 0.5 s | > 0 | SENSE_PLAN_CONTRACT |
| `future_tolerance` | 1e-6 s | ≥ 0 | docs/INTERFACES.md |
| `v_cruise` | 3.8 m/s | (0, 4.0] | below the 4.05 m/s violation threshold and Act's 3.9 m/s cap |
| `a_acc` | 1.4 m/s² | (0, 1.5] | vehicle limit 1.5 |
| `a_dec` | 1.8 m/s² | (0, 2.0] | PLAN_ACT_CONTRACT planning deceleration |
| `stop_margin` | 0.3 m | [0, 1] | front stops at 24.7 m. Act's backstop uses 0.2 m, so Plan's stop point always comes first (intentional). |
| `slew_margin` | 0.8 | (0, 1] | headroom for the tracking controller |

Contract constants are `constexpr` in `path_builder.hpp` and
`plan_decision.hpp`, each with its source: vehicle geometry and limits, beacon
validity 1.2 s, default speed limit 4.0 m/s, goal, grid and ramp layout.

## Verification

```bash
colcon build --packages-select roadwork_solution_msgs roadwork_student roadwork_test_tools
colcon test --packages-select roadwork_student && colcon test-result --verbose
```

**Unit tests:** 36 gtests (16 path, 20 decision) cover every row of the decision table, every
`DENY_*` bit, beacon rejection, the commitment edge cases (restart at x = 40,
crossing while denied, front exactly at the line) and the path invariants for
`work_shift ∈ {−2, −1, 0, 1, 2}`.

**Integration tests.** Until Sense exists, `roadwork_test_tools/scene_stub`
publishes a scripted `Scene` built from odometry. It is a **test tool only** and
reads no camera, LiDAR or beacon.

One command starts the simulator (with `student:=false`), `scene_stub`,
`plan_node` and `act_node`, and loads `config/plan.yaml` and `config/act.yaml`:

```bash
ros2 launch roadwork_test_tools stub_pipeline.launch.py scenario:=2 go_after:=10.0
ros2 launch roadwork_test_tools stub_pipeline.launch.py scenario:=1 work_shift:=-2.0 rviz:=false
```

All `challenge.launch.py` arguments are passed through, plus `go_after`, the sim
time in seconds at which the scripted panel turns GO. This is a test/demo launch
only. The graded configuration is `roadwork_sim/challenge.launch.py` with
`student:=true`, running the real Sense node.

Results with the stub, seed 1, 2026-11-12. All runs passed with no collision,
off-road, entry, lane or speed violation, and a maximum speed of 3.8 m/s.

| Run | Time | Min clearance |
|---|---|---|
| S1 | 24.5 s | 1.65 m |
| S2 (GO at 10 s, held at 23.80 m) | 27.35 s | 1.65 m |
| S1, `work_shift` −2 | 24.95 s | 1.64 m |
| S1, `work_shift` +2 | 24.45 s | 1.64 m |
| S1, scene stopped at x ≈ 39.5 and resumed 4 s later | 32.4 s | 1.64 m |

In the interrupted run, Plan reported `SCENE_STALE` with `committed = true`, the
vehicle stopped at x ≈ 47, and it resumed and finished once the scene returned.

`rejected_commands = 43` in these runs comes from starting the nodes about 2 s
after the simulator (startup), not from Plan.

## Deferred to D2

Radar gap acceptance (S3) and obstacle braking during traversal (S5) need new
`Scene` fields, with Sense applying the ego-motion correction. They will act
through the existing outputs (stop line, `MODE_STOP`, lower path speeds), so
`Plan` does not change. Each one adds a `DENY_*` bit and/or a reason code to
`PlanStatus`.
