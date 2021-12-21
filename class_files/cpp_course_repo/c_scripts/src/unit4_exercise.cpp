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
  
  float* laser_values_start;
  laser_values_start = rosbot.get_laser_full();

  auto laser_values_end = laser_values_start + 720;
  //ROS_INFO_STREAM(laser_values_start+720);
  ros::Duration(1).sleep();
  ROS_INFO_STREAM("The lase values are....");
  int i{0};
  while(laser_values_start!=laser_values_end){
  	//ROS_INFO_STREAM(laser_values_start<<","<<laser_values_end<<"---> Counter: "<<i++<<"\n");
  	ROS_INFO_STREAM(*laser_values_start<<"--> Counter: "<<++i<<"\n");
  	laser_values_start++;
  	ros::Duration(0.1).sleep();
  }
  return 0;
}