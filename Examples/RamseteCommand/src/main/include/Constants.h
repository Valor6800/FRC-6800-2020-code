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

#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <vector>
#include <utility>
//#include "Point.h"
#include <units/units.h>
#include <opencv2/core/types.hpp>


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
constexpr auto kMaxSpeed = 4_mps;
constexpr auto kMaxAcceleration = 4_mps_sq;

#define autoOffset
// std::vector<cv::Point2d> AutoTest1 = {cv::Point2d(0.0,0.0), cv::Point2d(2.5,0), cv::Point2d(3.5,-2),
//                              cv::Point2d(-1,-0)};


//Definsive 2 ball auto
//start pos allignment:
    //Center line of robot alligned with tip of target triangle (2.44m off wall). 
    //Front bar of robot parallel with initiation line.
const std::vector<frc::Translation2d> Auto1Taj1Translations = {frc::Translation2d(2.5_m,0.0_m)};
const std::vector<frc::Pose2d> Auto1Traj1Poses = {frc::Pose2d(0_m,0_m,frc::Rotation2d(0_deg)),frc::Pose2d(3.5_m,-2.0_m,frc::Rotation2d(-60_deg))};
const std::vector<frc::Pose2d> Auto1Traj2Poses = {Auto1Traj1Poses[1],frc::Pose2d(-1_m,0_m,frc::Rotation2d(0_deg))};


//Offensive 5 ball auto
//start pos allignment:
    //Center line of robot alligned with tip of target triangle (2.44m off wall). 
    //Front bar of robot parallel with initiation line.
const std::vector<frc::Translation2d> Auto2Taj1Translations = {frc::Translation2d(0.75_m,1.3_m),
                                                               frc::Translation2d(2.2_m,1.25_m)};

const std::vector<frc::Pose2d> Auto2Traj1Poses = {frc::Pose2d(0_m,0_m,frc::Rotation2d(63_deg)),frc::Pose2d(7_m,1.25_m,frc::Rotation2d(0_deg))};
const std::vector<frc::Pose2d> Auto2Traj2Poses = {Auto2Traj1Poses[1],frc::Pose2d(2.2_m,0.75_m,frc::Rotation2d(20_deg))};

// Reasonable baseline values for a RAMSETE follower in units of meters and
// seconds
constexpr double kRamseteB = 2;
constexpr double kRamseteZeta = 0.7;
}  // namespace AutoConstants

namespace OIConstants {
constexpr int kDriverControllerPort = 0;
}  // namespace OIConstants

constexpr double potUpperSetpoint = 0.8;
constexpr double potLowerSetpoint = 0.2;

