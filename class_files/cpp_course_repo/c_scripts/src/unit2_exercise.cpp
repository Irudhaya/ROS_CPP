#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>


int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;
  
  /*rosbot.move_forward(5);

  auto x = rosbot.get_position(1);

  while (x<1.0){
    rosbot.move_backwards(2);
  }

  rosbot.stop_moving();*/

  rosbot.move();
  auto robot_coordinates = rosbot.get_position_full();

  for (const auto& coord: robot_coordinates){
    ROS_INFO_STREAM(coord);
  }

  return 0;
}