#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() : frc2::TrapezoidProfileSubsystem,
                           leftDriveA(CAN_ID_LEFT_A, rev::CANSparkMax::MotorType::kBrushless),
                           leftDriveB(CAN_ID_LEFT_B, rev::CANSparkMax::MotorType::kBrushless),
                           rightDriveA(CAN_ID_RIGHT_A, rev::CANSparkMax::MotorType::kBrushless),
                           rightDriveB(CAN_ID_RIGHT_B, rev::CANSparkMax::MotorType::kBrushless)
{
    drive.SetMaxOutput(MAX_OUTPUT);
    drive.SetDeadband(DEADBAND);

    leftDriveA.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    leftDriveB.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightDriveA.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    rightDriveB.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void Drivetrain::Periodic() {
  
}