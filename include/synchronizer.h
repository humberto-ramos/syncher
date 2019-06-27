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
<<<<<<< HEAD
=======
#include <sensor_msgs/Image.h>
>>>>>>> 388b967044553adfb4f805f0e0fe6af640084621
#include <sensor_msgs/CompressedImage.h>
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

<<<<<<< HEAD
        void callback(const CompressedImageConstPtr &nir_image, const CompressedImageConstPtr &thermal_image,const CompressedImageConstPtr &rgb_image);
        ros::NodeHandle nh_;
        ros::NodeHandle private_nh_;
        typedef message_filters::Subscriber<CompressedImage> nir_subs;
        nir_subs nir_sub;
        typedef message_filters::Subscriber<CompressedImage> thermal_subs;
        thermal_subs thermal_sub;
        typedef message_filters::Subscriber<CompressedImage> rgb_subs;
        rgb_subs rgb_sub;
        typedef sync_policies::ApproximateTime<CompressedImage, CompressedImage,CompressedImage> MySyncPolicy;
=======
        void callback(const CompressedImageConstPtr &RGB_image, const CompressedImageConstPtr &NIR_image, const CompressedImageConstPtr &THRM_image);
        ros::NodeHandle nh_;
        ros::NodeHandle private_nh_;
        typedef message_filters::Subscriber<CompressedImage> RGB_sub;
        RGB_sub RGB_subs;
        typedef message_filters::Subscriber<CompressedImage> NIR_sub;
        NIR_sub NIR_subs;
        typedef message_filters::Subscriber<CompressedImage> THRM_sub;
        THRM_sub THRM_subs;
        typedef sync_policies::ApproximateTime<CompressedImage,CompressedImage,CompressedImage> MySyncPolicy;
>>>>>>> 388b967044553adfb4f805f0e0fe6af640084621
        message_filters::Synchronizer<MySyncPolicy> sync;

        ros::Publisher frames_publisher_;
        ros::Publisher nir_publisher_;
        ros::Publisher thermal_publisher_;
        ros::Publisher rgb_publisher_;

    };

}
