#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"

#ifndef MUNCHER_H
#define MUNCHER_H

class Muncher : public frc2::SubsystemBase {
 public:
 
    Muncher();

    static Muncher& GetInstance();

    void SetMunchPower(double power);
    void Periodic() override;

 private:

    // motor type not decided
    frc::PWMVictorSPX muncherMtr;

};

#endif