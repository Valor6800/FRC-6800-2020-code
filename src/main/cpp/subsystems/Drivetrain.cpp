#include "subsystems/Drivetrain.h"

// Drive parameters
#define MAX_OUTPUT 1.0
#define DEADBAND 0.05
#define P_VALUE 0.005
#define I_VALUE 0
#define D_VALUE 0
#define ARCADE_MODE true
#define DRIVER_SQUARED true

// Motor parameters
#define CAN_ID_LEFT_A 4
#define CAN_ID_LEFT_B 3
#define CAN_ID_RIGHT_A 1
#define CAN_ID_RIGHT_B 2

Drivetrain::Drivetrain() : frc::PIDSubsystem("Drivetrain", P_VALUE, I_VALUE, D_VALUE),
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

    // Previous year PID controller values
    // @TODO needs testing
    // @TODO values need to be parsed into macros
    GetPIDController()->SetOutputRange(-180, 180);
    GetPIDController()->SetAbsoluteTolerance(0.5);
    GetPIDController()->SetContinuous(true);
    GetPIDController()->SetOutputRange(-1, 1);
}

void Drivetrain::InitDefaultCommand()
{
    SetDefaultCommand(new DriveManual());
}

double Drivetrain::ReturnPIDInput()
{
    // @TODO implement
}

void Drivetrain::UsePIDOutput(double output)
{
    // @TODO implement
}

void Drivetrain::move(double leftInput, double rightInput)
{
    if (ARCADE_MODE) {
        drive.ArcadeDrive(leftInput, rightInput, DRIVER_SQUARED);
    } else {
        drive.TankDrive(leftInput, rightInput, DRIVER_SQUARED);
    }
}

void Drivetrain::stop() {
    move(0,0);
}

void Drivetrain::reset()
{
    leftDriveA.GetEncoder().SetPosition(0);
    leftDriveB.GetEncoder().SetPosition(0);
    rightDriveA.GetEncoder().SetPosition(0);
    rightDriveB.GetEncoder().SetPosition(0);
}