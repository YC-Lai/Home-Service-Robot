#!/bin/sh
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/Home-Service-Robot/catkin_ws/src/my_robot/worlds/UdacityOffice.world
export TURTLEBOT_GAZEBO_MAP_FILE=/home/workspace/Home-Service-Robot/catkin_ws/src/my_robot/maps/map.yaml
export ROBOT_INITIAL_POSE="-x -4 -y 2 -Y 0"

xterm -e " source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
xterm -e " source devel/setup.bash; roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5
xterm -e " source devel/setup.bash; roslaunch turtlebot_teleop keyboard_teleop.launch" &
sleep 5
xterm -e " source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch"