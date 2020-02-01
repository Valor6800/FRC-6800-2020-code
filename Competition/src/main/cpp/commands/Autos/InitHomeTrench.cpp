// #include "commands/Autos/InitHomeTrench.h"

// InitHomeTrench::InitHomeTrench() : m_autoVoltageConstraint{frc::SimpleMotorFeedforward<units::meters>(
//           RamseteConstants::ks, RamseteConstants::kv, RamseteConstants::ka), RamseteConstants::kDriveKinematics, 10_V} {

// // Create a voltage constraint to ensure we don't accelerate too fast
//   frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
//       frc::SimpleMotorFeedforward<units::meters>(
//           DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
//       DriveConstants::kDriveKinematics, 10_V);

//   // Set up config for trajectory
//   frc::TrajectoryConfig config(AutoConstants::kMaxSpeed,
//                                AutoConstants::kMaxAcceleration);
//   // Add kinematics to ensure max speed is actually obeyed
//   config.SetKinematics(DriveConstants::kDriveKinematics);
//   // Apply the voltage constraint
//   config.AddConstraint(autoVoltageConstraint);

//   // An example trajectory to follow.  All units in meters.
//   auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
//       // Start at the origin facing the +X direction
//       frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
//       // Pass through these two interior waypoints, making an 's' curve path
//       {frc::Translation2d(2.3_m, -1.3_m)},
//       // End 3 meters straight ahead of where we started, facing forward
//       frc::Pose2d(7.5_m, -1.3_m, frc::Rotation2d(0_deg)),
//       // Pass the config
//       config);

//   frc2::RamseteCommand ramseteCommand(
//       exampleTrajectory, [this]() { return m_drive.GetPose(); },
//       frc::RamseteController(AutoConstants::kRamseteB,
//                              AutoConstants::kRamseteZeta),
//       frc::SimpleMotorFeedforward<units::meters>(
//           DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
//       DriveConstants::kDriveKinematics,
//       [this] { return m_drive.GetWheelSpeeds(); },
//       frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
//       frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
//       [this](auto left, auto right) { m_drive.TankDriveVolts(left, right); },
//       {&m_drive});

//   // no auto
//   return new frc2::SequentialCommandGroup(
//       std::move(ramseteCommand),
//       frc2::InstantCommand([this] { m_drive.TankDriveVolts(0_V, 0_V); }, {}));
// }