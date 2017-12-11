
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include "geometry_msgs/PoseStamped.h"
// #include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/move_group_interface/move_group_interface.h>
// #include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
// #include <moveit_msgs/AttachedCollisionObject.h>
// #include <moveit_msgs/CollisionObject.h>

class SimpleGrasping {
private:
	ros::NodeHandle nh_;
	geometry_msgs::Pose target_pose1;
	moveit::planning_interface::MoveGroupInterface group;
	// ros::Publisher display_publisher;
	// moveit_visual_tools::MoveItVisualTools visual_tools;
	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;

    // For testing move_group
	bool tried_once;

	void attainPosition();
public:
	SimpleGrasping(ros::NodeHandle n_);
	void imageCb(const sensor_msgs::ImageConstPtr& msg);
};