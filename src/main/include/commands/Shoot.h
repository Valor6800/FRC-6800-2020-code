// #pragma once

// #include <frc2/command/CommandBase.h>
// #include <frc2/command/CommandHelper.h>

// #include "subsystems/Shooter.h"
// /**
//  * An example command that uses an example subsystem.
//  *
//  * <p>Note that this extends CommandHelper, rather extending CommandBase
//  * directly; this is crucially important, or else the decorator functions in
//  * Command will *not* work!
//  */
// class Shoot : public frc2::CommandHelper<frc2::CommandBase, Shoot> {
//  public:

//     explicit Shoot(Shoot* shoot, double value);
//     void Initialize() override;
//     void Execute() override;
//     bool IsFinished() override;
//     void End() override;
//     void Interrupted() override;

//  private:

//     Shooter* m_shooter;
//     double dist;
// };