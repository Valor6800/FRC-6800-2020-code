#include <commands/Auto/HomeTrenchAuto.h>

HomeTrenchAuto::HomeTrenchAuto(Drivetrain* drivetrain) {
    AddCommands(frc2::RamseteCommand((m_trajectories.GetMap()).at("InitHomeTrench"), 
                                    [drivetrain] { drivetrain->GetPose(); }, 
                                    frc::RamseteController(RamseteConstants::kRamseteB, RamseteConstants::kRamseteZeta),
                                    RamseteConstants::kSimpleMotorFeedforward,
                                    RamseteConstants::kDriveKinematics,
                                    [drivetrain] { drivetrain->GetWheelSpeeds(); },
                                    frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
                                    frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
                                    [drivetrain] (auto left, auto right) { drivetrain->TankDriveVolts(left, right); },
                                    {drivetrain} ));
}