cmake_minimum_required(VERSION 3.8)
project(roadwork_student)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(roadwork_interfaces REQUIRED)
find_package(roadwork_solution_msgs REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

foreach(stage sense plan)
  add_executable(${stage}_node src/${stage}_node.cpp)
  ament_target_dependencies(${stage}_node rclcpp roadwork_solution_msgs)
  install(TARGETS ${stage}_node DESTINATION lib/${PROJECT_NAME})
endforeach()

add_executable(act_node src/act_node.cpp)
ament_target_dependencies(act_node rclcpp nav_msgs roadwork_interfaces roadwork_solution_msgs)
install(TARGETS act_node DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY config DESTINATION share/${PROJECT_NAME})

ament_package()