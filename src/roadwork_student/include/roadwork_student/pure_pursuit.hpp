#pragma once
#include <cstddef>
#include <cstdint>
#include "geometry_msgs/msg/quaternion.hpp"
#include "roadwork_solution_msgs/msg/plan.hpp"

namespace roadwork_student {
    using Path = roadwork_solution_msgs::msg::Plan::_path_type;

    struct Pose2D { double x; double y; double yaw; };

    struct PurePursuitParams {
        double wheelbase;
        double lookahead_gain;  //s, Ld = gain * v
        double lookahead_min;   //m
        double lookahead_max;   //m
        double speed_preview;   //m
    };

    struct PathProjection {
        std::size_t segment;      // index i of segment path[i] -> path[i+1]
        double t;                 // 0..1 position along that segment
        double px, py;            // closest point on the path
        double path_heading;      // rad, direction of that segment
        double cross_track_error; // m, + = vehicle left of path
    };

    struct TrackingOutput {
        double steering;                    // rad, RAW
        double speed;                       // m/s, RAW target from the profile
        double cross_track_error;           // m
        double heading_error;               // rad, wrapped to [-pi, pi]
        uint32_t nearest_index;             // closest vertex, for ActStatus.target_index
        double lookahead_x, lookahead_y;    // handy for debugging/plots
    };

    double yaw_from_quaternion(const geometry_msgs::msg::Quaternion & q);
    double wrap_angle(double a);
    PathProjection project_onto_path(const Path & path, double x, double y);
    void point_at_distance(const Path & path, const PathProjection & from, double distance, double & out_x, double & out_y);
    double speed_at_distance(const Path & path, const PathProjection & from, double distance);
    double pure_pursuit_steering(const Pose2D & pose, double tx, double ty, double wheelbase);

    TrackingOutput track_path(const Path & path, const Pose2D & pose, double v, const PurePursuitParams & p);
}