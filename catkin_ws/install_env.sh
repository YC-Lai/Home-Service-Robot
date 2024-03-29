#!/bin/sh
git clone https://github.com/ros-perception/slam_gmapping &
git clone https://github.com/turtlebot/turtlebot &
git clone https://github.com/turtlebot/turtlebot_interactions &
git clone https://github.com/turtlebot/turtlebot_simulator &
cd ~/catkin_ws/ &
source devel/setup.bash &
rosdep -i install gmapping &
rosdep -i install turtlebot_teleop &
rosdep -i install turtlebot_rviz_launchers &
rosdep -i install turtlebot_gazebo &
catkin_make &
source devel/setup.bash &