//
// Created by okan on 18.07.2018.
//

#ifndef SURUIHA_GAZEBO_PLUGINS_TRACKING_SCORE_H
#define SURUIHA_GAZEBO_PLUGINS_TRACKING_SCORE_H

#include <sdf/sdf.hh>
#include <gazebo/physics/PhysicsTypes.hh>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <gazebo/common/Time.hh>
#include <nav_msgs/OccupancyGrid.h>
#include <ignition/math/Vector2.hh>
#include <geometry_msgs/Polygon.h>
#include <geometry_msgs/Point32.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <suruiha_gazebo_plugins/UAVTracking.h>
#include <boost/thread/mutex.hpp>

class TrackingScore {
    public: TrackingScore();
    public: ~TrackingScore();

    public: void GetParameters(sdf::ElementPtr worldSdf, sdf::ElementPtr ownSDF);
//    public: void SetRosNodeHandle(ros::NodeHandle* nodeHandle);
//    public: void SetModels(std::map<std::string, gazebo::physics::ModelPtr> _models);
    public: void UpdateStates();
    public: void SetWorld(gazebo::physics::WorldPtr _worldPtr);

//    protected: std::map<std::string, gazebo::physics::ModelPtr> models;
//
//    protected: std::map<std::string, std::pair<float, float> > modelPerceptionHeights;
//    protected: std::map<std::string, ignition::math::Frustum*> modelFrustums;

//    protected: int updateRate;
    protected: gazebo::physics::WorldPtr worldPtr;
//    protected: gazebo::common::Time lastUpdateTime;

//    protected: void AddOccupancy(geometry_msgs::Polygon& polygon);
//    protected: geometry_msgs::Point32 ToPoint32(ignition::math::Vector2d& vec);

    protected: ros::NodeHandle* rosNode;
    protected: ros::Subscriber trackingSub;

    protected: boost::mutex updateMutex;

//    protected: std::string visTopicName;
//    protected: bool isVisualization;
//    protected: int visualizationUpdateRate;
//    protected: gazebo::common::Time lastVisUpdateTime;

//    protected: void MyJoin(Polygon_2 p1, Polygon_2 p2);
//    protected: void MyJoin2(Polygon_2 p1, Polygon_2 p2);
//
//    protected: bool IsInside(Polygon_2& polygon, const Point_2& point);
//    protected: bool IsIntersection(const Segment_2& seg1, const Segment_2& seg2, Point_2& intersection);
//    protected: bool IsIntersection(const Segment_2& seg, const Polygon_2& polygon, Point_2& intersection, EdgeIterator& polygonEi);
    public: double GetFactor();

//    public: nav_msgs::OccupancyGrid::ConstPtr GetOccupancyMap();
    protected: void OnTrackingMessage(suruiha_gazebo_plugins::UAVTracking::ConstPtr trackingMsg);

    public: double CalculateScore();

    public: double CostAgainstZeroTrajectory(const std::string& modelName, std::vector<std::vector<double> >& trajectory);

//    protected: gazebo::common::Time detectionTime;
//    protected: double penalty;
//    protected: bool isDetected;
    protected: double scoreFactor;

    protected: double messageRate;
    protected: gazebo::common::Time lastTrackingMessageTime;

    protected: double updateRate;
    protected: gazebo::common::Time lastUpdateTime;

    protected: std::string terroristPrefix;
    protected: std::map<std::string, gazebo::physics::ModelPtr> terrorists;

    protected: std::map<std::string, std::vector<std::vector<double> > > terroristTrajectories;
    protected: std::map<std::string, std::vector<std::vector<double> > > trackingTrajectories;
    protected: std::map<std::string, double> trackingStartTimes;
    protected: std::map<std::string, double> trackingEndTimes;

    protected: std::map<std::string, unsigned int> soFarCalculatedIndex;
    protected: std::map<std::string, double> soFarCalculatedValue;

};

#endif //SURUIHA_GAZEBO_PLUGINS_TRACKING_SCORE_H
