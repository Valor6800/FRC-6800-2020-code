#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"
/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class SpinIntake : public frc2::CommandHelper<frc2::CommandBase, SpinIntake> {
 public:

    SpinIntake(Intake* intake, std::function<double()> rightTrigger, std::function<bool()> rightBumper);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;


 private:
 
    Intake* m_intake;
    std::function<double()> m_rightTrig;
    std::function<bool()> m_rightBumper;
};