#include "ros/ros.h"            // Include the main ROS header file
#include "std_msgs/String.h"    // Include the String message type from std_msgs

#include <sstream>              // Include the stringstream library for creating strings 

/**
 * The main function initializes the ROS system, publishes to the "chatter" topic, 
 * and enters a loo, sending multiple messages.
 */
int main(int argc, char **argv)
{
    // Initialize the ROS system and become a ROS node named "talker"
    ros::init(argc, argv, "talker");

    // Create a handle to this proccess' node
    ros::NodeHandle n;

    // Create a publisher object that will publish messages of type std_msgs::String
    // on the "chatter" topic. The second parameter is the queue size.
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    // Set a loop rate of 1 Hz (1 message per second)
    ros::Rate loop_rate(1.0);

    int count = 0;  // Initialize a counter variable

    // Keep running until ROS is shut down
    while (ros::ok())
    {
        std_msgs::String msg;   // Create a new String message object 

        std::stringstream ss;   // Create a stringstream object to construct the message
        ss << "hello world " << count;
        msg.data = ss.str();    // Assign the string data to the message

        // Log the message to the "chatter" topic
        ROS_INFO("%s", msg.data.c_str());

        // Publish the message to the "chatter" topic
        chatter_pub.publish(msg);

        // Allow ROS to process incoming messages and callbacks
        ros::spinOnce();
        
        // Increment the counter
        ++count;

        // Sleep for the remaining time to enforce the loop rate
        loop_rate.sleep();
    }
    
    return 0;
}