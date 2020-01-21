#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Throat.h"
/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class SpinThroat : public frc2::CommandHelper<frc2::CommandBase, SpinThroat> {
 public:

    SpinThroat(Throat* throat, std::function<double()> leftTrigger, std::function<bool()> leftBumper);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;


 private:
 
    Throat* m_throat;
    std::function<double()> m_leftTrig;
    std::function<bool()> m_leftBumper;
};