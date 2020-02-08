#include "Trajectories.h"

Trajectories::Trajectories() {
    m_initHomeTrench = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
                                                                    { frc::Translation2d(2.3_m, -1.3_m) },
                                                                    frc::Pose2d(7.5_m, -1.3_m, frc::Rotation2d(0_deg)),
                                                                    m_drivetrain.kTrajectoryConfig);

    trajectories.insert({"InitHomeTrench", m_initHomeTrench});
}

std::unordered_map<std::string, frc::Trajectory> Trajectories::GetMap() {
    return trajectories;
}

frc::Trajectory* Trajectories::GetTrajectory() {
    return nullptr;
}