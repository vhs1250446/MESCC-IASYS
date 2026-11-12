# Plan's report message (/solution/plan_status). Act never reads it.
# Contract: team_docs/PLAN_NODE.md
std_msgs/Header header                # stamp: sim time of the tick; frame_id: "map"

uint8 STATE_INIT      = 0             # no scene or no valid beacon geometry yet
uint8 STATE_HOLD      = 1             # tracking up to the stop line; entry denied
uint8 STATE_TRACKING  = 2             # entry permitted or committed
uint8 STATE_SAFE_STOP = 3             # MODE_STOP because of a scene problem
uint8 STATE_FAULT     = 255           # internal invariant broken; latched until reset
uint8 state

uint8 REASON_NONE          = 0
uint8 REASON_NO_SCENE      = 1
uint8 REASON_SCENE_FUTURE  = 2
uint8 REASON_SCENE_STALE   = 3
uint8 REASON_SENSE_FAULT   = 4
uint8 REASON_NO_GEOMETRY   = 5
uint8 REASON_ENTRY_DENIED  = 6
uint8 REASON_FAULT         = 255
uint8 reason_code
string<=32 reason                     # text of reason_code, e.g. SCENE_STALE

uint32 plan_seq                       # seq of the Plan published on this tick
uint32 scene_seq                      # seq of the Scene used; 0 if none
float64 scene_age                     # s, now minus scene header stamp; -1.0 if none
bool committed                        # front has crossed entry_x; latched until reset

# Set bit = that entry condition failed on this tick (as Plan evaluated it).
uint8 DENY_PANEL        = 1           # panel_state is not PANEL_GO
uint8 DENY_BEACON       = 2           # beacon not fresh, or its geometry was rejected
uint8 DENY_CAMERA_STALE = 4
uint8 DENY_LIDAR_STALE  = 8
uint8 DENY_LANE_BLOCKED = 16          # obstacle_in_lane
uint8 deny_flags
