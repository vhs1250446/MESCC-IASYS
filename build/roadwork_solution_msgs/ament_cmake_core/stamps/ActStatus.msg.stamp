std_msgs/Header header
uint8 STATE_INIT = 0
uint8 STATE_TRACKING = 1
uint8 STATE_SAFE_STOP = 2
uint8 state
string reason                 # why SAFE_STOP, e.g. PLAN_EXPIRED, ODOM_STALE
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
