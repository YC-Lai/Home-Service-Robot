#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>

class add_markers {
   private:
    ros::NodeHandle n_;
    ros::Publisher pub_;

    void setMarkerPosition(double x, double y);
    void toggleVisibility();

   public:
    add_markers();

    visualization_msgs::Marker marker;

    //Function to publish marker
    void PublishMarker();
};

add_markers::add_markers() {
    //Publisher
    pub_ = n_.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type to cylinder
    marker.type = visualization_msgs::Marker::CUBE;

    // Add the marker
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker
    marker.scale.x = 0.2;
    marker.scale.y = 0.2;
    marker.scale.z = 0.25;

    // Set the color
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();
}

void add_markers::PublishMarker() {
    // publish at the pickup zone
    this->setMarkerPosition(1.5, 1);
    pub_.publish(marker);
    ros::Duration(5.0).sleep();
    this->toggleVisibility();

    // publish at the drop off zone
    ros::Duration(5.0).sleep();
    this->setMarkerPosition(3, 2);
    pub_.publish(marker);
    this->toggleVisibility();
}

void add_markers::setMarkerPosition(double x, double y) {
    // Set the pose of the marker
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = 0.0;
}

void add_markers::toggleVisibility() {
    if (marker.color.a == 1.0) {
        marker.color.a = 0.0;
    } else
        marker.color.a = 1.0;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "add_markers");

    //Call add_markers constructor
    add_markers newAddMarkers;

    newAddMarkers.PublishMarker();

    ros::spin();

    return 0;
}