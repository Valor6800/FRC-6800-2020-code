// #include "commands/Auto/InitHomeTrench.h"

// InitHomeTrench::InitHomeTrench(Drivetrain* drivetrain) : m_autoVoltageConstraint{frc::SimpleMotorFeedforward<units::meters>
//                                         (RamseteConstants::kS, RamseteConstants::kV, RamseteConstants::kA), m_driveKinematics, 10_V},
//                                    m_config{RamseteConstants::kMaxSpeed, RamseteConstants::kMaxAcceleration},
//                                    m_driveKinematics{DriveConstants::kTrackwidth},
//                                    m_drivetrain{drivetrain} {

//     m_config.SetKinematics(m_driveKinematics);
//     m_config.AddConstraint(m_autoVoltageConstraint);

//     auto trajectory = frc::TrajectoryGenerator::GenerateTrajectory(
//         // Start at the origin facing the +X direction
//         frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
//         // Pass through these two interior waypoints, making an 's' curve path
//         {frc::Translation2d(2.3_m, -1.3_m)},
//         // End 3 meters straight ahead of where we started, facing forward
//         frc::Pose2d(7.5_m, -1.3_m, frc::Rotation2d(0_deg)),
//         //frc::Pose2d(4.0_m, 0_m, frc::Rotation2d(0_deg)),
//         // Pass the config
//         m_config);

//     ramseteCommand = new frc2::RamseteCommand(trajectory, [this] () { return m_drivetrain->GetPose(); },
//         frc::RamseteController(RamseteConstants::kRamseteB, RamseteConstants::kRamseteZeta),
//         frc::SimpleMotorFeedforward<units::meters>(RamseteConstants::kS, RamseteConstants::kV, RamseteConstants::kA),
//         m_driveKinematics,
//         [this] { return m_drivetrain->GetWheelSpeeds(); },
//         frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
//         frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
//         [this] (auto left, auto right) { m_drivetrain->TankDriveVolts(left, right); },
//         {m_drivetrain});
// }

// void InitHomeTrench::Execute() {
//     std::move(ramseteCommand);
// }

