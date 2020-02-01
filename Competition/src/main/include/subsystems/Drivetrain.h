#pragma once

#include <frc2/command/TrapezoidProfileSubsystem.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

#define kP 0
#define kI 0
#define kD 0
#define kIz 0
#define kFF 1.0/MaxRPM
#define MaxRPM 5700
#define kMaxOutput 1.0
#define kMinOutput -1.0
#define kMaxVel 1000
#define kMinVel 0
#define kMaxAccel 1500
#define kAllError 0
#define kDeadband 0.05
#define kDeadbandY 0.02
#define kDeadbandX 0.02
#define kDriveMultiplierX 0.5
#define kDriveMultiplierY 1
#define kDriveOffset 1

class Drivetrain : public frc2::SubsystemBase{
 public:

    Drivetrain();

    void Periodic() override;

    void ArcadeDrive(double leftInput, double rightInput);

    void RocketLeagueDrive(double straightInput, double reverseInput, double turnInput);

    void InitDrives(rev::CANSparkMax::IdleMode idleMode);

    void Stop();

    double boostMultiplier;

    void SetMultiplier(double multiplier);

 private:

    rev::CANSparkMax m_leftDriveLead;
    rev::CANSparkMax m_leftDriveFollowA;
    rev::CANSparkMax m_leftDriveFollowB;
    rev::CANSparkMax m_rightDriveLead;
    rev::CANSparkMax m_rightDriveFollowA;
    rev::CANSparkMax m_rightDriveFollowB;

    rev::CANPIDController m_leftPIDController = m_leftDriveLead.GetPIDController();
    rev::CANPIDController m_rightPIDController = m_rightDriveLead.GetPIDController();

    rev::CANEncoder m_leftEncoder = m_leftDriveLead.GetEncoder();
    rev::CANEncoder m_rightEncoder = m_rightDriveLead.GetEncoder();

    frc::SpeedControllerGroup leftDrive{m_leftDriveLead, m_leftDriveFollowA, m_leftDriveFollowB};
    frc::SpeedControllerGroup rightDrive{m_rightDriveLead, m_rightDriveFollowA, m_rightDriveFollowB};

    frc::DifferentialDrive drive{leftDrive, rightDrive};

    double directionY;
    double straightValue;
    double straightTarget;
    double directionX;
    double turnValue;
    double turnTarget;

};