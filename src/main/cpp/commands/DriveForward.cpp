/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveForward.h"
#include "Robot.h"

DriveForward::DriveForward() : isFinished(false) {
    Requires(Robot::mDrivetrain);
}

void DriveForward::Initialize() {}

void DriveForward::Execute()
{
    double leftVal = 0;
    double rightVal = 0;
    // @TODO perform some action to determine the new left and right values
    isFinished = false;
    // @TODO perform some action to determine the finish condition
    Robot::mDrivetrain->move(leftVal, rightVal);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() { return isFinished; }

// Called once after isFinished returns true
void DriveForward::End()
{
    Robot::mDrivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted()
{
    Robot::mDrivetrain->stop();
}
