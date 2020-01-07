/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveForward.h"
#include "Robot.h"

DriveForward::DriveForward(double distance) : isFinished(false) {
    Requires(Robot::mDrivetrain);

    dist = distance;
    timer = new frc::Timer();

    timer->Reset();
    timer->Start();
}

void DriveForward::Initialize() {
    straightTrapezoid = Robot::mTrajectory->create_trapezoid(dist);
    Robot::mTrajectory->plan_straight(dist, &straightTrapezoid);

    Robot::mTrajectory->test();
}

void DriveForward::Execute()
{   
    currTime = timer->Get();

    leftVelocity = Robot::mTrajectory->curr_left_state->v;
    rightVelocity = Robot::mTrajectory->curr_right_state->v;

    leftAccel = Robot::mTrajectory->curr_left_state->a;
    rightAccel = Robot::mTrajectory->curr_right_state->a;

    leftVal = Robot::mTrajectory->kv * leftVelocity + (Robot::mTrajectory->ka * leftAccel);
    rightVal = Robot::mTrajectory->kv * rightVelocity + (Robot::mTrajectory->ka * rightAccel);

    Robot::mTrajectory->track(currTime);

    Robot::mDrivetrain->move(leftVal, rightVal);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
    if (timer->Get() > Robot::mTrajectory->trapezoid.time) {
        return true;
    }
    else {
        return false;
    }
    
}

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
