#include "Trajectories.h"

Trajectories::Trajectories() {
    InitEightBallHome();
    InitTenBallHome();
    
    autos.insert({"EightBallHomeAuto", eightBallHome});
    autos.insert({"TenBallHomeAuto", tenBallHome});
}

std::unordered_map<std::string, std::vector<ValorTrajectory>> Trajectories::GetAutosMap() {
    return autos;
}

void Trajectories::InitStartPositions() {
    // need to measure for eight ball home
    startPositions.insert({"EightBallHomeAuto", 0.0_m});
    startPositions.insert({"TenBallHomeAuto", 4.9_m});
}

void Trajectories::InitEightBallHome() {
    eightBallHomePath1.action = ValorTrajectory::Path;
    eightBallHomePath1.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(0_m, 0_m,frc::Rotation2d(0_deg)),
                                                                      { frc::Translation2d(2.3_m, -1.3_m) },
                                                                      frc::Pose2d(7.5_m, -1.3_m, frc::Rotation2d(0_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfigF);
    eightBallHomePath2.action = ValorTrajectory::Path;
    eightBallHomePath2.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(7.5_m, -1.3_m,frc::Rotation2d(0_deg)),
                                                                      { frc::Translation2d(2.3_m, -1.3_m) },
                                                                      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfigR);
    
    eightBallHome.push_back(eightBallHomePath1);
}

void Trajectories::InitTenBallHome() {
    tenBallHomePath1.action = ValorTrajectory::Path;
    tenBallHomePath2.action = ValorTrajectory::Path;
    tenBallHomePath3.action = ValorTrajectory::Path;
    tenBallHomePath4.action = ValorTrajectory::Path;
    tenBallHomePath5.action = ValorTrajectory::Path;
    tenBallHomePath6.action = ValorTrajectory::Path;

    tenBallHomePath1.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(0_m,0_m,frc::Rotation2d(0_deg)),
                                                                      {},
                                                                      frc::Pose2d(3.7_m,(-7.64_m  + RamseteConstants::kStartPos),frc::Rotation2d(-60_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfigF);

    tenBallHomePath2.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(3.7_m,(-7.64_m  + RamseteConstants::kStartPos),frc::Rotation2d(-60_deg)),
                                                                      {},
                                                                      frc::Pose2d(0_m,(-2.69_m + RamseteConstants::kStartPos),frc::Rotation2d(0_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfigR);

    tenBallHomePath3.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(0_m,(-2.69_m + RamseteConstants::kStartPos),frc::Rotation2d(0_deg)),
                                                                      {},
                                                                      frc::Pose2d(3.3_m,(-3.04_m + RamseteConstants::kStartPos),frc::Rotation2d(-35_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfigF);

    tenBallHomePath4.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(3.3_m,(-3.04_m + RamseteConstants::kStartPos),frc::Rotation2d(-35_deg)),
                                                                      {},
                                                                      frc::Pose2d(1.5_m,(-RamseteConstants::kCenterline + RamseteConstants::kStartPos),frc::Rotation2d(0_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfigR);
    tenBallHomePath5.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(1.5_m,(-RamseteConstants::kCenterline + RamseteConstants::kStartPos),frc::Rotation2d(0_deg)),
                                                                      {frc::Translation2d(2.2_m,(-RamseteConstants::kCenterline + RamseteConstants::kStartPos))},
                                                                      frc::Pose2d(5_m,(-RamseteConstants::kCenterline + RamseteConstants::kStartPos),frc::Rotation2d(0_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfigF);
    tenBallHomePath6.trajectory = frc::TrajectoryGenerator::GenerateTrajectory(frc::Pose2d(5_m,(-RamseteConstants::kCenterline + RamseteConstants::kStartPos),frc::Rotation2d(0_deg)),
                                                                      {},
                                                                      frc::Pose2d(4_m,(-RamseteConstants::kCenterline + RamseteConstants::kStartPos -0.2_m),frc::Rotation2d(15_deg)),
                                                                      Drivetrain::GetInstance().kTrajectoryConfigR);
                                                                    
    tenBallHome.push_back(tenBallHomePath1);
    tenBallHome.push_back(tenBallHomePath2);
    tenBallHome.push_back(tenBallHomePath3);
    tenBallHome.push_back(tenBallHomePath4);
    tenBallHome.push_back(tenBallHomePath5);
    tenBallHome.push_back(tenBallHomePath6);
}