#pragma once

#include <frc2/command/TrapezoidProfileSubsystem.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>
#include <adi/ADIS16448_IMU.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/geometry/Pose2d.h>
#include <units/units.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

#include "Constants.h"

#define kP -0.01f
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

   static Drivetrain& GetInstance();

    void Periodic() override;
    
    void InitDrives(rev::CANSparkMax::IdleMode idleMode);
    void ResetEncoders();
    void ResetOdometry(frc::Pose2d pose);
    rev::CANEncoder& GetLeftEncoder();
    rev::CANEncoder& GetRightEncoder();
    double GetEncAvgDistance();
    units::meter_t GetLeftDistance();
    units::meter_t GetRightDistance();
    double GetHeading();
    double GetTurnRate();
    frc::Pose2d GetPose();
    frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

    void TankDriveVolts(units::volt_t leftVolts, units::volt_t rightVolts);
    void ArcadeDrive(double leftInput, double rightInput);
    void RocketLeagueDrive(double straightInput, double reverseInput, double turnInput, bool limelightInput);

    void SetMultiplier(double multiplier);
    void Stop();

    double boostMultiplier;

 private:

    rev::CANSparkMax m_leftDriveLead;
    rev::CANSparkMax m_leftDriveFollowA;
    rev::CANSparkMax m_leftDriveFollowB;
    rev::CANSparkMax m_rightDriveLead;
    rev::CANSparkMax m_rightDriveFollowA;
    rev::CANSparkMax m_rightDriveFollowB;

    frc::ADIS16448_IMU imu{};

    rev::CANPIDController m_leftPIDController = m_leftDriveLead.GetPIDController();
    rev::CANPIDController m_rightPIDController = m_rightDriveLead.GetPIDController();

    rev::CANEncoder m_leftEncoder = m_leftDriveLead.GetEncoder();
    rev::CANEncoder m_rightEncoder = m_rightDriveLead.GetEncoder();

    frc::SpeedControllerGroup leftDrive{m_leftDriveLead, m_leftDriveFollowA, m_leftDriveFollowB};
    frc::SpeedControllerGroup rightDrive{m_rightDriveLead, m_rightDriveFollowA, m_rightDriveFollowB};

    frc::DifferentialDrive drive{leftDrive, rightDrive};

    frc::DifferentialDriveOdometry m_odometry;

    double directionY;
    double straightValue;
    double straightTarget;
    double directionX;
    double turnValue;
    double turnTarget;

};