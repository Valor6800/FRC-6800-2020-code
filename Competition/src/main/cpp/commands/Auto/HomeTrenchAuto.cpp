// #include <commands/Auto/HomeTrenchAuto.h>

// HomeTrenchAuto::HomeTrenchAuto() : m_kinematics(DriveConstants::kTrackwidth) {
//     frc2::RamseteCommand ramsete_command_(
//         m_trajectory, [&]() { return Drivetrain::GetInstance().GetPose(); },
//         frc::RamseteController(RamseteConstants::kRamseteB, RamseteConstants::kRamseteZeta),
//         frc::SimpleMotorFeedforward<units::meters>(RamseteConstants::kS,RamseteConstants::kV,RamseteConstants::kA),
//         m_kinematics,
//         [&] { return Drivetrain::GetInstance().GetWheelSpeeds(); },
//         frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
//         frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
//         [&](auto left, auto right) { Drivetrain::GetInstance().TankDriveVolts(left, right); },
//     {&Drivetrain::GetInstance()});
// }