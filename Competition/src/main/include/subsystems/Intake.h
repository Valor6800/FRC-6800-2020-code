#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>

#include "Constants.h"

class Intake : public frc2::SubsystemBase {
 public:

    Intake();

    void SetIntakePower(double power);

    void Periodic() override;

 private:

    frc::PWMVictorSPX intakeMtr;

};
