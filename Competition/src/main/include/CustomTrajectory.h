#pragma once

#include<iostream> 
#include <string>
#include <frc/geometry/Pose2d.h>
#include <frc/trajectory/TrajectoryGenerator.h>

class CustomTrajectory {
    private:
        std::string name;
        frc::Pose2d start;
        frc::Pose2d end;
        std::vector<frc::Translation2d> waypoints;

}