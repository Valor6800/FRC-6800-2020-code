#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"

#include "InitHomeTrench.h"

#include "Constants.h"

class HomeTrenchAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, HomeTrenchAuto> {
 public:
    HomeTrenchAuto(Drivetrain* drivetrain);

};