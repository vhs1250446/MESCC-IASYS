#!/usr/bin/env python3
"""
publish_test_plan.py

Publishes test Plan messages to /solution/plan following the Plan-Act Contract.
QoS: Reliable, Volatile, Depth 1 (keep last 1)
Rate: 10 Hz

Can update timestamps dynamically to match simulation time (/clock) so that
valid plans remain fresh and do not expire while Act is running.

Usage:
  # Publish nominal full course plan with live sim stamps at 10 Hz:
  python3 scripts/publish_test_plan.py --file src/roadwork_student/test_data/plan/yaml/01_nominal_full_course.yaml --live-stamps

  # Publish stop-line plan once:
  python3 scripts/publish_test_plan.py --file src/roadwork_student/test_data/plan/yaml/03_stop_line_hold.yaml --once

  # Publish exact raw file as-is (e.g. to test expired plan behavior):
  python3 scripts/publish_test_plan.py --file src/roadwork_student/test_data/plan/yaml/07_expired_valid_until.yaml
"""

import argparse
import copy
import os
import sys
import yaml
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy
from rosgraph_msgs.msg import Clock
from roadwork_solution_msgs.msg import Plan
from rosidl_runtime_py.set_message import set_message_fields


class TestPlanPublisher(Node):
    def __init__(self, plan_file, rate_hz, live_stamps, publish_once):
        super().__init__("test_plan_publisher")

        self.plan_file = plan_file
        self.rate_hz = rate_hz
        self.live_stamps = live_stamps
        self.publish_once = publish_once
        self.published_count = 0

        # Load plan data from YAML
        with open(self.plan_file, "r") as f:
            self.raw_dict = yaml.safe_load(f)

        self.base_plan = Plan()
        set_message_fields(self.base_plan, copy.deepcopy(self.raw_dict))

        # Plan-Act contract QoS: Reliable, Volatile, Depth 1
        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        )

        self.publisher = self.create_publisher(Plan, "/solution/plan", qos)

        # Sim clock subscription for live stamps
        self.latest_sim_time = None
        if self.live_stamps:
            self.clock_sub = self.create_subscription(
                Clock, "/clock", self.clock_callback, 10
            )

        timer_period = 1.0 / self.rate_hz
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info(f"Loaded plan: {os.path.basename(plan_file)} (points: {len(self.base_plan.path)})")
        self.get_logger().info(f"Publishing to /solution/plan at {self.rate_hz} Hz (live_stamps={self.live_stamps})")

    def clock_callback(self, msg: Clock):
        self.latest_sim_time = msg.clock

    def timer_callback(self):
        msg = Plan()
        # Copy fields
        set_message_fields(msg, copy.deepcopy(self.raw_dict))

        if self.live_stamps:
            now_time = self.latest_sim_time if self.latest_sim_time is not None else self.get_clock().now().to_msg()
            msg.header.stamp = now_time

            # Keep scene_stamp 0.05 s behind header stamp (well under 0.5 s timeout)
            scene_sec = now_time.sec
            scene_nsec = now_time.nanosec - 50_000_000
            if scene_nsec < 0:
                scene_sec -= 1
                scene_nsec += 1_000_000_000
            msg.scene_stamp.sec = scene_sec
            msg.scene_stamp.nanosec = scene_nsec

            # valid_until = header.stamp + 0.3 s
            valid_sec = now_time.sec
            valid_nsec = now_time.nanosec + 300_000_000
            if valid_nsec >= 1_000_000_000:
                valid_sec += 1
                valid_nsec -= 1_000_000_000
            msg.valid_until.sec = valid_sec
            msg.valid_until.nanosec = valid_nsec

            # Increment sequence counter continuously when streaming live
            msg.seq = self.base_plan.seq + self.published_count

        self.publisher.publish(msg)
        self.published_count += 1

        if self.publish_once:
            self.get_logger().info("Published 1 message as requested. Exiting.")
            rclpy.shutdown()


def main():
    parser = argparse.ArgumentParser(description="Publish test Plan messages to /solution/plan")
    parser.add_argument("--file", "-f", required=True, help="Path to YAML plan file")
    parser.add_argument("--rate", "-r", type=float, default=10.0, help="Publish rate in Hz (default: 10.0)")
    parser.add_argument("--live-stamps", action="store_true", help="Update timestamps dynamically to match simulation time")
    parser.add_argument("--once", "-1", action="store_true", help="Publish single message and exit")

    args = parser.parse_args()

    if not os.path.exists(args.file):
        print(f"Error: File not found: {args.file}", file=sys.stderr)
        sys.exit(1)

    rclpy.init()
    node = TestPlanPublisher(args.file, args.rate, args.live_stamps, args.once)
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, rclpy.executors.ExternalShutdownException):
        pass
    finally:
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
