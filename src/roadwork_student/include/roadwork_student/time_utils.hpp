// Time helpers shared by the Plan and Act logic libraries.
#pragma once

#include "builtin_interfaces/msg/time.hpp"

namespace roadwork_student {

inline double to_seconds(const builtin_interfaces::msg::Time & t) {
  return static_cast<double>(t.sec) + static_cast<double>(t.nanosec) * 1e-9;
}

// True if `stamp` is more than `tolerance` seconds ahead of `now`
// (the simulator tolerates 1e-6 s; see docs/INTERFACES.md).
inline bool is_future(double stamp, double now, double tolerance) {
  return stamp > now + tolerance;
}

}  // namespace roadwork_student
