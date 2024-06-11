#!/usr/bin/env python

import rospy
from std_msgs.msg import String 

def talker():
    """Initalizes a ROS node named 'talker' and continuosly publishes
    messages to the 'chatter' topic at a rate of 10hz.
    """
    # Initialize the ROS node named 'talker'
    rospy.init_node('talker', anonymous=True)
    
    # Create a publisher that will send messages to the 'chatter' topic
    pub = rospy.Publisher('chatter', String, queue_size=10)
    
    # Set the rate at which messages will be published (10hz)
    rate = rospy.Rate(10) # 10hz

    i = 0

    # Main loop: Keep publishing until ROS is shutdown
    while not rospy.is_shutdown():
        # Create a string with the current time
        # hello_str = "Hello, World %s" % rospy.get_time()
        hello_str = "'Hello World %s'" % i


        # Log the message to the ROS log
        rospy.loginfo(hello_str)

        # Publish the message to the 'chatter' topic
        pub.publish(hello_str)

        i += 1

        # Sleep for the remaining time to enforce the loop rate
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass