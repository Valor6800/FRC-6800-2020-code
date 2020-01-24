#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <cmath>

#include "subsystems/Muncher.h"

#define DEADBAND 0.05

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Munch : public frc2::CommandHelper<frc2::CommandBase, Munch> {
 public:
   
    Munch(Muncher* muncher, std::function<bool()> pressed);

    void Execute() override;

    bool IsFinished() override;

 private:

    Muncher* m_muncher;
    std::function<bool()> m_pressed;
    
};
