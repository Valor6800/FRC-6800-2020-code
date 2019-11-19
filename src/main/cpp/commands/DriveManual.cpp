/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveManual.h"
#include "Robot.h"

DriveManual::DriveManual() {
    Requires(Robot::mDrivetrain);
}

// Called just before this Command runs the first time
void DriveManual::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveManual::Execute()
{
    double leftVal = Robot::mOI->mGamepadDriver.GetY(frc::GenericHID::JoystickHand::kLeftHand);
    double rightVal = Robot::mOI->mGamepadDriver.GetY(frc::GenericHID::JoystickHand::kRightHand);
    Robot::mDrivetrain->move(leftVal, rightVal);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveManual::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveManual::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveManual::Interrupted() {}
