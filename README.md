# Home Service Robot
This project simulates a full home service robot capable of navigating to pick up and deliver virtual objects, which show as a blue cube. As start, robot will drive into the pickup zone, and pick the object up (wait 5 seconds to simulate a pickup, and then hide the object). After reaching the pickup zone, the robot will move to the drop off zone, and the object will show again.

## Basic Idea
The home service robot is a **SLAM** system covering **localization, mapping, and navigation**.
* **Localization:** we use Adaptive Monte Carlo Localization (***AMCL***) as a localization method. Take laser scans and the predefined map as input, then identify the robot's location through AMCL.

* **Mapping:** using ***Gampping package*** to perform SLAM,  build a map of the environment via a robot equipped with laser range finder sensors or RGB-D cameras.

* **Navigation:** we used a predefined map and a manually identified goal as input, then generate the path via ***Dijkstra's algorithm***.

## Dependencies
* [AMCL Package](http://wiki.ros.org/amcl)
* [gmapping](http://wiki.ros.org/gmapping) 
* [turtlebot_navigation](http://wiki.ros.org/turtlebot_navigation)
* [turtlebot_teleop](http://wiki.ros.org/turtlebot_teleop)
* [turtlebot_rviz_launchers](http://wiki.ros.org/turtlebot_rviz_launchers)
* [turtlebot_gazebo](http://wiki.ros.org/turtlebot_gazebo)


## Basic Build and Run

```
git clone git@github.com:YC-Lai/Home-Service-Robot.git
cd catkin_ws/
catkin_make -j1
```
## Usage
* **Home Service Robot:** `./home_service.sh`
* **SLAM Testing (control it with keyboard commands):** `./test_slam.sh`

## License
Home-Service-Robot is a public domain work. Feel free to do whatever you want with it.