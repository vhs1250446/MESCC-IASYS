#!/usr/bin/env python3
"""
generate_plan_test_data.py

Generates test data files (both YAML and JSON) for the ACT node following the
Plan-to-Act Contract (team_docs/PLAN_ACT_CONTRACT.md, AGENTS.md, and roadwork_solution_msgs).

Dummy data includes ONLY what PLAN outputs:
  Topic: /solution/plan
  Message type: roadwork_solution_msgs/msg/Plan
    - header: std_msgs/Header (stamp, frame_id="map")
    - scene_stamp: builtin_interfaces/Time
    - valid_until: builtin_interfaces/Time (header.stamp + 0.3 s)
    - seq: uint32
    - mode: uint8 (MODE_STOP=0, MODE_TRACK=1, MODE_FAULT=255)
    - path: PlanPoint[<=250] path
        - x: float64 (m, map)
        - y: float64 (m, map)
        - speed: float64 (m/s, >= 0)
    - speed_limit: float64 (m/s)
    - has_stop_line: bool
    - stop_line_x: float64 (m, map)
    - decision_state: string<=32
"""

import os
import math
import json
import yaml

# Directory layout
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_ROOT = os.path.abspath(os.path.join(SCRIPT_DIR, ".."))
OUTPUT_DIR_YAML = os.path.join(REPO_ROOT, "src", "roadwork_student", "test_data", "plan", "yaml")
OUTPUT_DIR_JSON = os.path.join(REPO_ROOT, "src", "roadwork_student", "test_data", "plan", "json")

os.makedirs(OUTPUT_DIR_YAML, exist_ok=True)
os.makedirs(OUTPUT_DIR_JSON, exist_ok=True)


# ---------------------------------------------------------------------------
# Path model. Mirrors src/roadwork_student/src/path_builder.cpp exactly
# (team_docs/PLAN_NODE.md "Path"); keep the two in sync.
# ---------------------------------------------------------------------------
START_X = 5.0
GOAL_X, GOAL_Y = 80.2, -1.75
OWN_Y, OPP_Y = -1.75, 1.75
FRONT_OFFSET = 0.9
WHEELBASE = 2.4
MAX_STEER_RATE = 0.6
GRID_SPACING = 0.4        # m in x; arc spacing stays <= 0.5 m on the ramps
DENSE_SPACING = 0.2       # m in x, in the stopping zones
DENSE_ZONE = 4.0          # m before the stop point and before the goal
RAMP_START_OFFSET = 1.0   # m after entry_x
POST_WORK_OFFSET = 2.0    # m after work_end
RETURN_RAMP = 16.0        # m

# Nominal beacon geometry (work_shift = 0) and Plan parameters (config/plan.yaml).
GEO = dict(entry_x=25.0, work_start=42.0, work_end=49.0, exit_x=68.0)
V_CRUISE, A_ACC, A_DEC, STOP_MARGIN, SLEW_MARGIN = 3.8, 1.4, 1.8, 0.3, 0.8
STOP_X = GEO["entry_x"] - FRONT_OFFSET - STOP_MARGIN  # 23.8


def ramp(x, x0, x1, y0, y1):
    """Quintic smooth step s = 10t^3 - 15t^4 + 6t^5; returns y and its first three x-derivatives."""
    if x <= x0:
        return y0, 0.0, 0.0, 0.0
    if x >= x1:
        return y1, 0.0, 0.0, 0.0
    L, d = x1 - x0, y1 - y0
    t = (x - x0) / L
    s = t**3 * (10.0 + t * (-15.0 + 6.0 * t))
    s1 = 30.0 * t * t * (1.0 - t) ** 2
    s2 = 60.0 * t * (1.0 - t) * (1.0 - 2.0 * t)
    s3 = 60.0 - 360.0 * t + 360.0 * t * t
    return y0 + d * s, d * s1 / L, d * s2 / L**2, d * s3 / L**3


def lateral(x, g=GEO):
    """Outbound ramp entry_x+1 -> work_start; return ramp work_end+2 -> +16 m."""
    back_start = g["work_end"] + POST_WORK_OFFSET
    if x < back_start:
        return ramp(x, g["entry_x"] + RAMP_START_OFFSET, g["work_start"], OWN_Y, OPP_Y)
    return ramp(x, back_start, back_start + RETURN_RAMP, OPP_Y, OWN_Y)


def curvature_rate(x):
    """Exact |dkappa/ds| = |d3*q - 3*d1*d2^2| / q^3 with q = 1 + d1^2."""
    _, d1, d2, d3 = lateral(x)
    q = 1.0 + d1 * d1
    return abs(d3 * q - 3.0 * d1 * d2 * d2) / q**3


def generate_waypoint_x_grid():
    """
    x grid: 0.4 m nominal, 0.2 m in the 4 m before the stop point and the goal,
    exact stop point (23.8) and exact goal (80.2). 209 points (<= 250).
    """
    xs = []

    def fill(a, b, h):
        if b - a <= 1e-9:
            return
        n = max(1, math.ceil((b - a) / h - 1e-9))
        xs.extend(a + i * (b - a) / n for i in range(n))

    fill(START_X, STOP_X - DENSE_ZONE, GRID_SPACING)
    fill(max(START_X, STOP_X - DENSE_ZONE), STOP_X, DENSE_SPACING)
    fill(STOP_X, GOAL_X - DENSE_ZONE, GRID_SPACING)
    fill(GOAL_X - DENSE_ZONE, GOAL_X, DENSE_SPACING)
    xs.append(GOAL_X)
    return xs


def generate_lateral_path(xs):
    """Opposing-lane occupancy (y + 0.9 > 0) only inside the entry..exit region."""
    ys = [lateral(x)[0] for x in xs]
    ys[-1] = GOAL_Y
    return ys


def compute_velocity_profile(xs, ys, v_max=V_CRUISE, a_acc=A_ACC, a_dec=A_DEC,
                             stop_line=False, accel_x=START_X, accel_v=0.0):
    """
    Caps: v_max, steering slew (v * 2.4 * max|dkappa/ds| <= 0.8 * 0.6 rad/s over each
    point's neighbourhood), 0 at/after the stop point when stop_line, 0 at the goal.
    Forward pass at a_acc from (accel_x, accel_v); backward pass at a_dec.
    """
    n = len(xs)
    ds = [math.hypot(xs[i + 1] - xs[i], ys[i + 1] - ys[i]) for i in range(n - 1)] + [0.0]
    cap = [v_max] * n
    for i in range(n):
        a, b = xs[max(i - 1, 0)], xs[min(i + 1, n - 1)]
        kp = max(curvature_rate(a + (b - a) * k / 8) for k in range(9))
        if WHEELBASE * kp > 1e-9:
            cap[i] = min(cap[i], SLEW_MARGIN * MAX_STEER_RATE / (WHEELBASE * kp))
        if stop_line and xs[i] >= STOP_X - 1e-9:
            cap[i] = 0.0
    cap[-1] = 0.0

    i0 = max([i for i in range(n) if xs[i] <= accel_x + 1e-9] or [0])
    v = [0.0] * n
    for i in range(i0 + 1):
        v[i] = min(cap[i], max(0.0, accel_v))
    for i in range(i0, n - 1):
        v[i + 1] = min(cap[i + 1], math.sqrt(v[i] ** 2 + 2.0 * a_acc * ds[i]))
    for i in range(n - 2, -1, -1):
        v[i] = min(v[i], math.sqrt(v[i + 1] ** 2 + 2.0 * a_dec * ds[i]))
    return v


def build_plan_points(xs, ys, speeds):
    """Creates a list of dicts representing PlanPoint objects (rounded for readability)."""
    return [{"x": round(float(x), 4), "y": round(float(y), 4), "speed": round(float(v), 3)}
            for x, y, v in zip(xs, ys, speeds)]


def make_plan_dict(header_stamp, scene_stamp, valid_until, seq, mode,
                   path_points, speed_limit, has_stop_line, stop_line_x, decision_state):
    """Builds standard dictionary representing roadwork_solution_msgs/msg/Plan."""
    return {
        "header": {
            "stamp": header_stamp,
            "frame_id": "map"
        },
        "scene_stamp": scene_stamp,
        "valid_until": valid_until,
        "seq": int(seq),
        "mode": int(mode),
        "path": path_points,
        "speed_limit": float(speed_limit),
        "has_stop_line": bool(has_stop_line),
        "stop_line_x": float(stop_line_x),
        "decision_state": str(decision_state)[:32]
    }


def save_test_plan(name, plan_data):
    """Saves plan in both YAML and JSON format."""
    yaml_path = os.path.join(OUTPUT_DIR_YAML, f"{name}.yaml")
    json_path = os.path.join(OUTPUT_DIR_JSON, f"{name}.json")

    with open(yaml_path, "w") as f:
        yaml.dump(plan_data, f, sort_keys=False, default_flow_style=False)

    with open(json_path, "w") as f:
        json.dump(plan_data, f, indent=2)

    print(f"Generated: {name}.yaml and {name}.json (points: {len(plan_data['path'])})")


def main():
    xs = generate_waypoint_x_grid()
    ys = generate_lateral_path(xs)

    # Reference timestamps (sim time base: 5.0 s)
    base_stamp = {"sec": 5, "nanosec": 0}
    fresh_scene_stamp = {"sec": 4, "nanosec": 950000000}  # 0.05 s old (<= 0.5 s limit)
    valid_until_nominal = {"sec": 5, "nanosec": 300000000}  # stamp + 0.3 s

    # -------------------------------------------------------------
    # 1. Nominal Full Course (4.0 m/s limit)
    # -------------------------------------------------------------
    nominal_speeds = compute_velocity_profile(xs, ys)
    nominal_points = build_plan_points(xs, ys, nominal_speeds)
    plan_01 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=10,
        mode=1,  # MODE_TRACK
        path_points=nominal_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="ENTRY_GO"
    )
    save_test_plan("01_nominal_full_course", plan_01)

    # -------------------------------------------------------------
    # 2. Nominal Reduced Speed (3.0 m/s limit from beacon)
    # -------------------------------------------------------------
    reduced_speeds = compute_velocity_profile(xs, ys, v_max=min(3.0, V_CRUISE))
    reduced_points = build_plan_points(xs, ys, reduced_speeds)
    plan_02 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=11,
        mode=1,  # MODE_TRACK
        path_points=reduced_points,
        speed_limit=3.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="NOMINAL_REDUCED_SPEED_3MS"
    )
    save_test_plan("02_nominal_reduced_speed", plan_02)

    # -------------------------------------------------------------
    # 3. Stop-Line Active (Enforced at x=25.0, stopping waypoint at x=23.8)
    # -------------------------------------------------------------
    stop_speeds = compute_velocity_profile(xs, ys, stop_line=True)
    stop_points = build_plan_points(xs, ys, stop_speeds)
    plan_03 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=15,
        mode=1,  # MODE_TRACK
        path_points=stop_points,
        speed_limit=4.0,
        has_stop_line=True,
        stop_line_x=25.0,
        decision_state="HOLD_AT_ENTRY"
    )
    save_test_plan("03_stop_line_hold", plan_03)

    # -------------------------------------------------------------
    # 4. Stop-Line Cleared (Resuming motion into work area)
    # -------------------------------------------------------------
    resume_speeds = compute_velocity_profile(xs, ys, accel_x=STOP_X, accel_v=0.0)
    resume_points = build_plan_points(xs, ys, resume_speeds)
    plan_04 = make_plan_dict(
        header_stamp={"sec": 10, "nanosec": 0},
        scene_stamp={"sec": 9, "nanosec": 950000000},
        valid_until={"sec": 10, "nanosec": 300000000},
        seq=25,
        mode=1,  # MODE_TRACK
        path_points=resume_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="ENTRY_GO"
    )
    save_test_plan("04_stop_line_cleared", plan_04)

    # -------------------------------------------------------------
    # 5. Explicit MODE_STOP (Emergency or operator brake command)
    # -------------------------------------------------------------
    plan_05 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=30,
        mode=0,  # MODE_STOP
        path_points=nominal_points,  # Path ignored by Act when mode is MODE_STOP
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="SCENE_STALE"
    )
    save_test_plan("05_mode_stop", plan_05)

    # -------------------------------------------------------------
    # 6. Explicit MODE_FAULT (Fatal planning error / sensor loss)
    # -------------------------------------------------------------
    plan_06 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=35,
        mode=255,  # MODE_FAULT
        path_points=[],  # Can be empty in fault mode
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="FAULT"
    )
    save_test_plan("06_mode_fault", plan_06)

    # -------------------------------------------------------------
    # 7. Expired valid_until (Contract timing failure)
    # -------------------------------------------------------------
    plan_07 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until={"sec": 4, "nanosec": 900000000},  # valid_until in the past
        seq=40,
        mode=1,
        path_points=nominal_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="EXPIRED_VALID_UNTIL_TEST"
    )
    save_test_plan("07_expired_valid_until", plan_07)

    # -------------------------------------------------------------
    # 8. Future header stamp (Contract timing failure)
    # -------------------------------------------------------------
    plan_08 = make_plan_dict(
        header_stamp={"sec": 500, "nanosec": 0},  # Way in the future
        scene_stamp={"sec": 500, "nanosec": 0},
        valid_until={"sec": 500, "nanosec": 300000000},
        seq=45,
        mode=1,
        path_points=nominal_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="FUTURE_STAMP_TEST"
    )
    save_test_plan("08_future_header_stamp", plan_08)

    # -------------------------------------------------------------
    # 9. Stale scene stamp (Contract timing failure, age > 0.5 s)
    # -------------------------------------------------------------
    plan_09 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp={"sec": 4, "nanosec": 200000000},  # 0.8 s age (> 0.5 s timeout)
        valid_until=valid_until_nominal,
        seq=50,
        mode=1,
        path_points=nominal_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="STALE_SCENE_TEST"
    )
    save_test_plan("09_stale_scene_stamp", plan_09)

    # -------------------------------------------------------------
    # 10. Malformed Empty Path in MODE_TRACK (Contract violation)
    # -------------------------------------------------------------
    plan_10 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=55,
        mode=1,  # MODE_TRACK with empty path violates Rule 1
        path_points=[],
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="EMPTY_PATH_IN_TRACK_MODE"
    )
    save_test_plan("10_malformed_empty_path", plan_10)

    # -------------------------------------------------------------
    # 11. Malformed NaN Coordinates (Contract violation)
    # -------------------------------------------------------------
    nan_coord_points = [dict(p) for p in nominal_points]
    nan_coord_points[5] = {"x": float("nan"), "y": -1.75, "speed": 1.5}
    plan_11 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=60,
        mode=1,
        path_points=nan_coord_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="NAN_COORDINATE_TEST"
    )
    save_test_plan("11_malformed_nan_coordinates", plan_11)

    # -------------------------------------------------------------
    # 12. Malformed NaN Speed (Contract violation)
    # -------------------------------------------------------------
    nan_speed_points = [dict(p) for p in nominal_points]
    nan_speed_points[5] = {"x": 7.5, "y": -1.75, "speed": float("nan")}
    plan_12 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=65,
        mode=1,
        path_points=nan_speed_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="NAN_SPEED_TEST"
    )
    save_test_plan("12_malformed_nan_speed", plan_12)

    # -------------------------------------------------------------
    # 13. Recovery New Sequence (Recovers Act from SAFE_STOP)
    # -------------------------------------------------------------
    plan_13 = make_plan_dict(
        header_stamp={"sec": 15, "nanosec": 0},
        scene_stamp={"sec": 14, "nanosec": 950000000},
        valid_until={"sec": 15, "nanosec": 300000000},
        seq=100,  # Fresh sequence strictly higher
        mode=1,
        path_points=nominal_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="RECOVERY_NEW_SEQ"
    )
    save_test_plan("13_recovery_new_seq", plan_13)

    # -------------------------------------------------------------
    # 14. Plan Exceeding Speed Limit (Tests Act's speed clamp guard)
    # -------------------------------------------------------------
    overspeed_points = [dict(p) for p in nominal_points]
    for pt in overspeed_points[10:30]:
        pt["speed"] = 5.5  # Exceeds 4.0 m/s limit
    plan_14 = make_plan_dict(
        header_stamp=base_stamp,
        scene_stamp=fresh_scene_stamp,
        valid_until=valid_until_nominal,
        seq=70,
        mode=1,
        path_points=overspeed_points,
        speed_limit=4.0,
        has_stop_line=False,
        stop_line_x=0.0,
        decision_state="OVERSPEED_GUARD_TEST"
    )
    save_test_plan("14_edge_speed_limit_violation", plan_14)

    print("\nAll 14 test plan scenarios generated successfully in both YAML and JSON!")


if __name__ == "__main__":
    main()
