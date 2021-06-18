#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <marker_msg/status.h>
#include <ros/ros.h>
#include <std_msgs/String.h>

class goal_msg {
   private:
    move_base_msgs::MoveBaseGoal goal_;

   public:
    goal_msg() {
        // set up the frame parameters
        goal_.target_pose.header.frame_id = "map";
        goal_.target_pose.header.stamp = ros::Time::now();
    }
    void set_goal(double x, double y, double w) {
        goal_.target_pose.pose.position.x = x;
        goal_.target_pose.pose.position.y = y;
        goal_.target_pose.pose.orientation.w = w;
    }
    move_base_msgs::MoveBaseGoal get_goal() {
        return goal_;
    }
};

class pick_objects {
   private:
    ros::NodeHandle n_;
    ros::Publisher pub_status_;
    ros::Publisher pub_loc_;

   public:
    pick_objects() {
        //Topic to publish what the status of the marker should be
        pub_status_ = n_.advertise<marker_msg::status>("marker_status", 1);
        pub_loc_ = n_.advertise<move_base_msgs::MoveBaseGoal>("marker_location", 1);
    }

    //Public method to publish the marker status
    void publish(marker_msg::status status_message) {
        pub_status_.publish(status_message);
    }
};

//Client to send navigation goals to MoveBase server
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv) {
    // Initialize the simple_navigation_goals node
    ros::init(argc, argv, "pick_objects");

    //Variables to hold current message
    marker_msg::status msg;
    std::string status;

    //Instance of publisher class
    pick_objects po_pub;

    //tell the action client that we want to spin a thread by default
    MoveBaseClient ac("move_base", true);

    // Wait 5 sec for move_base action server to come up
    while (!ac.waitForServer(ros::Duration(5.0))) {
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    //Create pickup navigation goal
    goal_msg pickup;
    pickup.set_goal(1.5, 1, 3.14);
    //Create drop off navigation goal
    goal_msg drop_off;
    drop_off.set_goal(3, 2, 1);

    //Publish initial status
    status = "Pickup";
    msg.status = status;
    msg.x = 1.5;
    msg.y = 1;
    msg.w = 3.14;
    po_pub.publish(msg);

    // Send the goal position for object pickup
    ROS_INFO("Robot is traveling to the pick up location.");
    ac.sendGoal(pickup.get_goal());

    // Wait an infinite time for the results
    ac.waitForResult();

    // Check if the robot reached the pickup location
    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
        ROS_INFO("Robot has picked up object");

        //Publish updated status
        status = "Invisible";
        msg.status = status;
        po_pub.publish(msg);

        // Wait 5 seconds to simulate object pick up
        ros::Duration(5.0).sleep();

        //Send new goal position for object drop off
        ROS_INFO("Robot is traveling to the drop off location");
        ac.sendGoal(drop_off.get_goal());

        // Wait an infinite time for the results
        ac.waitForResult();

        // Check if the robot reached the pickup location
        if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
            ROS_INFO("Robot has dropped off the object");

            //Publish updated status
            status = "Dropped";
            msg.status = status;
            msg.x = 3;
            msg.y = 2;
            msg.w = 1;
            po_pub.publish(msg);

            //Wait 5 seconds to simulate drop off
            ros::Duration(5.0).sleep();
        } else {
            ROS_INFO("Robot could not drop off the object");
        }
    } else {
        ROS_INFO("Robot could not pick up the object");
    }

    return 0;
}