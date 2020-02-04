/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <units/units.h>
#include <wpi/math>

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {

constexpr int kLeftMotorLeadPort = 1;
constexpr int kLeftMotorFollow1Port = 2;
constexpr int kLeftMotorFollow2Port = 3;

constexpr int kRightMotorLeadPort = 4;
constexpr int kRightMotorFollow1Port = 5;
constexpr int kRightMotorFollow2Port = 6;

constexpr auto kTrackwidth = 0.68_m;
extern const frc::DifferentialDriveKinematics kDriveKinematics;

constexpr double kWheelDiameterInches = 6;
constexpr double kGearRatio = 8.8;

// Convert rotations to meters using gear ratio and wheel diameter (converted to meters)
constexpr double kPositionConversionFactor = kWheelDiameterInches * 0.0254 / kGearRatio * M_PI;
// Convert rotations per minute to meters per second 
constexpr double kVelocityConversionFactor = kPositionConversionFactor / 60;

constexpr bool kGyroReversed = true;

// These are example values only - DO NOT USE THESE FOR YOUR OWN ROBOT!
// These characterization values MUST be determined either experimentally or
// theoretically for *your* robot's drive. The Robot Characterization
// Toolsuite provides a convenient tool for obtaining these values for your
// robot.
constexpr auto ks = 0.146_V;
constexpr auto kv = 2.25 * 1_V * 1_s / 1_m;
constexpr auto ka = 0.315 * 1_V * 1_s * 1_s / 1_m;

// Example value only - as above, this must be tuned for your drive!
constexpr double kPDriveVel = 5.53;
}  // namespace DriveConstants

namespace AutoConstants {
constexpr auto kMaxSpeed = 2_mps;
constexpr auto kMaxAcceleration = 2_mps_sq;

// Reasonable baseline values for a RAMSETE follower in units of meters and
// seconds
constexpr double kRamseteB = 2;
constexpr double kRamseteZeta = 0.7;
}  // namespace AutoConstants

namespace OIConstants {
constexpr int kDriverControllerPort = 1;
}  // namespace OIConstants
