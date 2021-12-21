#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <map>

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  //std::map<double, float> robot_positions;
  RosbotClass rosbot;
  rosbot.move();

  auto x_start = rosbot.get_position(1);
  auto timestamp_start = rosbot.get_time();

  //robot_positions.insert(std::make_pair(timestamp,x1));

  rosbot.move();

  auto x_end = rosbot.get_position(1);
  auto timestamp_end = rosbot.get_time();

  auto speed = (x_end - x_start)/(timestamp_end-timestamp_start);

  ROS_INFO_STREAM("Is Velocity along x-axis less than 1m/s?\n"<<(speed<1)<<"\n");
  //robot_positions.insert(std::make_pair(timestamp,x1));

/*  for (auto& [key,value]:robot_positions){
    ROS_INFO_STREAM("X: "<<value<<" at timestamp ["<<key<<"]\n");
  }*/

  return 0;
}