#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <map>

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  std::map<double, float> robot_positions;
  RosbotClass rosbot;
  rosbot.move();

  auto x1 = rosbot.get_position(1);
  auto timestamp = rosbot.get_time();

  robot_positions.insert(std::make_pair(timestamp,x1));

  rosbot.move();

  x1 = rosbot.get_position(1);
  timestamp = rosbot.get_time();

  robot_positions.insert(std::make_pair(timestamp,x1));

  for (auto& [key,value]:robot_positions){
    ROS_INFO_STREAM("X: "<<value<<" at timestamp ["<<key<<"]\n");
  }

  return 0;
}