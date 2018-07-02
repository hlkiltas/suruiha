//
// Created by okan on 02.07.2018.
//

#include <suruiha_gazebo_plugins/air_traffic_controller/air_traffic_constants.h>

// command strings
const std::string AirTrafficConstants::STATUS = "STATUS";
const std::string AirTrafficConstants::TAKEOFF_REQUEST = "TAKEOFF_REQUEST";
const std::string AirTrafficConstants::LANDING_REQUEST = "LANDING_REQUEST";
const std::string AirTrafficConstants::CANCEL = "CANCEL";

const std::string AirTrafficConstants::AVAILABLE = "AVAILABLE";
const std::string AirTrafficConstants::TAKEN = "TAKEN";
const std::string AirTrafficConstants::ALLOCATED_TO_LAND = "ALLOCATED_TO_LAND";
const std::string AirTrafficConstants::ALLOCATED_TO_TAKEOFF = "ALLOCATED_TO_TAKEOFF";
const std::string AirTrafficConstants::READY_TO_TAKEOFF = "READY_TO_TAKEOFF";