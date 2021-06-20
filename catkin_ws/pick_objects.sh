#!/bin/sh
export TURTLEBOT_GAZEBO_WORLD_FILE="$(rospack find my_robot)/worlds/UdacityOffice.world"
export TURTLEBOT_GAZEBO_MAP_FILE="$(rospack find my_robot)/maps/map.yaml"
export ROBOT_INITIAL_POSE="-x -4 -y 2 -Y 0"

xterm -e " source devel/setup.bash" &
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5
xterm -e " source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " source devel/setup.bash; rosrun pick_objects pick_objects "
