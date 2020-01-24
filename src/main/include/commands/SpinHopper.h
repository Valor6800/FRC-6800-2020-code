#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Hopper.h"
/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class SpinHopper : public frc2::CommandHelper<frc2::CommandBase, SpinHopper> {
 public:

    SpinHopper(Hopper* hopper, std::function<double()> leftTrigger, std::function<bool()> leftBumper);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;


 private:
 
    Hopper* m_hopper;
    std::function<double()> m_leftTrig;
    std::function<bool()> m_leftBumper;
};