//
// Created by humberto on 5/30/19.
//

#include <synchronizer.h>
namespace syncher{
    //Initialize and bind the topics
Syncher::Syncher():private_nh_("~"), nh_(""),
    camera_subs(nh_, "/camera/image_raw", 1),
    camera1_subs(nh_, "/camera1/image_raw", 1),
    boson_subs(nh_,"/boson/image_raw",1),
    // ApproximateTime takes a queue size as its constructor argument, hence MySyncPolicy(10)
    sync(MySyncPolicy(10), camera_subs, camera1_subs, boson_subs)
{
    //register the sync callback
    sync.registerCallback(boost::bind(&Syncher::callback, this, _1, _2, _3));
    //initialize variables
    dt = 0.0;
    previous_time = 0;
}
Syncher::~Syncher(){}

void Syncher::callback(const ImageConstPtr &camera_image, const ImageConstPtr &camera1_image,const ImageConstPtr &boson_image){
    //These printing statements are just to check what the resulting frequency is.
    ROS_INFO("Time stamp camera = %f",camera_image->header.stamp.toSec());
    current_time = camera_image->header.stamp.toSec() ;
    ROS_INFO("Time stamp camera1 = %f",camera1_image->header.stamp.toSec());
    ROS_INFO("Time stamp boson = %f",boson_image->header.stamp.toSec());
        dt = current_time - previous_time;
        ROS_INFO("DT= %f",dt);
        previous_time = current_time;
        //From here you can write what you need to do with the synchronized images.
        //It is not optimal, but you could potentially republish the images but now
        //at a unified frequency/time_stamp.

}


}