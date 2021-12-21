#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <list>
#include <string>



std::list<float> move_and_inform(RosbotClass& rosbot, int n_secs, std::string rot_direction){
  rosbot.move_forward(n_secs);
  rosbot.turn(rot_direction,n_secs);
  rosbot.move_forward(2);
  rosbot.turn(rot_direction,2);
  rosbot.move_forward(2);
 
  auto x = rosbot.get_position(1);
  auto y = rosbot.get_position(2);
  return std::list<float>{x,y};
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;
  
  auto pose_after_move = move_and_inform(rosbot,3,"clockwise");
  ROS_INFO_STREAM("Position after moving....");
  for (auto val:pose_after_move){
    ROS_INFO_STREAM(val);
  }

  return 0;
}