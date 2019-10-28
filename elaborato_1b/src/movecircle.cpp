#include "ros/ros.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char **argv) {
  // Initialization
  ros::init(argc, argv, "movecircle");
  ros::NodeHandle n;
  
  // Publisher
  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

  // Message
  geometry_msgs::Twist msg;
  msg.linear.x = 3;
  //msg.linear.y = 0;   // Default, 0
  //msg.linear.z = 0;
  //msg.angular.x = 0;
  //msg.angular.y = 0;
  msg.angular.z = 4;

  // Loop at 10Hz
  ros::Rate loop_rate(10);
  ROS_INFO("Moving...");

  while (ros::ok()) {
    pub.publish(msg);
    loop_rate.sleep();
  }

  return 0;
}
