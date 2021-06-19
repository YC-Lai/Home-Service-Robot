cmake_minimum_required(VERSION 2.8.3)
project(marker_msg)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
)

#include_directories(include)

#########################
##       MESSAGE       ##
#########################
add_message_files(
  FILES
  status.msg
)
##########################
##       SERVICE        ##
##########################

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  #INCLUDE_DIRS include
  CATKIN_DEPENDS message_runtime std_msgs)

install(DIRECTORY include/${PROJECT_NAME}/
DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
FILES_MATCHING PATTERN "*.h")