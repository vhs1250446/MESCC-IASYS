cmake_minimum_required(VERSION 3.8)
project(roadwork_student)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(roadwork_interfaces REQUIRED)
find_package(roadwork_solution_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sense_node src/sense_node.cpp)
ament_target_dependencies(sense_node rclcpp roadwork_solution_msgs)
install(TARGETS sense_node DESTINATION lib/${PROJECT_NAME})

# Pure Plan logic (no node, no clock): linked by plan_node and the gtests.
add_library(plan_logic STATIC src/path_builder.cpp src/plan_decision.cpp)
target_include_directories(plan_logic PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
ament_target_dependencies(plan_logic roadwork_solution_msgs builtin_interfaces)

add_executable(plan_node src/plan_node.cpp)
target_link_libraries(plan_node plan_logic)
ament_target_dependencies(plan_node rclcpp nav_msgs std_msgs roadwork_solution_msgs)
install(TARGETS plan_node DESTINATION lib/${PROJECT_NAME})

# Pure Act logic (no node, no clock): linked by act_node and, later, by the gtests.
add_library(act_logic STATIC src/act_validator.cpp src/pure_pursuit.cpp src/command_limiter.cpp)
target_include_directories(act_logic PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
ament_target_dependencies(act_logic nav_msgs roadwork_solution_msgs geometry_msgs builtin_interfaces)

add_executable(act_node src/act_node.cpp)
target_link_libraries(act_node act_logic)
ament_target_dependencies(act_node rclcpp nav_msgs roadwork_interfaces roadwork_solution_msgs)
install(TARGETS act_node DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY config DESTINATION share/${PROJECT_NAME})
install(DIRECTORY test_data DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_path_builder test/test_path_builder.cpp)
  target_link_libraries(test_path_builder plan_logic)
  ament_add_gtest(test_plan_decision test/test_plan_decision.cpp)
  target_link_libraries(test_plan_decision plan_logic)
endif()

ament_package()