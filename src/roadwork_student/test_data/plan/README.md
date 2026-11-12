# PLAN Dummy Test Data for ACT Node

This directory contains dummy test data representing **exclusively what the PLAN node outputs** to the ACT node, strictly adhering to the Plan-Act contract defined in [`team_docs/PLAN_ACT_CONTRACT.md`](file:///home/v/t/roadwork/MESCC-IASYS/team_docs/PLAN_ACT_CONTRACT.md), [`team_docs/README.md`](file:///home/v/t/roadwork/MESCC-IASYS/team_docs/README.md), and [`AGENTS.md`](file:///home/v/t/roadwork/MESCC-IASYS/AGENTS.md).

Both **YAML** and **JSON** formats are provided for each scenario:
- `yaml/`: Ideal for direct publication via `ros2 topic pub --stdin` or `yaml-cpp`.
- `json/`: Ideal for programmatic parsing in C++ or Python unit tests.

---

## 1. Plan-Act Contract Specification

The ACT node subscribes to only one topic published by the PLAN node:

- **Topic:** `/solution/plan`
- **Type:** `roadwork_solution_msgs/msg/Plan`
- **QoS:** Reliable, Volatile, Depth 1 (keep last 1)
- **Publication Rate:** 10 Hz

### Message Structure:
```text
std_msgs/Header header              # stamp: sim time of computation, frame_id: "map"
builtin_interfaces/Time scene_stamp # stamp of the Scene this plan was built from (max age 0.5 s)
builtin_interfaces/Time valid_until # stamp + 0.3 s; Act must not execute after this time
uint32 seq                          # incrementing sequence counter

uint8 MODE_STOP  = 0                # brake to standstill now; ignore path
uint8 MODE_TRACK = 1                # track path under speed profile and constraints
uint8 MODE_FAULT = 255              # unrecoverable fault; emergency stop
uint8 mode

PlanPoint[<=250] path               # bounded waypoint array (<= 250 points, 209 points generated)
float64 speed_limit                 # m/s (nominal 4.0 or beacon value, e.g. 3.0)

bool has_stop_line                  # true when waiting before entry line
float64 stop_line_x                 # m (e.g. 25.0 m)

string<=32 decision_state           # Plan state name for logging/traceability
```

### Waypoint Structure (`PlanPoint.msg`):
```text
float64 x                           # m, map frame, rear-axle reference
float64 y                           # m, map frame
float64 speed                       # m/s, target speed when rear axle is at (x, y)
```

---

## 2. Test Scenarios Overview

| File Base Name | Mode | Stop Line? | Speed Limit | Objective / Test Purpose | Expected Act State | Expected Reason Code | Expected Reason String |
|---|:---:|:---:|:---:|---|---|:---:|---|
| `01_nominal_full_course` | `MODE_TRACK` (1) | No | 4.0 m/s | Nominal full-course tracking from $x=5.0\text{ m}$ to $x=80.2\text{ m}$ bypassing work zone via opposing lane. | `STATE_TRACKING` (1) | 0 | `NONE` |
| `02_nominal_reduced_speed` | `MODE_TRACK` (1) | No | 3.0 m/s | Tracking under lower beacon speed limit (3.0 m/s). Verify Act limits speed to $\le 3.0\text{ m/s}$. | `STATE_TRACKING` (1) | 0 | `NONE` |
| `03_stop_line_hold` | `MODE_TRACK` (1) | Yes ($x=25.0$) | 4.0 m/s | Holding before work zone. Dense deceleration to exact stopping waypoint at $x=23.8\text{ m}$, speed 0 beyond. | `STATE_TRACKING` (1) | 0 | `NONE` |
| `04_stop_line_cleared` | `MODE_TRACK` (1) | No | 4.0 m/s | Resuming motion after panel turns GO. Speed ramps up from $x=23.8\text{ m}$ into work zone. Higher `seq`. | `STATE_TRACKING` (1) | 0 | `NONE` |
| `05_mode_stop` | `MODE_STOP` (0) | No | 4.0 m/s | Plan commands immediate brake to standstill. Act must ignore path and command speed 0. | `STATE_SAFE_STOP` (2) | 8 | `PLAN_MODE_STOP` |
| `06_mode_fault` | `MODE_FAULT` (255) | No | 4.0 m/s | Unrecoverable planner fault. Act must trigger emergency stop. | `STATE_FAULT` (255) | 255 | `FAULT` |
| `07_expired_valid_until` | `MODE_TRACK` (1) | No | 4.0 m/s | `valid_until` is in the past / older than current time. Act must safe-stop. | `STATE_SAFE_STOP` (2) | 2 | `PLAN_EXPIRED` |
| `08_future_header_stamp` | `MODE_TRACK` (1) | No | 4.0 m/s | Plan header stamp is $> 1\mu\text{s}$ ahead of clock. Act must safe-stop. | `STATE_SAFE_STOP` (2) | 3 | `PLAN_FUTURE` |
| `09_stale_scene_stamp` | `MODE_TRACK` (1) | No | 4.0 m/s | Plan's underlying scene stamp is $> 0.5\text{ s}$ old. Act must safe-stop. | `STATE_SAFE_STOP` (2) | 5 | `SCENE_STALE` |
| `10_malformed_empty_path` | `MODE_TRACK` (1) | No | 4.0 m/s | `MODE_TRACK` provided with an empty waypoint array (violates Rule 1). Act must safe-stop. | `STATE_SAFE_STOP` (2) | 4 | `PLAN_MALFORMED` |
| `11_malformed_nan_coordinates` | `MODE_TRACK` (1) | No | 4.0 m/s | Path contains a point with `NaN` coordinate. Act must sanitize and safe-stop without crashing. | `STATE_SAFE_STOP` (2) | 4 | `PLAN_MALFORMED` |
| `12_malformed_nan_speed` | `MODE_TRACK` (1) | No | 4.0 m/s | Path contains a point with `NaN` speed. Act must sanitize and safe-stop without crashing. | `STATE_SAFE_STOP` (2) | 4 | `PLAN_MALFORMED` |
| `13_recovery_new_seq` | `MODE_TRACK` (1) | No | 4.0 m/s | Fresh plan with strictly incremented sequence (`seq=100`) to test recovery from `WAITING_NEW_SEQ`. | `STATE_TRACKING` (1) | 0 | `NONE` |
| `14_edge_speed_limit_violation` | `MODE_TRACK` (1) | No | 4.0 m/s | Plan path contains points requesting 5.5 m/s. Act guard must clamp commands to $\le 3.9\text{ m/s}$. | `STATE_TRACKING` (1) | 0 | `NONE` (`LIMIT_SPEED` flag set) |

---

## 3. Kinematic and Geometric Guarantees

All generated paths strictly enforce the contract invariants:

1. **Deterministic Bounded Size:**
   All paths contain exactly **209 waypoints**, satisfying the bounded IDL condition `PlanPoint[<=250] path` with zero dynamic reallocation.
2. **Dense Stopping Zones & Quantization Safety:**
   - Approaching stop line: $\Delta x = 0.2\text{ m}$ between $x = 19.8\text{ m}$ and $x = 23.8\text{ m}$.
   - Approaching goal: $\Delta x = 0.2\text{ m}$ between $x = 76.2\text{ m}$ and $x = 80.2\text{ m}$.
   - Nominal spacing: $\Delta x = 0.4\text{ m}$, so the arc length between points stays $\le 0.5\text{ m}$ on the lane-change ramps (max 0.432 m).
   - Leaving a standstill (at 5.0 or 23.8 m), the first 0.4 m step jumps to about 1.06 m/s; Act interpolates speed along the path, so this is a target step, not a command step.
3. **Exact Boundary Waypoints:**
   - Stop line waypoint: exactly $(23.8, -1.75)$ with $v = 0.0\text{ m/s}$, ensuring vehicle front ($x+0.9 = 24.7\text{ m}$) never touches $x = 25.0\text{ m}$.
   - Goal waypoint: exactly $(80.2, -1.75)$ with $v = 0.0\text{ m/s}$.
4. **Kinematic Bounds:**
   - Longitudinal acceleration: $\le 1.40\text{ m/s}^2$ (below challenge limit $1.5\text{ m/s}^2$).
   - Longitudinal braking: $\le 1.81\text{ m/s}^2$ (below contract limit $2.0\text{ m/s}^2$).
   - Maximum nominal speed: $3.80\text{ m/s}$ (comfortably below challenge limit $4.0\text{ m/s}$ and Act cap $3.9\text{ m/s}$).
5. **Opposing Lane Safety ($y \in [-3.5, +3.5]$):**
   - Outbound 16 m quintic ramp from $x = 26.0\text{ m}$ (entry + 1) to $x = 42.0\text{ m}$ (work_start); hold $y = +1.75\text{ m}$ to $x = 51.0\text{ m}$ (work_end + 2).
   - Return 16 m quintic ramp from $x = 51.0\text{ m}$ to $x = 67.0\text{ m}$ ($\le$ exit line $x = 68.0\text{ m}$).
   - Opposing-lane occupancy ($y + 0.9 > 0$) only for $x \in [31.8, 61.0]\text{ m}$.
   - Maximum steering angle $\approx 0.18\text{ rad}$ (clamp $\pm 0.45\text{ rad}$).
   - Maximum steering rate at 3.8 m/s $\approx 0.47\text{ rad/s}$ (limit 0.6 rad/s; the profile caps speed so that it never exceeds $0.8 \times 0.6$).

---

## 4. How to Use Test Data

### A. Publishing Live with the Helper Script
The helper script `scripts/publish_test_plan.py` publishes directly to `/solution/plan` with contract-compliant QoS (reliable, volatile, keep last 1) at 10 Hz:

```bash
# Source environment first:
source /opt/ros/jazzy/setup.bash
source install/setup.bash

# Stream nominal plan with live timestamps (matched to /clock):
python3 scripts/publish_test_plan.py -f src/roadwork_student/test_data/plan/yaml/01_nominal_full_course.yaml --live-stamps

# Test Act's behavior when receiving an expired plan:
python3 scripts/publish_test_plan.py -f src/roadwork_student/test_data/plan/yaml/07_expired_valid_until.yaml --once
```

### B. Publishing via ROS 2 CLI
You can also feed the YAML files directly using `ros2 topic pub --stdin`:

```bash
ros2 topic pub --stdin /solution/plan roadwork_solution_msgs/msg/Plan \
  --qos-reliability reliable --qos-durability volatile --qos-depth 1 \
  < src/roadwork_student/test_data/plan/yaml/01_nominal_full_course.yaml
```

### C. Regenerating or Modifying Scenarios
To regenerate all YAML and JSON files (e.g. after modifying parameters):

```bash
python3 scripts/generate_plan_test_data.py
```
