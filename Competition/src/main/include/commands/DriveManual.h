#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveManual : public frc2::CommandHelper<frc2::CommandBase, DriveManual> {
 public:
   
    DriveManual(Drivetrain* drivetrain, std::function<double()> straightValue, std::function<double()> reverseValue, std::function<double()> turnValue, std::function<bool()> limelightInput);

    void Execute() override;

    bool IsFinished() override;

 private:

    Drivetrain* m_drivetrain;
   //  std::function<double()> m_leftValue;
   //  std::function<double()> m_rightValue;
   std::function<double()> m_straightValue;
   std::function<double()> m_reverseValue;
   std::function<double()> m_turnValue;
   std::function<bool()> m_limelightInput;
};
