# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target roadwork_interfaces::roadwork_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${roadwork_interfaces_TARGETS}.
if(roadwork_interfaces_TARGETS AND NOT TARGET roadwork_interfaces::roadwork_interfaces)
  add_library(roadwork_interfaces::roadwork_interfaces INTERFACE IMPORTED)
  set_target_properties(roadwork_interfaces::roadwork_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${roadwork_interfaces_TARGETS}")
endif()
