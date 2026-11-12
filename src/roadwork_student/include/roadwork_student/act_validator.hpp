// Implements the checks listed in team_docs/PLAN_ACT_CONTRACT.md

// Each function returns one ActStatus::REASON_* code. REASON_NONE means the
// input is usable. When several problems exist, the FIRST failing check in the
// documented order is reported, so a reason code always means the same thing.
#pragma once

#include <cstdint>

#include "builtin_interfaces/msg/time.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "roadwork_solution_msgs/msg/plan.hpp"
#include "roadwork_student/time_utils.hpp"

namespace roadwork_student {

struct ValidatorParams {
  double plan_timeout;     
  double scene_timeout;    
  double odom_timeout;     
  double future_tolerance; 
};

uint8_t validate_plan(
  const roadwork_solution_msgs::msg::Plan * plan, double now, const ValidatorParams & p);

uint8_t validate_odometry(
  const nav_msgs::msg::Odometry * odom, double now, const ValidatorParams & p);

uint8_t validate_inputs(
  const roadwork_solution_msgs::msg::Plan * plan,
  const nav_msgs::msg::Odometry * odom,
  double now, const ValidatorParams & p);

bool is_newer_plan(
  const roadwork_solution_msgs::msg::Plan & plan, double stopped_plan_stamp);

const char * reason_to_string(uint8_t reason_code);

}