std_msgs/Header header                # stamp: sim time of computation; frame_id: "map"
builtin_interfaces/Time scene_stamp   # stamp of the Scene this plan was built from
builtin_interfaces/Time valid_until   # Act must not execute this plan after this instant
uint32 seq                            # increments by one on every publication

uint8 MODE_STOP  = 0                  # brake to standstill now; ignore path
uint8 MODE_TRACK = 1                  # track path under speed profile and constraints
uint8 MODE_FAULT = 255                # unrecoverable fault; emergency stop
uint8 mode

PlanPoint[<=250] path                 # ordered in travel direction; non-empty if MODE_TRACK; upper bounded for real-time safety
float64 speed_limit                   # m/s, from beacon or nominal 4.0

bool has_stop_line
float64 stop_line_x                   # m, map; vehicle front (x + 0.9) must stay below it

string<=32 decision_state             # Plan's state name, for logs and traceability only
