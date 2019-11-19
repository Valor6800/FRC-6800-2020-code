/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <frc/commands/Scheduler.h>

Drivetrain *Robot::mDrivetrain = NULL;
OI *Robot::mOI = NULL;

void Robot::RobotInit()
{
    mDrivetrain = new Drivetrain();
    mOI = new OI();
}

void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{
    frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{

}

void Robot::TeleopPeriodic()
{
    frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{

}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif