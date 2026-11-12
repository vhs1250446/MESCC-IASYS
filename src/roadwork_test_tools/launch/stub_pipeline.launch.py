# TEST / DEMO ONLY: simulator + scene_stub + plan_node + act_node in one command.
#
# scene_stub replaces the Sense node: it publishes a scripted Scene (fixed beacon
# geometry, panel STOP until `go_after` s, then GO) and reads no camera, LiDAR or
# beacon. A run with this launch does NOT demonstrate perception and is not a
# graded configuration; the graded one is roadwork_sim/challenge.launch.py with
# student:=true (exactly three solution nodes).
#
# Usage:
#   ros2 launch roadwork_test_tools stub_pipeline.launch.py scenario:=2 go_after:=10.0
#   ros2 launch roadwork_test_tools stub_pipeline.launch.py scenario:=1 work_shift:=-2.0 rviz:=false
#
# Plan and Act load their YAML parameters here (challenge.launch.py passes only
# use_sim_time), so config/plan.yaml and config/act.yaml edits take effect.
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    defaults = dict(scenario='1', seed='1', work_shift='0.0', traffic_speed='3.0',
                    noise='0.02', rviz='true', visualize='true',
                    result_path='roadwork_result.json', go_after='0.0')
    args = [DeclareLaunchArgument(k, default_value=v) for k, v in defaults.items()]
    cfg = {k: LaunchConfiguration(k) for k in defaults}

    sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(
            get_package_share_directory('roadwork_sim'), 'launch', 'challenge.launch.py')),
        launch_arguments={
            'scenario': cfg['scenario'], 'seed': cfg['seed'], 'work_shift': cfg['work_shift'],
            'traffic_speed': cfg['traffic_speed'], 'noise': cfg['noise'], 'rviz': cfg['rviz'],
            'visualize': cfg['visualize'], 'result_path': cfg['result_path'],
            'student': 'false',  # the challenge launch must not start its own sense/plan/act
        }.items())

    student_cfg = os.path.join(get_package_share_directory('roadwork_student'), 'config')

    scene_stub = Node(
        package='roadwork_test_tools', executable='scene_stub', output='screen',
        parameters=[{
            'use_sim_time': True,
            # value_type=float: "0" or "-2" on the command line would otherwise be an
            # int and the double parameter declaration would reject it.
            'go_after': ParameterValue(cfg['go_after'], value_type=float),
            'work_shift': ParameterValue(cfg['work_shift'], value_type=float),
        }])
    plan = Node(
        package='roadwork_student', executable='plan_node', name='plan', output='screen',
        parameters=[os.path.join(student_cfg, 'plan.yaml'), {'use_sim_time': True}])
    act = Node(
        package='roadwork_student', executable='act_node', name='act', output='screen',
        parameters=[os.path.join(student_cfg, 'act.yaml'), {'use_sim_time': True}])

    return LaunchDescription(args + [sim, scene_stub, plan, act])
