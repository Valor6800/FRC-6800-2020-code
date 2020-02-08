#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/controller/SimpleMotorFeedforward.h>

#include "InitHomeTrench.h"

#include "Constants.h"

class HomeTrenchAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, HomeTrenchAuto> {
 public:
    HomeTrenchAuto();

private:
    frc::Trajectory m_trajectory;
    frc::DifferentialDriveKinematics m_kinematics;
};