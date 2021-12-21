#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;
  rosbot.move();

  auto x1 = rosbot.get_position(1);
  auto y1 = rosbot.get_position(2);

  ROS_INFO_STREAM("X: "<<x1<<" Y: "<<y1);

  rosbot.move();

  auto x2 = rosbot.get_position(1);
  auto y2 = rosbot.get_position(2);


  ROS_INFO_STREAM("X: "<<x2<<" Y: "<<y2);

  return 0;
}