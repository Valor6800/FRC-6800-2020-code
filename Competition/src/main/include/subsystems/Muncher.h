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
    void InitMuncher();

    void Periodic() override;

    void SetMunchPower(double power);

 private:

    frc::PWMVictorSPX muncherMtr;

};

#endif