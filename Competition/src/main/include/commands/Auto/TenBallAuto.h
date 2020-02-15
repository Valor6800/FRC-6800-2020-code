#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include "Trajectories.h"
#include <frc2/command/RamseteCommand.h>
#include <frc/controller/RamseteController.h>
#include <frc/controller/PIDController.h>

#include "subsystems/Drivetrain.h"

#include "commands/ShootStart.h"

#include "Constants.h"

class TenBallAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, TenBallAuto> {
 public:
    TenBallAuto();

private:
    Drivetrain& m_drivetrain = Drivetrain::GetInstance();

    Trajectories m_trajectories;

    frc::Trajectory trajectory1;
    frc::Trajectory trajectory2;
    frc::Trajectory trajectory3;
    frc::Trajectory trajectory4;
    frc::Trajectory trajectory5;
    frc::Trajectory trajectory6;
};