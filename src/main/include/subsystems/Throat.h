#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>

#include "Constants.h"

class Throat : public frc2::SubsystemBase {
 public:

    Throat();

    void SetThroatPower(double power);

    void Periodic() override;

 private:

    frc::PWMVictorSPX throatMtrA;
    //frc::PWMVictorSPX throatMtrB;

};
