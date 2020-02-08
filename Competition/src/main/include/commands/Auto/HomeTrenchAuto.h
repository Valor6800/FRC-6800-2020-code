#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/StartEndCommand.h>

#include "subsystems/Drivetrain.h"

#include "Trajectories.h"
#include "Constants.h"

class HomeTrenchAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, HomeTrenchAuto> {
 public:
    HomeTrenchAuto(Drivetrain* drivetrain);

 private:
    Trajectories m_trajectories;
};