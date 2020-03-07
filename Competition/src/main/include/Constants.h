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

}

namespace LimelightConstants {
    constexpr static int LED_MODE_ON = 3;
    constexpr static int LED_MODE_OFF = 1;
    constexpr static int TRACK_MODE_ON = 0;
    constexpr static int TRACK_MODE_OFF = 1;
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

    constexpr double kP = -0.01f;
    constexpr double kI = 0;
    constexpr double kD = 0;
    constexpr double kIz = 0;
    constexpr double kFF = .00017543859;
    constexpr double MaxRPM = 5700;
    constexpr double kMaxOutput = 1.0;
    constexpr double kMinOutput = -1.0;
    constexpr double kMaxVel = 1000;
    constexpr double kMinVel = 0;
    constexpr double kMaxAccel = 1500;
    constexpr double kAllError = 0;
    constexpr double kDeadband = 0.05;
    // changed x and y deadband to .05 for testing
    constexpr double kDeadbandY = 0.05;
    constexpr double kDeadbandX = 0.05;
    constexpr double kDriveMultiplierX = 0.5;
    constexpr double kDriveMultiplierY = 1;
    constexpr double kDriveOffset = 1;

}

namespace RamseteConstants {

    constexpr auto kMaxSpeed = 4.4_mps; // 4_mps
    constexpr auto kMaxAcceleration = 3.5_mps_sq; //4_mps_sq;

    constexpr double kRamseteB = 2;
    constexpr double kRamseteZeta = 0.7;

    // Convert rotations to meters using gear ratio and wheel diameter (converted to meters)
    constexpr double kPositionConversionFactor = DriveConstants::kWheelDiameterInches * 0.0254 / DriveConstants::kGearRatio * M_PI;
    // Convert rotations per minute to meters per second 
    constexpr double kVelocityConversionFactor = kPositionConversionFactor / 60;

    constexpr bool kGyroReversed = true;

    constexpr auto kS = 0.183_V;
    constexpr auto kV = 2.27 * 1_V * 1_s / 1_m;
    constexpr auto kA = 0.442 * 1_V * 1_s * 1_s / 1_m;

    constexpr double kPDriveVel = 5.62;

    constexpr units::length::meter_t  kStartPos = 4.9_m;
    //constexpr units::deg_t kStartAngularOffset = 15_deg;
    constexpr units::length::meter_t  kCenterline = 0.94_m;

}

namespace ArmConstants {

    constexpr static int TALON_ID_LEFT_ARM = 9;
    constexpr static int TALON_ID_RIGHT_ARM = 10;

}

namespace ShooterConstants {

    constexpr static int CAN_ID_SHOOTER_LEAD = 7;
    constexpr static int CAN_ID_SHOOTER_FOLLOW = 8;
    constexpr static int VICTOR_ID_THROAT = 0;
    constexpr static int PWM_ID_HOOD = 0;

}

namespace IntakeConstants {

    constexpr static int VICTOR_ID_INTAKE = 1;

}

namespace HopperConstants {

    constexpr static int VICTOR_ID_HOPPER_A = 2;

}

namespace LiftConstants {

    constexpr static int VICTOR_ID_LIFT_A = 5;
    constexpr static int VICTOR_ID_LIFT_B = 8;
    constexpr static int PWM_ID_SERVO_RATCHET_LEFT = 7;
    constexpr static int PWM_ID_SERVO_RATCHET_RIGHT = 8;
    constexpr static double RATCHET_LOCK_LEFT_POS = 0.65;
    constexpr static double RATCHET_LOCK_RIGHT_POS = 0.1;
    constexpr static double RATCHET_UNLOCK_LEFT_POS = 0.3;
    constexpr static double RATCHET_UNLOCK_RIGHT_POS = 0.1;

    constexpr static double kDeadbandY = 0.02;

}

namespace MuncherConstants {

    constexpr static int VICTOR_ID_MUNCHER = 4;

}

#endif