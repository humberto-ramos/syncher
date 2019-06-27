//
// Created by humberto on 5/30/19.
//

#include <synchronizer.h>
namespace syncher {
    //Initialize and bind the topics
    Syncher::Syncher() : private_nh_("~"), nh_(""),
<<<<<<< HEAD
                         nir_sub(nh_, "/NIR/image_raw/compressed", 1),
                         thermal_sub(nh_, "/THRM/image_raw/compressed", 1),
                         rgb_sub(nh_, "/RGB/image_raw/compressed", 1),
            // ApproximateTime takes a queue size as its constructor argument, hence MySyncPolicy(10)
                         sync(MySyncPolicy(10), nir_sub, thermal_sub, rgb_sub) {
=======
                         RGB_subs(nh_, "/RGB/image_raw/compressed", 1),
                         NIR_subs(nh_, "/NIR/image_raw/compressed", 1),
                         THRM_subs(nh_,"/THRM/image_raw/compressed", 1),
            // ApproximateTime takes a queue size as its constructor argument, hence MySyncPolicy(10)
                         sync(MySyncPolicy(10), RGB_subs, NIR_subs, THRM_subs) {
>>>>>>> 388b967044553adfb4f805f0e0fe6af640084621
        //register the sync callback
        sync.registerCallback(boost::bind(&Syncher::callback, this, _1, _2, _3));
        //initialize variables
        dt = 0.0;
        previous_time = 0;
        frames_publisher_ = nh_.advertise<syncher::SyncImages>("images_synchronized", 1, true);
        nir_publisher_ = nh_.advertise<sensor_msgs::CompressedImage>("images_synchronized/NIR/image_raw/compressed", 1, true);
        thermal_publisher_ = nh_.advertise<sensor_msgs::CompressedImage>("images_synchronized/THRM/image_raw/compressed", 1, true);
        rgb_publisher_ = nh_.advertise<sensor_msgs::CompressedImage>("images_synchronized/RGB/image_raw/compressed", 1, true);
    }

    Syncher::~Syncher() {}

<<<<<<< HEAD
    void Syncher::callback(const CompressedImageConstPtr &nir_image, const CompressedImageConstPtr &thermal_image,
                           const CompressedImageConstPtr &rgb_image) {
        //These printing statements are just to check what the resulting frequency is.
//        ROS_INFO("Time stamp camera = %f", camera_image->header.stamp.toSec());
//        current_time = camera_image->header.stamp.toSec();
//        ROS_INFO("Time stamp camera1 = %f", camera1_image->header.stamp.toSec());
//        ROS_INFO("Time stamp boson = %f", boson_image->header.stamp.toSec());
//        dt = current_time - previous_time;
//        ROS_INFO("DT= %f", dt);
=======
    void Syncher::callback(const CompressedImageConstPtr &RGB_image, const CompressedImageConstPtr &NIR_image,
                           const CompressedImageConstPtr &THRM_image) {
        //These printing statements are just to check what the resulting frequency is.
        ROS_INFO("Time stamp RGB = %f", RGB_image->header.stamp.toSec());
        current_time = RGB_image->header.stamp.toSec();
        ROS_INFO("Time stamp NIR = %f", NIR_image->header.stamp.toSec());
        ROS_INFO("Time stamp THRM = %f", THRM_image->header.stamp.toSec());
        dt = current_time - previous_time;
        ROS_INFO("DT= %f", dt);
>>>>>>> 388b967044553adfb4f805f0e0fe6af640084621
        previous_time = current_time;
        //From here you can write what you need to do with the synchronized images.
        //It is not optimal, but you could potentially republish the images but now
        //at a unified frequency/time_stamp.
        syncher::SyncImages syncImages;
<<<<<<< HEAD
//        syncImages.header = camera_image->header;
        syncImages.camera = *nir_image;
        syncImages.camera1 = *thermal_image;
        syncImages.boson = *rgb_image;
//        frames_publisher_.publish(syncImages); // This is a better way to do it.

        //For now I will just give you what you ask me.
        nir_publisher_.publish(*nir_image);
        thermal_publisher_.publish(*thermal_image);
        rgb_publisher_.publish(*rgb_image);
=======
        syncImages.header = RGB_image->header;
        syncImages.RGB = *RGB_image;
        syncImages.NIR = *NIR_image;
        syncImages.THRM = *THRM_image;
        frames_publisher_.publish(syncImages);
>>>>>>> 388b967044553adfb4f805f0e0fe6af640084621


    }
}
