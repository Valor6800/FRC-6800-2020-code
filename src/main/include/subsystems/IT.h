#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>

#include "Constants.h"

class IT : public frc2::SubsystemBase {
 public:

    IT();

    void SetIntakePower(double power);
    void SetThroatPower(double power);

    void Periodic() override;

 private:

    frc::PWMVictorSPX intake{VICTOR_ID_INTAKE};
    frc::PWMVictorSPX throatA{VICTOR_ID_THROATA};
    frc::PWMVictorSPX throatB{VICTOR_ID_THROATB};

};

// // 7 victor sp
// // 3 talon on board sped control
// // 6 canspark

