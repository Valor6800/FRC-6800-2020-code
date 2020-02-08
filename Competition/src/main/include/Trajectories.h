#pragma once

#include <iostream> 
#include <string>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/controller/RamseteController.h>
#include <frc2/command/RamseteCommand.h>
#include <unordered_map>
#include "subsystems/Drivetrain.h"

#include "Constants.h"

class Trajectories {
    public:
        Trajectories();

        std::unordered_map<std::string, frc::Trajectory> GetMap();
        frc::Trajectory* GetTrajectory();

        std::unordered_map<std::string, frc::Trajectory> trajectories;

         frc::Trajectory m_initHomeTrench;

    private:
        //frc::Trajectory m_initAwayTrench;

        Drivetrain m_drivetrain;

};