#pragma once

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>

namespace OIConstants {

    constexpr static int GAMEPAD_BASE_LOCATION = 1;
    constexpr static int GAMEPAD_OPERATOR_LOCATION = 0;

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

}

namespace RamseteConstants {

    constexpr auto kMaxSpeed = 2_mps; // 4_mps
    constexpr auto kMaxAcceleration = 2_mps_sq; //4_mps_sq;

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

    constexpr double kPDriveVel = 5.53;

}

namespace ArmConstants {

    constexpr static int VICTOR_ID_LEFT_ARM = 7;
    constexpr static int VICTOR_ID_RIGHT_ARM = 8;

}

namespace ShooterConstants {

    constexpr static int CAN_ID_SHOOTER_A = 7;
    constexpr static int CAN_ID_SHOOTER_B = 8;
    constexpr static int PWM_ID_HOOD = 0;

}

namespace IntakeConstants {

    constexpr static int VICTOR_ID_INTAKE = 4;

}

namespace HopperConstants {

    constexpr static int VICTOR_ID_HOPPER_A = 2;
    constexpr static int VICTOR_ID_HOPPER_B = 8;

}

namespace LiftConstants {

    constexpr static int VICTOR_ID_LIFT_A = 7;
    constexpr static int VICTOR_ID_LIFT_B = 8;

}

namespace MuncherConstants {

    constexpr static int VICTOR_ID_MUNCHER = 9;

}