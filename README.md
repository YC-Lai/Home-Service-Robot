# Home Service Robot
This project simulate a full home service robot capable of navigating to pick up and deliver virtual objects. 

## Dependencies for Running Locally
* [AMCL Package](http://wiki.ros.org/amcl)
    * use Adaptive Monte Carlo Localization (AMCL) as localization method. AMCL dynamically adjusts the number of particles over a period of time, as the robot navigates around in a map.
* [gmapping](http://wiki.ros.org/gmapping) 
    * perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.
* [turtlebot_navigation](http://wiki.ros.org/turtlebot_navigation)
    * perform several path planning method via ROS navigation stack.
* [turtlebot_teleop](http://wiki.ros.org/turtlebot_teleop)
    * manually control a robot using keyboard commands.
* [turtlebot_rviz_launchers](http://wiki.ros.org/turtlebot_rviz_launchers)
    * load a preconfigured rviz workspace. It will automatically load the robot model, trajectories, and map.
* [turtlebot_gazebo](http://wiki.ros.org/turtlebot_gazebo)
    * deploy a turtlebot in a gazebo environment by linking the world file to it.

## Basic Build Instructions

1. Clone this repo.
2. Move to catkin workspace: `cd catkin_ws/`
3. Compile: `catkin_make -j1`
4. Run it: `./home_service.sh`
