cmake_minimum_required(VERSION 3.8)
project(roadwork_solution_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/PlanPoint.msg"
  "msg/Plan.msg"
  "msg/ActStatus.msg"
  "msg/PlanStatus.msg"
  "msg/Scene.msg"
  # "msg/SenseStatus.msg"  -- deferred to D2; fields covered by sense_state + stale_flags on Scene
  DEPENDENCIES std_msgs builtin_interfaces
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
