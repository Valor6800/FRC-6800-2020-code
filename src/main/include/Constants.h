#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

//GAMEPAD CONTROLS
constexpr static int GAMEPAD_BASE_LOCATION = 1;
constexpr static int GAMEPAD_OPERATOR_LOCATION = 0;

//DRIVETRAIN SUBSYSTEM
// 1/2/3, 4/5/6 from pdp increasing towards intake
constexpr static int CAN_ID_LEFT_A = 1;
constexpr static int CAN_ID_LEFT_B = 2;
constexpr static int CAN_ID_LEFT_C = 3;
constexpr static int CAN_ID_RIGHT_A = 4;
constexpr static int CAN_ID_RIGHT_B = 5;
constexpr static int CAN_ID_RIGHT_C = 6;

//SHOOTER SUBSYSTEM (***ask for vals***)
constexpr static int VICTOR_ID_SHOOTER = 1;
//constexpr static int SERVO_ID_HOOD = 1;

// IT SUBSYSTEM (***ask for vals***)
constexpr static int VICTOR_ID_INTAKE = 0;
constexpr static int VICTOR_ID_THROATA = 2;
constexpr static int VICTOR_ID_THROATB = 3;