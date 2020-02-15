#include "ValorTrajectory.h"
#include <unordered_map>
#include "subsystems/Drivetrain.h"
#include <frc/geometry/Translation2d.h>

#ifndef TRAJECTORIES_H
#define TRAJECTORIES_H

class Trajectories {
    public:
        Trajectories();

        std::unordered_map<std::string, std::vector<ValorTrajectory>> GetAutosMap();

        std::unordered_map<std::string, std::vector<ValorTrajectory>> autos;

        std::vector<ValorTrajectory> eightBallPath;
        ValorTrajectory EBpath1;

    private:
        
};

#endif