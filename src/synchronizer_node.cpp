//
// Created by humberto on 5/30/19.
//
#include "ros/ros.h"
#include "synchronizer.h"
int main(int argc, char** argv)
{
    ros::init(argc, argv, "synchronizer_node");

    while(ros::ok()){
        syncher::Syncher synchronizer;
        ros::spin();
    }
        return 0;
}
