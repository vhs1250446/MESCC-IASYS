std_msgs/Header header             # stamp: sim time of publication

# ── Sense FSM state ───────────────────────────────────────────────────────────
uint8 STATE_INIT      = 0          # waiting for first valid sensor set
uint8 STATE_RUNNING   = 1          # publishing valid scenes normally
uint8 STATE_DEGRADED  = 2          # publishing degraded scenes (one or more sensors stale)
uint8 STATE_FAULT     = 255        # unrecoverable internal error; not publishing scenes
uint8 state

# ── Reason codes ──────────────────────────────────────────────────────────────
uint8 REASON_NONE            = 0
uint8 REASON_NO_SENSORS      = 1   # no sensor data received yet
uint8 REASON_LIDAR_STALE     = 2   # LiDAR last stamp older than TTL
uint8 REASON_RADAR_STALE     = 3   # Radar last stamp older than TTL
uint8 REASON_CAMERA_STALE    = 4   # Camera last stamp older than TTL
uint8 REASON_BEACON_STALE    = 5   # Beacon last stamp older than its valid_for window
uint8 REASON_FAULT           = 255 # internal error
uint8 reason_code
string<=32 reason              # e.g. "LIDAR_STALE", "BEACON_STALE"

# ── Per-sensor age telemetry ──────────────────────────────────────────────────
float64 lidar_age              # s; now minus lidar_stamp; negative before first message
float64 radar_age              # s; now minus radar_stamp
float64 camera_age             # s; now minus camera_stamp
float64 beacon_age             # s; now minus beacon_stamp

# ── Diagnostic counts ─────────────────────────────────────────────────────────
uint32 scene_seq               # seq of the most recently published Scene
uint32 panel_window_hits       # number of consistent panel frames in the confirmation window
uint8  panel_state             # most recent raw panel classification (before confirmation)
