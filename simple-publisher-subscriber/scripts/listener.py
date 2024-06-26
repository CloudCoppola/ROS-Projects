#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def callback(data):
    """Receives messages from the 'chatter' topic and logs them.
    
    Args:
        data (std_msgs.msg.String): The message received from the 'chatter' topic.
    """
    rospy.loginfo(rospy.get_caller_id() + " I heard %s", data.data)

def listener():
    """Initializes a ROS node named 'listener' and subscribes to the 'chatter' topic.
    """
    # Initialize the ROS node named 'listener'
    rospy.init_node('listener', anonymous=True)

    # Create a subscriber that will recieve messages from the 'chatter' topic
    rospy.Subscriber('chatter', String, callback)

    # Simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    try:
        listener()
    except rospy.ROSInterruptException:
        pass