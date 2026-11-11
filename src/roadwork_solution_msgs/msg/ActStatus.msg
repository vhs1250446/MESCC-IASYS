std_msgs/Header header

uint8 STATE_INIT      = 0
uint8 STATE_TRACKING  = 1
uint8 STATE_SAFE_STOP = 2
uint8 STATE_FAULT     = 255
uint8 state

uint8 REASON_NONE            = 0
uint8 REASON_NO_PLAN         = 1
uint8 REASON_PLAN_EXPIRED    = 2
uint8 REASON_PLAN_FUTURE     = 3
uint8 REASON_PLAN_MALFORMED  = 4
uint8 REASON_SCENE_STALE     = 5
uint8 REASON_ODOM_STALE      = 6
uint8 REASON_ODOM_MALFORMED  = 7
uint8 REASON_PLAN_MODE_STOP  = 8
uint8 REASON_WAITING_NEW_SEQ = 9
uint8 REASON_FAULT           = 255
uint8 reason_code

string<=32 reason             # human-readable reason string, e.g. PLAN_EXPIRED, ODOM_STALE
uint32 plan_seq               # seq of the plan in use
float64 plan_age              # s, now minus plan header stamp
float64 odom_age              # s, now minus odometry stamp
uint32 target_index           # progress index on the path
float64 cross_track_error     # m, signed, left positive
float64 heading_error         # rad
float64 speed_raw             # m/s, before limits
float64 steering_raw          # rad, before limits
float64 speed_cmd             # m/s, as published
float64 steering_cmd          # rad, as published
uint8 limit_flags             # bitmask: speed cap, stop line, steering clamp, slew
