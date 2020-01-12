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

    explicit DriveManual(Drivetrain* drivetrain, double leftValue, double rightValue);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
   // void End() override;
    //void Interrupted() override;

 private:

    Drivetrain* m_drivetrain;
    double leftVal;
    double rightVal;
};
