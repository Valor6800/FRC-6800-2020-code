#include "ValorTrajectory.h"
#include <unordered_map>
#include "subsystems/Drivetrain.h"
#include <frc/geometry/Translation2d.h>
#include <units/units.h>

#ifndef TRAJECTORIES_H
#define TRAJECTORIES_H

class Trajectories {
    public:
        Trajectories();

        std::unordered_map<std::string, std::vector<ValorTrajectory>> GetAutosMap();

    private:
        std::unordered_map<std::string, std::vector<ValorTrajectory>> autos;

        void InitStartPositions();
        std::unordered_map<std::string, units::meter_t> startPositions;

        void InitEightBallHome();
        std::vector<ValorTrajectory> eightBallHome;
        ValorTrajectory eightBallHomePath1;
        ValorTrajectory eightBallHomePath2;
        
        void InitTenBallHome();
        std::vector<ValorTrajectory> tenBallHome;
        ValorTrajectory tenBallHomePath1;
        ValorTrajectory tenBallHomePath2;
        ValorTrajectory tenBallHomePath3;
        ValorTrajectory tenBallHomePath4;
        ValorTrajectory tenBallHomePath5;
        ValorTrajectory tenBallHomePath6;

        
};

#endif