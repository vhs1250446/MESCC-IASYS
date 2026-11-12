std_msgs/Header header             # stamp: sim time of publication; frame_id: "map"
uint32 seq                         # increments by one on every publication

# ── Source stamps ─────────────────────────────────────────────────────────────
# Plan passes header.stamp back as Plan.scene_stamp so Act can verify lineage.
builtin_interfaces/Time odom_stamp     # stamp of the odometry used to project LiDAR into map
builtin_interfaces/Time lidar_stamp    # stamp of the most recent LiDAR scan used
builtin_interfaces/Time radar_stamp    # stamp of the most recent radar message used
builtin_interfaces/Time camera_stamp   # stamp of the most recent camera image used
builtin_interfaces/Time beacon_stamp   # stamp of the most recent beacon message used

# ── Ego position ──────────────────────────────────────────────────────────────
# Plan needs it for the commitment rule (front = ego_x + 0.9 past entry_x).
float64 ego_x                      # m, map; rear-axle x from the odometry at odom_stamp

# ── Beacon evidence ───────────────────────────────────────────────────────────
# Geometry fields may be cached after beacon_valid goes false (Plan decides caching policy).
# Plan computes its own expiry: beacon_stamp + 1.2 s (valid_for is a fixed project constant).
bool    beacon_valid               # true iff beacon was received and is within its valid_for window
float64 entry_x                    # m, map; work-zone entry line x (normally 25.0)
float64 work_start                 # m, map; x start of physical works
float64 work_end                   # m, map; x end of physical works
float64 exit_x                     # m, map; x coordinate of work-zone exit line
float64 speed_limit                # m/s, from beacon; 0.0 when beacon_valid is false
int8    pass_side                  # +1 = pass to the left; only +1 supported in v1

# ── Camera / panel evidence ───────────────────────────────────────────────────
# panel_state is the output of Sense's temporal confirmation window.
# Sense requires >=3 consecutive consistent frames before promoting STOP -> GO.
# PANEL_UNKNOWN is the zero/safe default for missing or ambiguous evidence.
uint8 PANEL_UNKNOWN = 0            # blank, ambiguous, stale, or insufficient frames
uint8 PANEL_STOP    = 1            # red disk confirmed
uint8 PANEL_GO      = 2            # green disk confirmed
uint8 panel_state

# ── Obstacle evidence (LiDAR-derived) ────────────────────────────────────────
# LiDAR rays projected into map frame using ego pose at odom_stamp.
# obstacle_in_lane is re-derived each scan; it is not retained across scans.
# If STALE_LIDAR is set, obstacle_in_lane = false and obstacle_range = 0.0.
bool    obstacle_in_lane           # true iff a cluster is detected in the opposing lane (map y > 0)
float64 obstacle_range             # m, base_link; range to nearest blocking cluster; 0.0 if none

# ── Sense health ──────────────────────────────────────────────────────────────
uint8 SENSE_OK       = 0           # all core sensors fresh
uint8 SENSE_DEGRADED = 1           # one or more non-critical sensors stale; core evidence valid
uint8 SENSE_FAULT    = 255         # unrecoverable error; Plan must switch to MODE_STOP
uint8 sense_status

# Bitmask: set bits identify which sensor streams have exceeded their TTL.
uint8 STALE_LIDAR  = 1             # bit 0
uint8 STALE_RADAR  = 2             # bit 1
uint8 STALE_CAMERA = 4             # bit 2
uint8 STALE_BEACON = 8             # bit 3
uint8 stale_flags

string<=32 sense_state             # Sense FSM state name; for logs and traceability only
