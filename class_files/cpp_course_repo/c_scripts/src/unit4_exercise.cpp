#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <array>



int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;
  ros::Duration(2).sleep();//waiting to get the laser readings
  std::array<float,2> laser_readings{rosbot.get_laser(121),rosbot.get_laser(431)};
  
  ROS_INFO_STREAM("RObot is "<<laser_readings[0]<<" from the right wall....\n");
  ROS_INFO_STREAM("RObot is "<<laser_readings[1]<<" from the left wall....\n");
  

  return 0;
}