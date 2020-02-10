#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <cmath>

#include "subsystems/Arm.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ArmManual : public frc2::CommandHelper<frc2::CommandBase, ArmManual> {
 public:
   
    ArmManual(Arm& arm, std::function<double()> value);

    void Execute() override;

    bool IsFinished() override;

 private:

    std::function<double()> m_value;
    
};
