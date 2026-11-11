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


def quintic_smooth_step(x, x0, x1, y0, y1):
    """
    Quintic polynomial transition ensuring C^2 continuity (zero 1st and 2nd derivatives).
    tau = (x - x0) / (x1 - x0)
    s(tau) = 10*tau^3 - 15*tau^4 + 6*tau^5
    """
    if x <= x0:
        return y0
    if x >= x1:
        return y1
    tau = (x - x0) / (x1 - x0)
    s = 10.0 * (tau**3) - 15.0 * (tau**4) + 6.0 * (tau**5)
    return y0 + (y1 - y0) * s


def generate_waypoint_x_grid():
    """
    Generates x-grid adhering strictly to:
      - Start: x = 5.0 m
      - Nominal spacing <= 0.5 m
      - Denser spacing (~0.15 m) in deceleration & stopping zones:
          Approaching stop line x = 23.8 m
          Approaching goal x = 80.2 m
      - Exact boundary waypoints: 23.8 m and 80.2 m
      - Upper bound: <= 250 waypoints total
    """
    xs = []

    # Segment 1: start (5.0 m) to 20.0 m (nominal 0.5 m spacing)
    x = 5.0
    while x < 20.0:
        xs.append(round(x, 4))
        x += 0.5

    # Segment 2: 20.0 m to 23.8 m (dense deceleration zone for stop line)
    dense_steps_stop = round((23.8 - 20.0) / 0.15)
    for i in range(dense_steps_stop):
        xi = 20.0 + i * (23.8 - 20.0) / dense_steps_stop
        xs.append(round(xi, 4))
    xs.append(23.8)  # Exact stop line boundary waypoint

    # Segment 3: 23.8 m to 75.0 m (nominal 0.5 m spacing)
    x = 23.8 + 0.5
    while x < 75.0:
        xs.append(round(x, 4))
        x += 0.5

    # Segment 4: 75.0 m to 80.2 m (dense deceleration zone for goal)
    dense_steps_goal = round((80.2 - 75.0) / 0.15)
    for i in range(dense_steps_goal):
        xi = 75.0 + i * (80.2 - 75.0) / dense_steps_goal
        xs.append(round(xi, 4))
    xs.append(80.2)  # Exact goal boundary waypoint

    return xs


def generate_lateral_path(xs):
    """
    Computes y coordinates along the road:
      - Own lane center: y = -1.75 m
      - Opposing lane center: y = +1.75 m
      - Bypass roadwork obstacles at x = 43.0 and 47.0
      - Stay in own lane until x = 26.0 m (> stop line 25.0 m)
      - Smooth transition to opposing lane between x = 26.0 and 38.0 m
      - Opposing cruise between x = 38.0 and 51.0 m (giving > 1.6 m clearance to obstacles)
      - Smooth transition back to own lane between x = 51.0 and 63.0 m (< exit line 68.0 m)
      - Cruise to goal at y = -1.75 m
    """
    ys = []
    for x in xs:
        if x <= 26.0:
            y = -1.75
        elif x <= 38.0:
            y = quintic_smooth_step(x, 26.0, 38.0, -1.75, 1.75)
        elif x <= 51.0:
            y = 1.75
        elif x <= 63.0:
            y = quintic_smooth_step(x, 51.0, 63.0, 1.75, -1.75)
        else:
            y = -1.75
        ys.append(round(y, 4))
    return ys


def compute_velocity_profile(xs, ys, v_max=3.8, a_acc=1.4, a_dec=1.8, stop_x=None, resume_from_stop=False):
    """
    Computes bounded kinematic speed profile (forward acceleration and backward deceleration).
    Guarantees:
      - acceleration <= a_acc (limit 1.5 m/s^2)
      - deceleration <= a_dec (limit 2.0 m/s^2)
      - speeds <= v_max
      - exact stop at stop_x (if given) and at goal (80.2 m)
    """
    n = len(xs)
    ds = [0.0] * n
    for i in range(n - 1):
        dx = xs[i+1] - xs[i]
        dy = ys[i+1] - ys[i]
        ds[i] = math.hypot(dx, dy)

    # Forward pass: acceleration from rest or initial speed
    v_fwd = [0.0] * n
    if resume_from_stop and stop_x is not None:
        # Start accelerating after stop_x
        for i in range(n):
            if xs[i] <= stop_x:
                v_fwd[i] = 0.0
            else:
                prev = v_fwd[i-1]
                v_fwd[i] = min(v_max, math.sqrt(prev**2 + 2 * a_acc * ds[i-1]))
    else:
        v_fwd[0] = 0.0
        for i in range(n - 1):
            v_fwd[i+1] = min(v_max, math.sqrt(v_fwd[i]**2 + 2 * a_acc * ds[i]))

    # Backward pass: braking to 0 at stop points
    v_bwd = [v_max] * n
    if stop_x is not None and not resume_from_stop:
        for i in range(n):
            if xs[i] >= stop_x:
                v_bwd[i] = 0.0
    else:
        v_bwd[-1] = 0.0  # Stop at goal

    for i in range(n - 2, -1, -1):
        v_bwd[i] = min(v_bwd[i], math.sqrt(v_bwd[i+1]**2 + 2 * a_dec * ds[i]))

    speeds = [round(min(v_fwd[i], v_bwd[i]), 3) for i in range(n)]
    return speeds


def build_plan_points(xs, ys, speeds):
    """Creates a list of dicts representing PlanPoint objects."""
    points = []
    for x, y, v in zip(xs, ys, speeds):
        points.append({
            "x": float(x),
            "y": float(y),
            "speed": float(v)
        })
    return points


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
    nominal_speeds = compute_velocity_profile(xs, ys, v_max=3.8, a_acc=1.4, a_dec=1.8)
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
        decision_state="NOMINAL_TRACKING"
    )
    save_test_plan("01_nominal_full_course", plan_01)

    # -------------------------------------------------------------
    # 2. Nominal Reduced Speed (3.0 m/s limit from beacon)
    # -------------------------------------------------------------
    reduced_speeds = compute_velocity_profile(xs, ys, v_max=2.9, a_acc=1.2, a_dec=1.5)
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
    stop_speeds = compute_velocity_profile(xs, ys, v_max=3.8, a_acc=1.4, a_dec=1.8, stop_x=23.8)
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
        decision_state="WAITING_BEFORE_ENTRY_LINE"
    )
    save_test_plan("03_stop_line_hold", plan_03)

    # -------------------------------------------------------------
    # 4. Stop-Line Cleared (Resuming motion into work area)
    # -------------------------------------------------------------
    resume_speeds = compute_velocity_profile(xs, ys, v_max=3.8, a_acc=1.4, a_dec=1.8, stop_x=23.8, resume_from_stop=True)
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
        decision_state="RESUMING_MOTION_AFTER_STOP"
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
        decision_state="PLAN_MODE_STOP"
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
        decision_state="PLAN_FATAL_FAULT"
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
