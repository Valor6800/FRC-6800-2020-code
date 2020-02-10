#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <cmath>

#include "subsystems/Lift.h"

#define DEADBAND 0.05

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Climb : public frc2::CommandHelper<frc2::CommandBase, Climb> {
 public:
   
    Climb(Lift& lift, std::function<double()> value);

    void Execute() override;

    bool IsFinished() override;

 private:

    std::function<double()> m_value;
    
};
