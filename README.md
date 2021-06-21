# Home Service Robot
This project simulate a full home service robot capable of navigating to pick up and deliver virtual objects. 

## Dependencies for Running Locally
* [AMCL Package](http://wiki.ros.org/amcl)
    * Use Adaptive Monte Carlo Localization (AMCL) as a localization method. In this implement, we subscribe the sensor information from gazebo, input the predefined map, and identify the robot's location.
* [gmapping](http://wiki.ros.org/gmapping) 
    * Perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.
* [turtlebot_navigation](http://wiki.ros.org/turtlebot_navigation)
    * Perform several path planning methods via ROS navigation stack. In this implement, we used a predefined map and a manually identified goal as input, then generate the path via Dijkstra's algorithm.
* [turtlebot_teleop](http://wiki.ros.org/turtlebot_teleop)
    * Manually control a robot using keyboard commands. If you want to manually control the robot rather than automatically find the goal, please run via `./test_slam.sh`
* [turtlebot_rviz_launchers](http://wiki.ros.org/turtlebot_rviz_launchers)
    * Load a preconfigured rviz workspace. It will automatically load the robot model, trajectories, and map.
* [turtlebot_gazebo](http://wiki.ros.org/turtlebot_gazebo)
    * Deploy a turtlebot in a gazebo environment by linking the world file to it.

## Basic Build Instructions

1. Clone this repo.
2. Move to catkin workspace: `cd catkin_ws/`
3. Compile: `catkin_make -j1`
4. Run it: `./home_service.sh`
