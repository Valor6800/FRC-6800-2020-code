#pragma once

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace OIConstants {

    constexpr static int GAMEPAD_BASE_LOCATION = 1;
    constexpr static int GAMEPAD_OPERATOR_LOCATION = 0;

    constexpr static int BUTTON_A = 1;
    constexpr static int BUTTON_B = 2;
    constexpr static int BUTTON_X = 3;
    constexpr static int BUTTON_Y = 4;
    constexpr static int LEFT_BUMPER = 5;
    constexpr static int RIGHT_BUMPER = 6;
    constexpr static int BUTTON_BACK = 7;
    constexpr static int BUTTON_START = 8;
    constexpr static int LEFT_STICK = 9;
    constexpr static int RIGHT_STICK = 10;

}

namespace DriveConstants {

// 1/2/3, 4/5/6 from pdp increasing towards intake
    constexpr static int CAN_ID_LEFT_LEAD = 1;
    constexpr static int CAN_ID_LEFT_FOLLOW_A = 2;
    constexpr static int CAN_ID_LEFT_FOLLOW_B = 3;
    constexpr static int CAN_ID_RIGHT_LEAD = 4;
    constexpr static int CAN_ID_RIGHT_FOLLOW_A = 5;
    constexpr static int CAN_ID_RIGHT_FOLLOW_B = 6;

    constexpr auto kTrackwidth = 0.68_m;

    constexpr double kWheelDiameterInches = 6;
    constexpr double kGearRatio = 8.8;

    constexpr auto kMaxSpeed = 4.4_mps; // 4_mps
    constexpr auto kMaxAcceleration = 4_mps_sq;

    constexpr static double kP = -0.01;
    constexpr static double kI = 0;
    constexpr static double kD = 0;
    constexpr static double kIz = 0;
    // 1/5700
    constexpr static double kFF = 0.00017543859;
    constexpr static double MaxRPM = 5700;
    constexpr static double kMaxOutput = 1.0;
    constexpr static double kMinOutput = -1.0;
    constexpr static double kMaxVel = 1000;
    constexpr static double kMinVel = 0;
    constexpr static double kMaxAccel = 1500;
    constexpr static double kAllError = 0;
    constexpr static double kDeadband = 0.05;
    constexpr static double kDeadbandY = 0.02;
    constexpr static double kDeadbandX = 0.02;
    constexpr static double kDriveMultiplierX = 0.5;
    constexpr static double kDriveMultiplierY = 1;
    constexpr static double kDriveOffset = 1;

    

}

namespace ArmConstants {

    constexpr static int TALON_ID_ARM_LEFT = 6;
    constexpr static int TALON_ID_ARM_RIGHT = 1;

    constexpr auto kArmOffset = 5_deg;

    constexpr double kP = 0;

    constexpr auto kMaxSpeed = 3_deg_per_s;
    constexpr auto kMaxAcceleration = 10_deg / (1_s * 1_s);

    constexpr auto kS = 1_V;
    constexpr auto kCos = 1_V;
    constexpr auto kV = 0.5_V * 1_s / 1_deg;
    constexpr auto kA = 0.1_V * 1_s * 1_s / 1_deg;

}

namespace ShooterConstants {

    constexpr static int CAN_ID_SHOOTER_LEFT = 7;
    constexpr static int CAN_ID_SHOOTER_RIGHT = 8;
    constexpr static int PWM_ID_THROAT = 0;
    constexpr static int PWM_ID_HOOD_LEFT = 6;
    constexpr static int PWM_ID_HOOD_RIGHT = 7;

}

namespace IntakeConstants {

    constexpr static int PWM_ID_INTAKE = 3;

}

namespace HopperConstants {

    constexpr static int PWM_ID_HOPPER = 2;

}

namespace LiftConstants {

    constexpr static int PWM_ID_LIFT_LEFT = 4;
    constexpr static int PWM_ID_LIFT_RIGHT = 5;
    constexpr static int PWM_ID_RATCHET_LEFT = 8;
    constexpr static int PWM_ID_RATCHET_RIGHT = 9;

}

namespace MuncherConstants {

    constexpr static int PWM_ID_MUNCHER = 1;

}

 namespace RamseteConstants {

    constexpr double kRamseteB = 2;
    constexpr double kRamseteZeta = 0.7;

    // Convert rotations to meters using gear ratio and wheel diameter (converted to meters)
    constexpr double kPositionConversionFactor = DriveConstants::kWheelDiameterInches * 0.0254 / DriveConstants::kGearRatio * M_PI;
    // Convert rotations per minute to meters per second 
    constexpr double kVelocityConversionFactor = kPositionConversionFactor / 60;

    constexpr bool kGyroReversed = true;

    constexpr auto kS = 0.146_V;
    constexpr auto kV = 2.25 * 1_V * 1_s / 1_m;
    constexpr auto kA = 0.315 * 1_V * 1_s * 1_s / 1_m;

    constexpr double kPDriveVel = 3.09;

    constexpr units::length::meter_t kStartPos = 4.9_m;
    constexpr units::length::meter_t kCenterline = 0.94_m;

}


#endif