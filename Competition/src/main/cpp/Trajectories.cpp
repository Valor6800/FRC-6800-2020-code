#include "Trajectories.h"

Trajectories::Trajectories() {
    EBpath1.action = ValorTrajectory::Path;
    EBpath1.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(0_m,0_m,frc::Rotation2d(0_deg)),
                                                                      { frc::Translation2d(2.3_m, -1.3_m) },
                                                                      frc::Pose2d(7.5_m, -1.3_m, frc::Rotation2d(0_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfig);
    
    
    eightBallPath.push_back(EBpath1);

    autos.insert({"EightBallAuto", eightBallPath});
}

std::unordered_map<std::string, std::vector<ValorTrajectory>> Trajectories::GetAutosMap() {
    return autos;
}