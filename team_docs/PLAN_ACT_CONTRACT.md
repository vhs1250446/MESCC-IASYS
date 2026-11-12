# Plan to Act contract

This document describes how the Plan node and the Act node talk to each other.
Plan decides what the vehicle should do and where it should go. Act takes that
decision, follows the path using odometry and is the only node that sends
commands to the simulator. Everything Act needs from Plan is in one message,
`Plan`, and everything Act wants to show about itself goes in `ActStatus`.

The messages live in our own interface package, `roadwork_solution_msgs`, so we
never touch the supplied `roadwork_interfaces`.

## Topics

| Topic | Type | Who publishes | Who listens | QoS | Rate |
|---|---|---|---|---|---|
| /solution/plan | roadwork_solution_msgs/msg/Plan | plan | act | reliable, volatile, keep last 1 | 10 Hz |
| /solution/path | nav_msgs/msg/Path | plan | rviz | reliable, volatile, keep last 1 | 10 Hz |
| /solution/state | std_msgs/msg/String | plan | logs | reliable, volatile, keep last 10 | 10 Hz |
| /solution/plan_status | roadwork_solution_msgs/msg/PlanStatus | plan | logs | reliable, volatile, keep last 10 | 10 Hz |
| /solution/act_status | roadwork_solution_msgs/msg/ActStatus | act | logs | reliable, volatile, keep last 10 | 20 Hz |
| /vehicle/command | roadwork_interfaces/msg/VehicleCommand | act | simulator | reliable, volatile, keep last 10 | 20 Hz |

For the plan we only keep the last message, because an older plan is never
useful once a newer one has arrived. Act is the only node allowed to publish on
/vehicle/command.

## Conventions

We use SI units everywhere: metres, metres per second, radians and seconds (REP-103).
Positions are in the `map` frame (REP-105) and always refer to the same point the
odometry reports, which is the rear axle of the vehicle. When we talk about the
front of the vehicle we mean x + 0.9 m, since the simulator models the car as a
disc with a 0.9 m radius.

All times come from the simulation clock (/clock), never from the computer's
wall clock, so every node runs with `use_sim_time=true`. A stamp is only
considered to be "in the future" if it is more than 1e-6 s ahead of the current
sim time, which is the same tolerance the simulator uses.

## The path

The path is a bounded list of `PlanPoint` (`PlanPoint[<=250] path`), and each point has three values:

- `x` and `y`: where the rear axle should pass, in metres in the map frame.
- `speed`: the speed we want when the vehicle reaches that point, in m/s. It is
  never negative.

We put the speed inside each point instead of having a separate list, so the
path and the speed profile can never end up with different lengths.

Plan always follows these rules when building a path:

1. When the mode is MODE_TRACK, the path is never empty.
2. Points go in the direction of travel with nominal spacing <= 0.5 m. In deceleration
   and stopping zones, Plan may generate denser points (e.g. 0.1 to 0.2 m) to ensure
   a smooth velocity ramp.
3. The path has an explicit upper bound of 250 points (`PlanPoint[<=250] path`) to guarantee
   real-time determinism with zero dynamic heap allocation.
4. The first point is at or behind the vehicle, so Act always has something to
   track from where it is.
5. Critical boundary waypoints are explicitly inserted into the path array:
   - When a stop line is enforced, an exact stopping waypoint is placed at
     `x_rear = stop_line_x - 0.9 - margin` (e.g. `x = 23.8 m`) with speed 0.
   - The last point is at the exact goal `(80.2, -1.75)` and has speed 0.
6. Every message carries the whole path up to the goal, not just a piece of it.
7. Speeds never go above `speed_limit`, and slowing down between two points
   never needs more than 2.0 m/s^2.

> **Note for the person implementing Act:**
> While Act is free to select the closest discrete waypoint for lookahead tracking,
> using discrete points spaced 0.5 m apart can cause the lookahead point to jump
> by 0.5 m at a time, creating step changes in the lookahead angle and command chattering.
> It is strongly recommended to compute the lookahead target by interpolating continuously
> along the chord between adjacent waypoints.

## The Plan message

- `header.stamp`: the sim time when Plan computed this plan. `frame_id` is
  always "map".
- `scene_stamp`: the stamp of the Scene message Plan used. This lets us trace a
  plan back to the sensor data behind it, and Act uses it to check that the
  plan is not based on old information.
- `valid_until`: after this moment Act must not use the plan anymore. Plan sets
  it to `header.stamp + 0.3 s`.
- `seq`: a counter that goes up by one every time Plan publishes, even if
  nothing changed. Act uses it to know that Plan is still alive and that a plan
  is really new.
- `mode`:
  - `MODE_STOP = 0`: brake to standstill now and ignore the path.
  - `MODE_TRACK = 1`: follow the path under speed profile and constraints.
  - `MODE_FAULT = 255`: unrecoverable fault; emergency stop.
- `path`: bounded list of `PlanPoint[<=250]`. Empty in `MODE_STOP` and
  `MODE_FAULT`, because Act ignores it there.
- `speed_limit`: the speed limit from the beacon. If Plan has no beacon cached
  yet, it uses 4.0 m/s.
- `has_stop_line` and `stop_line_x`: while `has_stop_line` is true, the front of
  the vehicle must not go past `stop_line_x`.
- `decision_state`: `string<=32`, the name of Plan's current state for logs and
  traceability. Act never makes decisions based on it.

## How we stop before the work zone

Waiting before the entry line is done with the stop line, not with a separate
mode. On the wire, `has_stop_line = true` means "the front (x + 0.9) stays
below `stop_line_x`"; Plan sets `stop_line_x = entry_x` (25.0) and also gives
the path speed 0 from the stop point onwards. Plan never sets a stop line
behind the vehicle front.

When Plan sets and clears the stop line (entry permission, commitment,
beacon-loss policy) is Plan's own decision logic and is specified in
[PLAN_NODE.md](PLAN_NODE.md), not in this interface contract.

Act respects the stop line on its own, even if the speed profile from Plan is
wrong. This way the rule "do not cross x = 25 during STOP" is protected twice,
once in Plan and once in Act.

## Timing values and why we chose them

| What | Value | Why |
|---|---|---|
| Plan publish rate | 10 Hz | the sensors run at 10 Hz, so planning faster gives no new information |
| Plan validity | 0.3 s | we can lose two plans in a row without stopping; it is also the same as the simulator's command timeout |
| Act command rate | 20 Hz | the simulator steps every 0.05 s and expects commands at 20 Hz |
| Max plan age in Act | 0.3 s | Act checks this by itself, in case `valid_until` is wrong |
| Max scene age in Act | 0.5 s | five sensor periods, which leaves time for Sense and Plan to do their work |
| Max odometry age in Act | 0.15 s | three odometry messages at 20 Hz |
| Planning deceleration | 2.0 m/s^2 | lower than the 3.0 m/s^2 the car can brake, so we keep a margin for delays |
| Act speed cap | 3.9 m/s | the limit is 4.0 m/s and a violation is counted above 4.05 m/s, so we stay below it |

## What Act promises

1. As soon as sim time is available, Act sends a command every 50 ms of sim
   time. Until it has a valid plan to follow, the command is speed 0.
2. Every command is stamped with the current sim time.
3. The commanded speed is never higher than the speed from the path, the
   `speed_limit`, the Act speed cap or what the stop line allows. Act can slow
   the vehicle down but never makes it go faster than Plan asked.
4. Steering stays between -0.45 and 0.45 rad and never changes faster than
   0.6 rad/s.
5. Act publishes an ActStatus message on every tick.

## When Act stops on its own

If something is wrong with its inputs, Act goes into SAFE_STOP: it commands
speed 0 and keeps the steering where it is. These are the cases, with the numerical
reason codes and string representations Act reports:

| What happened | Reason constant | Code (`uint8`) | String (`reason`) |
|---|---|---|---|
| tracking normally | `REASON_NONE` | 0 | `NONE` |
| no plan has arrived yet | `REASON_NO_PLAN` | 1 | `NO_PLAN` |
| the plan is past `valid_until` or older than 0.3 s | `REASON_PLAN_EXPIRED` | 2 | `PLAN_EXPIRED` |
| the plan stamp is in the future | `REASON_PLAN_FUTURE` | 3 | `PLAN_FUTURE` |
| MODE_TRACK with an empty path, or NaN/infinite value | `REASON_PLAN_MALFORMED` | 4 | `PLAN_MALFORMED` |
| the scene behind the plan is older than 0.5 s | `REASON_SCENE_STALE` | 5 | `SCENE_STALE` |
| odometry is older than 0.15 s | `REASON_ODOM_STALE` | 6 | `ODOM_STALE` |
| odometry contains NaN or infinite values | `REASON_ODOM_MALFORMED` | 7 | `ODOM_MALFORMED` |
| Plan asked for MODE_STOP | `REASON_PLAN_MODE_STOP` | 8 | `PLAN_MODE_STOP` |
| waiting for a fresh plan sequence | `REASON_WAITING_NEW_SEQ` | 9 | `WAITING_NEW_SEQ` |
| unrecoverable fault | `REASON_FAULT` | 255 | `FAULT` |

To leave SAFE_STOP, Act waits for a valid plan whose `header.stamp` is strictly
newer than the stamp of the plan it held when it stopped. While it is waiting,
the reason is `REASON_WAITING_NEW_SEQ`. Sim time only moves forward, so this
still works if Plan restarts and its `seq` goes back to 1. `seq` is kept for
tracing plans in logs and bags.

Plan also checks for old Scene data by itself. The scene check in Act is only a
second safety layer.

## The ActStatus message

Act publishes this message every tick so we can see what it was doing at any
moment, both live and later from the recorded bags.

- `state`:
  - `STATE_INIT = 0`: before the first valid plan
  - `STATE_TRACKING = 1`: while actively driving
  - `STATE_SAFE_STOP = 2`: when stopped because of an input problem
  - `STATE_FAULT = 255`: unrecoverable failure
- `reason_code`: one of the numerical reason codes above.
- `reason`: `string<=32`, human-readable version of the reason code.
- `plan_seq`: the `seq` of the plan Act is using.
- `plan_age` and `odom_age`: how old the plan and the odometry are, in seconds.
- `target_index`: the path point closest to the vehicle.
- `cross_track_error`: how far the vehicle is from the path, in metres, positive
  when it is to the left of the path.
- `heading_error`: the difference between the vehicle heading and the direction
  of the path, in radians.
- `speed_raw` and `steering_raw`: what the controller wanted before Act applied
  its limits.
- `speed_cmd` and `steering_cmd`: what was actually sent to the simulator.
- `limit_flags`: which limits changed the command on this tick. LIMIT_SPEED is a
  speed cap, LIMIT_STOP_LINE is the stop line, LIMIT_STEER_CLAMP is the
  steering angle limit and LIMIT_STEER_SLEW is the steering rate limit.

## Starting a new episode

Every episode is a fresh launch. Still, if Act sees sim time going backwards, it
forgets the plan, the odometry and its progress along the path, and goes back
to STATE_INIT.
