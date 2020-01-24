#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
 public:

    Shooter();

    void SetShooterPower(double power);
    void Periodic() override;
    void Stop();
 private:

   // motor type not decided
    frc::PWMVictorSPX shootMtr;

    // add encoder

    // maybe add servo?

};