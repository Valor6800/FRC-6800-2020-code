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
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>

#include "Constants.h"

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H



class Drivetrain : public frc2::SubsystemBase{
 public:

    Drivetrain();

    static Drivetrain& GetInstance();

    void Periodic() override;
    
    void InitDrives(rev::CANSparkMax::IdleMode idleMode);
    void ResetEncoders();
    void ResetOdometry(frc::Pose2d pose);
    void ResetIMU();
    rev::CANEncoder& GetLeftEncoder();
    rev::CANEncoder& GetRightEncoder();
    double GetEncAvgDistance();
    units::meter_t GetLeftDistance();
    units::meter_t GetRightDistance();
    double GetHeading();
    double GetTurnRate();
    frc::Pose2d GetPose();
    frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

    //frc::TrajectoryConfig& GetTrajConfigRef();

    void TankDriveVolts(units::volt_t leftVolts, units::volt_t rightVolts);
    void ArcadeDrive(double leftInput, double rightInput);
    void RocketLeagueDrive(double straightInput, double reverseInput, double turnInput, bool limelightInput);

    void SetMultiplier(double multiplier);
    void Stop();

    double boostMultiplier;

    frc::DifferentialDriveKinematics kDriveKinematics;
    frc::SimpleMotorFeedforward<units::meters> kSimpleMotorFeedforward;
    frc::TrajectoryConfig kTrajectoryConfigF;
    frc::TrajectoryConfig kTrajectoryConfigR;
    frc::DifferentialDriveVoltageConstraint kDifferentialDriveVoltageConstraint;

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

   //  frc::SpeedControllerGroup leftDrive{m_leftDriveLead, m_leftDriveFollowA, m_leftDriveFollowB};
   //  frc::SpeedControllerGroup rightDrive{m_rightDriveLead, m_rightDriveFollowA, m_rightDriveFollowB};

   //  frc::DifferentialDrive drive{leftDrive, rightDrive};

    frc::DifferentialDriveOdometry m_odometry;

    double directionY;
    double straightValue;
    double straightTarget;
    double directionX;
    double turnValue;
    double turnTarget;

    int limelight_state;

};

#endif