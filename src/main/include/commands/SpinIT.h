// #pragma once

// #include <frc2/command/CommandBase.h>
// #include <frc2/command/CommandHelper.h>

// #include "subsystems/IT.h"
// /**
//  * An example command that uses an example subsystem.
//  *
//  * <p>Note that this extends CommandHelper, rather extending CommandBase
//  * directly; this is crucially important, or else the decorator functions in
//  * Command will *not* work!
//  */
// class SpinIT : public frc2::CommandHelper<frc2::CommandBase, SpinIT> {
//  public:

//     SpinIT(IT* it, double leftTrigger, double rightTrigger);
//     void Initialize() override;
//     void Execute() override;
//     bool IsFinished() override;


//  private:

//     IT* m_it;
//     double leftTrig;
//     double rightTrig;
// };