/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "../../util/include/Trajectory.h"
#include <frc/Timer.h>

class DriveForward : public frc::Command {
public:
    DriveForward(double distance);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;

    frc::Timer *timer;
private:
    bool isFinished;

    double currTime;

    double leftVal;
    double rightVal;

    double leftVelocity;
    double rightVelocity;
    double leftAccel;
    double rightAccel;

    double dist;

    Trajectory::Trapezoid straightTrapezoid;
};
