# Sense to Plan contract

This document describes how the Sense node and the Plan node talk to each other.
Sense subscribes to every raw sensor topic the simulator exposes, validates and
fuses the evidence, and publishes a compact internal `Scene` message that
contains all the interpreted facts Plan needs to make a decision. Plan never
subscribes to any external sensor topic directly.

The messages live in `roadwork_solution_msgs`; `roadwork_interfaces` is never
modified.

---

## Topics

| Topic | Type | Publisher | Subscriber | QoS | Rate |
|---|---|---|---|---|---|
| `/solution/scene` | `roadwork_solution_msgs/msg/Scene` | sense | plan | Reliable, volatile, keep last 1 | 10 Hz |

The scene is published at 10 Hz, matching the slowest sensors (LiDAR, Radar,
Camera). Only the most recent scene is kept, because a stale scene is worse than
no scene for safety decisions. There is no separate status topic for D1; Sense
health is carried inline on `Scene` via `sense_status`, `stale_flags`, and
`sense_state`.

---

## Conventions

All values follow SI units (metres, m/s, radians, seconds) throughout — REP-103.
Obstacle positions are in the `map` frame; sensor-frame quantities (`obstacle_range`)
are in `base_link` (+x forward, +y left, right-hand rule — REP-105).
All timestamps come from `/clock` (simulation time); `use_sim_time=true` is
mandatory for all three nodes.

A stamp is "in the future" if it is more than 1×10⁻⁶ s ahead of the current
sim time (same tolerance the simulator uses for command validation).

Vehicle geometry reference: rear axle = pose origin; front = x + 0.9 m;
collision radius = 0.9 m disc; wheelbase = 2.4 m. These are immutable project-contract
constants.

---

## Sensor inputs to Sense

Sense subscribes to these external topics. All are read-only from Sense's
perspective; Sense never publishes to any external topic.

| Topic | Type | Rate | QoS |
|---|---|---:|---|
| `/vehicle/odometry` | `nav_msgs/msg/Odometry` | 20 Hz | SensorDataQoS |
| `/lidar/scan` | `sensor_msgs/msg/LaserScan` | 10 Hz | SensorDataQoS |
| `/radar/detections` | `roadwork_interfaces/msg/RadarDetections` | 10 Hz | SensorDataQoS |
| `/camera/image_raw` | `sensor_msgs/msg/Image` | 10 Hz | SensorDataQoS |
| `/infra/roadwork/beacon` | `roadwork_interfaces/msg/RoadworkBeacon` | 2 Hz | Reliable, volatile, depth 10 |

Odometry is used to project LiDAR rays from `base_link` into `map`. The stamp of
the odometry message used for each scan is published as `odom_stamp` so the
projection age can be traced in rosbags.

---

## Sensor freshness TTLs

Sense enforces these time-to-live values on every publishing tick:

| Sensor | Rate | TTL | Notes |
|---|---:|---:|---|
| Odometry | 20 Hz | 0.075 s | 1.5 periods; used for LiDAR projection only |
| LiDAR | 10 Hz | 0.15 s | 1.5 periods — permits one missed packet |
| Radar | 10 Hz | 0.15 s | 1.5 periods |
| Camera | 10 Hz | 0.15 s | 1.5 periods |
| Beacon | 2 Hz | 1.2 s | The beacon's own `valid_for` field governs; Sense re-checks every tick |

When a sensor exceeds its TTL, its bit in `stale_flags` is set. If LiDAR is
stale, `obstacle_in_lane = false` and `obstacle_range = 0.0`. If the camera is
stale, `panel_state = PANEL_UNKNOWN`. If the beacon is stale, `beacon_valid = false`.

Plan treats every field that depends on a stale sensor as "no information", not
as the last known value.

---

## The Scene message

### Header and sequencing

- `header.stamp`: sim time when Sense finished computing this scene.
  `frame_id` is always `"map"`.
- `seq`: monotonically increasing counter, incremented on every publication
  (even if nothing changed). Plan uses it to confirm Sense is alive and that
  a scene is genuinely new.

### Source stamps

```
builtin_interfaces/Time odom_stamp
builtin_interfaces/Time lidar_stamp
builtin_interfaces/Time radar_stamp
builtin_interfaces/Time camera_stamp
builtin_interfaces/Time beacon_stamp
```

Sense records the stamp of each raw message it last used. Plan passes
`scene.header.stamp` back through the Plan message as `Plan.scene_stamp`, so
Act can verify the age of the sensor data behind any active plan (the ≤ 0.5 s
scene-age check defined in PLAN_ACT_CONTRACT).

### Beacon evidence

| Field | Type | Meaning |
|---|---|---|
| `beacon_valid` | `bool` | true iff a beacon was received and is still within its `valid_for` window |
| `entry_x` | `float64` | m, map; entry line x (normally 25.0) |
| `work_start` | `float64` | m, map; x start of physical works |
| `work_end` | `float64` | m, map; x end of physical works |
| `exit_x` | `float64` | m, map; x coordinate of work-zone exit line |
| `speed_limit` | `float64` | m/s; from beacon; 0.0 when `beacon_valid` is false |
| `pass_side` | `int8` | +1 = pass left; only +1 supported in v1 |

`beacon_valid` is set to false as soon as `now > beacon_stamp + 1.2`. Plan
computes its own deadline the same way (`beacon_stamp + 1.2 s`); there is no
`valid_until` field because the subscriber can derive it in one line from a
fixed project-contract constant.

Geometry fields (`entry_x`, `work_start`, `work_end`, `exit_x`, `pass_side`) may
be cached from the last valid beacon even after `beacon_valid` goes false. Plan's
caching policy governs whether to use that cached geometry; Sense publishes the
last received values regardless.

### Camera / panel evidence

| Field | Type | Meaning |
|---|---|---|
| `panel_state` | `uint8` | `PANEL_UNKNOWN = 0`, `PANEL_STOP = 1`, `PANEL_GO = 2` |

`panel_state` is the output of Sense's temporal confirmation window. Sense
requires at least 3 consecutive consistent camera frames before changing state.
This suppresses single-frame false-GO detections, which the PDF identifies as
the principal camera failure mode.

Sense sets `panel_state = PANEL_UNKNOWN` when:
- the camera stamp is stale (beyond its 0.15 s TTL), or
- fewer than 3 consecutive frames agree on the same state, or
- the classification is ambiguous (neither clearly red nor clearly green).

`PANEL_UNKNOWN` is the zero-value default, so an uninitialised or unread field
is always safe. Plan must treat `PANEL_UNKNOWN` with the same caution as
`PANEL_STOP` for all entry decisions.

There is no confidence score field. The camera provides a 96×64 RGB8 crop with
no confidence output from the simulator. Temporal confirmation (frame count)
is the stability mechanism; a numeric confidence score is not needed and would
require an undefined computation rule.

### Obstacle evidence

```
bool    obstacle_in_lane    # any LiDAR cluster detected in the opposing lane (map y > 0)
float64 obstacle_range      # m, base_link; range to nearest cluster; 0.0 if none
```

Sense projects the 360-ray LiDAR scan into `map` using the odometry pose at
`odom_stamp`, clusters the opposing lane (map y > 0), and reports the nearest
cluster. No multi-frame tracking is performed by Sense; Plan provides temporal
hysteresis for stop/hold decisions.

`obstacle_in_lane` is re-derived freshly on each scan. It is never carried over
from a previous tick. If `STALE_LIDAR` is set, both fields default to safe
values (false / 0.0).

> **D2 note — radar evidence:** Radar-based yielding for opposing traffic (S3)
> and mid-traversal obstacle detection (S5) will require additional fields in a
> future revision of this message. When added, **Sense** is responsible for
> correcting radar radial velocity for ego motion before publishing. Leaving
> ego-velocity correction as an open question across the node boundary is a
> contract defect. This work is deferred to D2.

### Sense health

| Field | Type | Meaning |
|---|---|---|
| `sense_status` | `uint8` | `SENSE_OK = 0`, `SENSE_DEGRADED = 1`, `SENSE_FAULT = 255` |
| `stale_flags` | `uint8` | bitmask: bit 0 = LiDAR, bit 1 = Radar, bit 2 = Camera, bit 3 = Beacon |
| `sense_state` | `string<=32` | Sense FSM state name; for logs and traceability; Plan never makes decisions on it |

`SENSE_DEGRADED` means at least one non-critical sensor is stale but core
evidence (LiDAR + Camera) is still fresh. For D1 (S1–S2), a stale radar sets
`SENSE_DEGRADED` but does not block Plan, because S1–S2 have no opposing
traffic. `SENSE_FAULT` means Sense cannot guarantee any output; Plan must
switch to `MODE_STOP`.

Plan distinguishes `SENSE_FAULT` from a stale scene:
- **Stale scene** (`now - scene.header.stamp > 0.5 s`): Plan's own age-check
  fires; Plan goes to `MODE_STOP`.
- **`SENSE_FAULT`**: Sense is still publishing but marks its data untrustworthy;
  Plan goes to `MODE_STOP`.

---

## What Sense promises

1. Sense publishes a `Scene` every 100 ms of sim time from the moment the first
   valid sensor message arrives.
2. Every scene carries the stamps of the raw messages it was built from so the
   full data-lineage chain (sensor → scene → plan → command) can be traced
   in rosbags.
3. Sense never promotes `panel_state` from `PANEL_STOP` to `PANEL_GO` without
   at least 3 consecutive consistent camera frames.
4. `beacon_valid` goes false as soon as `now > beacon_stamp + 1.2`. Sense never
   extends a beacon's validity window.
5. `obstacle_in_lane` and `obstacle_range` are re-derived on each scan. If
   LiDAR is stale, both are cleared to their safe defaults.
6. All numerical fields are finite. Sense filters NaN and infinite raw sensor
   values before publishing; a stale bit is set if a scan cannot be used.
7. `sense_state` is set even when `SENSE_FAULT = 255`, so logs capture the last
   known FSM state before the fault.

---

## What Plan promises (regarding the Scene interface)

1. Plan subscribes to `/solution/scene` with the same QoS profile
   (Reliable, volatile, keep last 1).
2. Plan checks the age of every scene before using it:
   `now - scene.header.stamp > 0.5 s` → Plan switches to `MODE_STOP` and sets
   `decision_state` to `"SCENE_STALE"`.
3. Plan never acts on a scene whose `header.stamp` is in the future
   (more than 1×10⁻⁶ s ahead of now).
4. Plan treats `PANEL_UNKNOWN` and `SENSE_FAULT` as no entry permission.
5. Plan forwards `scene.header.stamp` as `Plan.scene_stamp` so Act can verify
   sensor lineage (see PLAN_ACT_CONTRACT §Timing).
6. Plan does not interpret `sense_state`; it publishes its own `decision_state`.

For the entry-permission conditions that Plan enforces using Scene fields, see
PLAN_ACT_CONTRACT §How we stop before the work zone.

---

## Timing values and why we chose them

| What | Value | Why |
|---|---|---|
| Sense publish rate | 10 Hz | matches the slowest sensors; faster gives no new information |
| LiDAR / Radar / Camera TTL | 0.15 s | 1.5 periods at 10 Hz; permits one lost packet without false staleness |
| Odometry TTL | 0.075 s | 1.5 periods at 20 Hz; keeps LiDAR projection age low |
| Beacon TTL | 1.2 s | the beacon `valid_for` field (fixed project-contract constant) |
| Max scene age in Plan | 0.5 s | five sensor periods; leaves time for Sense + Plan computation |
| Panel confirmation window | ≥ 3 consecutive frames | ≈ 300 ms at 10 Hz; suppresses single-frame false GO |

---

## Rubric compliance

| Criterion | Verdict |
|---|---|
| **Command/Report Separation** | ✅ `Scene` is the evidence stream to Plan; Sense health is inline on Scene — no separate status topic needed for D1 |
| **Deterministic Data Types** | ✅ No unbounded arrays; all fields are scalars or `string<=32` |
| **Safety Lifecycle** | ✅ `SENSE_FAULT = 255`; `PANEL_UNKNOWN = 0` defaults safe; `beacon_valid = false` defaults safe |
| **REP-103 / REP-105** | ✅ `map` frame for positions; `base_link` for `obstacle_range`; SI units throughout |
| **Modularity** | ✅ `Scene.msg` in `roadwork_solution_msgs`; zero node logic in the interface package |
| **Build Configuration** | ✅ Registered in `CMakeLists.txt`; compiles under `-Wall -Wextra -Wpedantic` |

---

## Starting a new episode

Every episode is a fresh launch. If Sense observes sim time going backwards, it
resets all source stamps to "never received", clears `beacon_valid`, resets
`panel_state` to `PANEL_UNKNOWN`, and returns to its initial FSM state. Plan
detects the reset via a `seq` discontinuity or a future `header.stamp` and
also resets.
