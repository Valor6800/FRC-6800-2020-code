#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"

class Muncher : public frc2::SubsystemBase {
 public:
 
    Muncher();

    void SetMunchPower(double power);
    void Periodic() override;

 private:

    // motor type not decided
    frc::PWMVictorSPX muncherMtr;

};