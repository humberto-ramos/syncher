//
// Created by humberto on 5/30/19.
//

#ifndef XYZ_TRACKER_SYNCHRONIZER_NODE_H
#define XYZ_TRACKER_SYNCHRONIZER_NODE_H

#endif //XYZ_TRACKER_SYNCHRONIZER_NODE_H

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include "opencv2/highgui/highgui.hpp"
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <sensor_msgs/Image.h>
#include <iostream>
#include "syncher/SyncImages.h"
using namespace sensor_msgs;
using namespace message_filters;

namespace syncher
{

    class Syncher {
    public:
        Syncher();
        ~Syncher();
        double dt;
        double previous_time;
        double current_time;

    private:

        void callback(const ImageConstPtr &camera_image, const ImageConstPtr &camera1_image,const ImageConstPtr &boson_image);
        ros::NodeHandle nh_;
        ros::NodeHandle private_nh_;
        typedef message_filters::Subscriber<Image> camera_sub;
        camera_sub camera_subs;
        typedef message_filters::Subscriber<Image> camera1_sub;
        camera1_sub camera1_subs;
        typedef message_filters::Subscriber<Image> boson_sub;
        boson_sub boson_subs;
        typedef sync_policies::ApproximateTime<Image, Image,Image> MySyncPolicy;
        message_filters::Synchronizer<MySyncPolicy> sync;

        ros::Publisher frames_publisher_;

    };

}

