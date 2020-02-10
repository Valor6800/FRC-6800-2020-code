#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>

#include "Constants.h"

class Hopper : public frc2::SubsystemBase {
 public:

    Hopper();

    static Hopper& GetInstance();

    void SetHopperPower(double power);

    void Periodic() override;

 private:
    frc::PWMVictorSPX hopperMtr;

    // photo electric sensors

};
