#!/bin/sh
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/catkin_ws/src/my_robot/worlds/UdacityOffice.world
export TURTLEBOT_GAZEBO_MAP_FILE=/home/workspace/catkin_ws/src/my_robot/map/map.yaml
xterm -e " source devel/setup.bash" &
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5
xterm -e " source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " source devel/setup.bash; rosrun pick_objects pick_objects "
