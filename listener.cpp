#include "ros/ros.h"
#include "std_msgs/String.h"
// Topic messages callback function
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("[Listener] I heard: [%s]\n", msg->data.c_str());
}

int main(int argc, char **argv)
{
    // Initiate the  new ROS node named listener
	ros::init(argc, argv, "listener_node");
	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle node;
    // Subscribe to a given topic name chatter
	//chatterCallback function will be executed each time a message is received.
    ros::Subscriber sub = node.subscribe("chatter", 1000, chatterCallback);
 // Enter a loop, pumping callbacks
    ros::spin();
	return 0;
}
