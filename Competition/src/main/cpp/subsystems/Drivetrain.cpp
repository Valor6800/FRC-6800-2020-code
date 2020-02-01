#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() : m_leftDriveLead{DriveConstants::CAN_ID_LEFT_LEAD, rev::CANSparkMax::MotorType::kBrushless},
                           m_leftDriveFollowA{DriveConstants::CAN_ID_LEFT_FOLLOW_A, rev::CANSparkMax::MotorType::kBrushless},
                           m_leftDriveFollowB{DriveConstants::CAN_ID_LEFT_FOLLOW_B, rev::CANSparkMax::MotorType::kBrushless},
                           m_rightDriveLead{DriveConstants::CAN_ID_RIGHT_LEAD, rev::CANSparkMax::MotorType::kBrushless},
                           m_rightDriveFollowA{DriveConstants::CAN_ID_RIGHT_FOLLOW_A, rev::CANSparkMax::MotorType::kBrushless},
                           m_rightDriveFollowB{DriveConstants::CAN_ID_RIGHT_FOLLOW_B, rev::CANSparkMax::MotorType::kBrushless},
                           boostMultiplier{0.5}
{
    drive.SetMaxOutput(kMaxOutput);
    drive.SetDeadband(kDeadband);

    InitDrives(rev::CANSparkMax::IdleMode::kCoast);

    leftDrive.SetInverted(!leftDrive.GetInverted());
    rightDrive.SetInverted(!rightDrive.GetInverted());
}

void Drivetrain::Periodic() {

 }

void Drivetrain::ArcadeDrive(double leftInput, double rightInput) {
    drive.ArcadeDrive(leftInput, -rightInput * .5, true);
}

void Drivetrain::RocketLeagueDrive(double straightInput, double reverseInput, double turnInput) {
    straightValue = reverseInput - straightInput;
    if (std::abs(straightValue) < kDeadbandY) {
      straightValue = 0;
    }
    directionY = (straightValue > 0) ? 1 : -1;
    straightTarget = MaxRPM * -std::pow(straightValue, 2) * directionY * kDriveMultiplierY * boostMultiplier;
   
    turnValue = turnInput;
    directionX = (turnValue >= 0) ? 1 : -1;
    turnValue = -std::pow(turnValue, 2) * directionX * kDriveMultiplierX;
    turnTarget = MaxRPM * turnValue;
    if (directionY == 1) {   //for inverting x and y in revese direction
      turnTarget = -turnTarget;
    }
    
    if (std::abs(turnValue) < kDeadbandX) {
      if (std::abs(straightValue) < kDeadbandY) {
        turnTarget = 0; //if turning, don't use drive straightening
      }
      else {
        turnTarget = (m_leftEncoder.GetVelocity() - m_rightEncoder.GetVelocity()) * kDriveOffset;
        // Robot tends to curve to the left at 50RPM slower
      }
    }
  
    m_leftPIDController.SetReference(straightTarget - turnTarget, rev::ControlType::kVelocity);
    m_rightPIDController.SetReference(straightTarget + turnTarget, rev::ControlType::kVelocity);
}

void Drivetrain::InitDrives(rev::CANSparkMax::IdleMode idleMode) {
    // m_leftDriveLead.RestoreFactoryDefaults();
    // m_leftDriveFollowA.RestoreFactoryDefaults();
    // m_leftDriveFollowB.RestoreFactoryDefaults();
    // m_rightDriveLead.RestoreFactoryDefaults();
    // m_rightDriveFollowA.RestoreFactoryDefaults();
    // m_rightDriveFollowB.RestoreFactoryDefaults();

    m_leftDriveLead.SetIdleMode(idleMode);
    m_leftDriveFollowA.SetIdleMode(idleMode);
    m_leftDriveFollowB.SetIdleMode(idleMode);
    m_rightDriveLead.SetIdleMode(idleMode);
    m_rightDriveFollowA.SetIdleMode(idleMode);
    m_rightDriveFollowB.SetIdleMode(idleMode);

    m_leftDriveFollowA.Follow(m_leftDriveLead);
    m_leftDriveFollowB.Follow(m_leftDriveLead);

    m_rightDriveFollowA.Follow(m_rightDriveLead);
    m_rightDriveFollowB.Follow(m_rightDriveLead);

    m_leftPIDController.SetP(kP);
    m_leftPIDController.SetI(kI);
    m_leftPIDController.SetD(kD);
    m_leftPIDController.SetIZone(kIz);
    m_leftPIDController.SetFF(kFF);
    m_leftPIDController.SetOutputRange(kMinOutput, kMaxOutput);

    m_rightPIDController.SetP(kP);
    m_rightPIDController.SetI(kI);
    m_rightPIDController.SetD(kD);
    m_rightPIDController.SetIZone(kIz);
    m_rightPIDController.SetFF(kFF);
    m_rightPIDController.SetOutputRange(kMinOutput, kMaxOutput);

    m_rightPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    m_rightPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    m_rightPIDController.SetSmartMotionMaxAccel(kMaxAccel);
    m_rightPIDController.SetSmartMotionAllowedClosedLoopError(kAllError);
    
    m_leftPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    m_leftPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    m_leftPIDController.SetSmartMotionMaxAccel(kMaxAccel);
    m_leftPIDController.SetSmartMotionAllowedClosedLoopError(kAllError);
}

void Drivetrain::Stop() {
    drive.StopMotor();
}

void Drivetrain::SetMultiplier(double multiplier) {
    boostMultiplier = multiplier;
}