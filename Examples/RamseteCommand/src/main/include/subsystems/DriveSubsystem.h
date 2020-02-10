/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <adi/ADIS16448_IMU.h>
#include <rev/CANEncoder.h>
#include <rev/CANSparkMax.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc2/command/SubsystemBase.h>
#include <units/units.h>
#include <iostream>
#include <fstream>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:

  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  /**
   * Log output to file
   */
  void LogOutput();

  /**
   * Helper method to set all motor controllers to use brake or coast mode
   * @param mode the mode to set the motor controllers
   */
  void SetIdleMode(rev::CANSparkMax::IdleMode mode);

  /**
   * Setup the initial configuration for the REV motors
   */
  void SetupDrive();

  /**
   * Drives the robot using arcade controls.
   *
   * @param fwd the commanded forward movement
   * @param rot the commanded rotation
   */
  void ArcadeDrive(double fwd, double rot);

  /**
   * Controls each side of the drive directly with a voltage.
   *
   * @param left the commanded left output
   * @param right the commanded right output
   */
  void TankDriveVolts(units::volt_t left, units::volt_t right);

  /**
   * Resets the drive encoders to currently read a position of 0.
   */
  void ResetEncoders();

  /**
   * Claibrate Imu
   */
  void ResetImu();

  /**
   * Gets the average distance of the TWO encoders.
   *
   * @return the average of the TWO encoder readings
   */
  double GetAverageEncoderDistance();

  /**
   * Gets the left drive encoder.
   *
   * @return the left drive encoder
   */
  rev::CANEncoder& GetLeftEncoder();

  /**
   * Gets the right drive encoder.
   *
   * @return the right drive encoder
   */
  rev::CANEncoder& GetRightEncoder();

  /**
   * Sets the max output of the drive.  Useful for scaling the drive to drive
   * more slowly.
   *
   * @param maxOutput the maximum output to which the drive will be constrained
   */
  void SetMaxOutput(double maxOutput);

  /**
   * Returns the heading of the robot.
   *
   * @return the robot's heading in degrees, from 180 to 180
   */
  double GetHeading();

  /**
   * Returns the turn rate of the robot.
   *
   * @return The turn rate of the robot, in degrees per second
   */
  double GetTurnRate();

  /**
   * Returns the currently-estimated pose of the robot.
   *
   * @return The pose.
   */
  frc::Pose2d GetPose();

  /**
   * Returns the current wheel speeds of the robot.
   *
   * @return The current wheel speeds.
   */
  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

  /**
   * Resets the odometry to the specified pose.
   *
   * @param pose The pose to which to set the odometry.
   */
  void ResetOdometry(frc::Pose2d pose);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // The motor controllers
  rev::CANSparkMax mLeftLead;
  rev::CANSparkMax mLeftFollow1;
  rev::CANSparkMax mLeftFollow2;
  rev::CANSparkMax mRightLead;
  rev::CANSparkMax mRightFollow1;
  rev::CANSparkMax mRightFollow2;

  // The robot's drive
  frc::DifferentialDrive m_drive{mLeftLead, mRightLead};

  // The left-side drive encoder
  rev::CANEncoder mLeftEncoder = mLeftLead.GetEncoder();

  // The right-side drive encoder
  rev::CANEncoder mRightEncoder = mRightLead.GetEncoder();

  // The gyro sensor
  frc::ADIS16448_IMU imu{};

  // Odometry class for tracking robot pose
  frc::DifferentialDriveOdometry m_odometry;

  std::ofstream logging_file;
};
