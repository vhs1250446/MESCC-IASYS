# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target roadwork_solution_msgs::roadwork_solution_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${roadwork_solution_msgs_TARGETS}.
if(roadwork_solution_msgs_TARGETS AND NOT TARGET roadwork_solution_msgs::roadwork_solution_msgs)
  add_library(roadwork_solution_msgs::roadwork_solution_msgs INTERFACE IMPORTED)
  set_target_properties(roadwork_solution_msgs::roadwork_solution_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${roadwork_solution_msgs_TARGETS}")
endif()
