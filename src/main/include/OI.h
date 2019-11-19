/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/WPILib.h>
#include <frc/XboxController.h>

#define GAMEPAD_DRIVER_LOCATION 0
#define GAMEPAD_OPERATOR_LOCATION 1

class OI {
private:
public:
    OI();

    frc::XboxController mGamepadDriver{GAMEPAD_DRIVER_LOCATION};
    frc::XboxController mGamepadOperator{GAMEPAD_OPERATOR_LOCATION};

};
