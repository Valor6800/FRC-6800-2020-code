/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"

#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
    : mLeftLead{kLeftMotorLeadPort, rev::CANSparkMax::MotorType::kBrushless},
      mLeftFollow1{kLeftMotorFollow1Port, rev::CANSparkMax::MotorType::kBrushless},
      mLeftFollow2{kLeftMotorFollow2Port, rev::CANSparkMax::MotorType::kBrushless},
      mRightLead{kRightMotorLeadPort, rev::CANSparkMax::MotorType::kBrushless},
      mRightFollow1{kRightMotorFollow1Port, rev::CANSparkMax::MotorType::kBrushless},
      mRightFollow2{kRightMotorFollow2Port, rev::CANSparkMax::MotorType::kBrushless},
      m_odometry{frc::Rotation2d(units::degree_t(GetHeading()))} {

  SetupDrive();
  ResetEncoders();
  imu.Calibrate();
  logging_file.open("/home/lvuser/ramsete_test.csv");
  logging_file << "Time,Heading,LeftPosition,RightPosition,LeftSpeed,RightSpeed,LeftOutput,RightOutput,LeftCurrent,RightCurrent\n";
}

void DriveSubsystem::SetIdleMode(rev::CANSparkMax::IdleMode mode) {
  mLeftLead.SetIdleMode(mode);
  mLeftFollow1.SetIdleMode(mode);
  mLeftFollow2.SetIdleMode(mode);

  mRightLead.SetIdleMode(mode);
  mRightFollow1.SetIdleMode(mode);
  mRightFollow2.SetIdleMode(mode);
}

void DriveSubsystem::SetupDrive() {
  mLeftLead.RestoreFactoryDefaults();
  mLeftFollow1.RestoreFactoryDefaults();
  mLeftFollow2.RestoreFactoryDefaults();
  mRightLead.RestoreFactoryDefaults();
  mRightFollow1.RestoreFactoryDefaults();
  mRightFollow2.RestoreFactoryDefaults();

  mLeftLead.SetInverted(false);
  mLeftFollow1.SetInverted(false);
  mLeftFollow2.SetInverted(false);
  mRightLead.SetInverted(true);
  mRightFollow1.SetInverted(true);
  mRightFollow2.SetInverted(true);

  mLeftFollow1.Follow(mLeftLead);
  mRightFollow1.Follow(mRightLead);
  mLeftFollow2.Follow(mLeftLead);
  mRightFollow2.Follow(mRightLead);

  // set motors to brake mode
  SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void DriveSubsystem::LogOutput() {
  logging_file << frc::Timer::GetFPGATimestamp() << ",";
  logging_file << GetHeading() << ",";
  logging_file << mLeftEncoder.GetPosition() * kPositionConversionFactor << ",";
  logging_file << mRightEncoder.GetPosition() * kPositionConversionFactor << ",";
  logging_file << mLeftEncoder.GetVelocity() * kVelocityConversionFactor<< ",";
  logging_file << mRightEncoder.GetVelocity() * kVelocityConversionFactor << ",";
  logging_file << mLeftLead.GetAppliedOutput() << ",";
  logging_file << mRightLead.GetAppliedOutput() << ",";
  logging_file << mLeftLead.GetOutputCurrent() << ",";
  logging_file << mRightLead.GetOutputCurrent();
  logging_file << "\n";
  
  frc::SmartDashboard::PutNumber("Heading", std::remainder(imu.GetAngle(), 360) * (kGyroReversed ? -1.0 : 1.0));
  
}

void DriveSubsystem::Periodic() {
  LogOutput();

  // Implementation of subsystem periodic method goes here.
  m_odometry.Update(frc::Rotation2d(units::degree_t(GetHeading())),
                    units::meter_t(mLeftEncoder.GetPosition() * kPositionConversionFactor),
                    units::meter_t(mRightEncoder.GetPosition()) * kPositionConversionFactor);
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd, rot);
}

void DriveSubsystem::TankDriveVolts(units::volt_t left, units::volt_t right) {
  mLeftLead.SetVoltage(left);
  mRightLead.SetVoltage(right);
}

void DriveSubsystem::ResetEncoders() {
  mLeftEncoder.SetPosition(0);
  mRightEncoder.SetPosition(0);
}

double DriveSubsystem::GetAverageEncoderDistance() {
  return (mLeftEncoder.GetPosition() * kPositionConversionFactor + mRightEncoder.GetPosition() * kPositionConversionFactor) / 2.0;
}

rev::CANEncoder& DriveSubsystem::GetLeftEncoder() { return mLeftEncoder; }

rev::CANEncoder& DriveSubsystem::GetRightEncoder() { return mRightEncoder; }

void DriveSubsystem::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}

double DriveSubsystem::GetHeading() {
  return std::remainder(imu.GetAngle(), 360) * (kGyroReversed ? -1.0 : 1.0);
}

double DriveSubsystem::GetTurnRate() {
  return imu.GetRate() * (kGyroReversed ? -1.0 : 1.0);
}

frc::Pose2d DriveSubsystem::GetPose() { return m_odometry.GetPose(); }

frc::DifferentialDriveWheelSpeeds DriveSubsystem::GetWheelSpeeds() {
  return {units::meters_per_second_t(mLeftEncoder.GetVelocity() * kVelocityConversionFactor),
          units::meters_per_second_t(mRightEncoder.GetVelocity() * kVelocityConversionFactor)};
}

void DriveSubsystem::ResetOdometry(frc::Pose2d pose) {
  ResetEncoders();
  m_odometry.ResetPosition(pose,
                           frc::Rotation2d(units::degree_t(GetHeading())));
}
