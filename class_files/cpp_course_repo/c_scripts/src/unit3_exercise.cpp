#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <list>



std::list<float> move_and_inform(RosbotClass& rosbot, int n_secs){
  rosbot.move_forward(n_secs);
  auto x = rosbot.get_position(1);
  auto y = rosbot.get_position(2);
  return std::list<float>{x,y};
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;
  
  auto pose_after_move = move_and_inform(rosbot,3);
  ROS_INFO_STREAM("Position after moving....");
  for (auto val:pose_after_move){
    ROS_INFO_STREAM(val);
  }

  return 0;
}