#include "ros/ros.h"            // Include the main ROS header file
#include "std_msgs/String.h"    // Include the String message type from std_msgs

/**
 * This callback funciton is called whenever a new message is recieved on the "chatter" topic.
 * The recieved message is passed as a shared pointer (ConstPtr) to the function. 
 * It logs the message data to the ROS console.
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    // Log the recieved message to the ROS console
    ROS_INFO("I heard [%s]", msg->data.c_str());
}

/**
 * The main function initializes the ROS system, subscribes to the "chatter" topic, 
 * and enters a loop, pumping callbacks.
 */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

    ros::spin();

    return 0;
}