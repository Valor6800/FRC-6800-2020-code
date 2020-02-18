#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>

#include "Constants.h"

#ifndef HOPPER_H
#define HOPPER_H

class Hopper : public frc2::SubsystemBase {
 public:

    Hopper();

    static Hopper& GetInstance();

    void InitHopper();

    void SetHopperPower(double power);

    void Periodic() override;

 private:
    frc::PWMVictorSPX hopperMtr;
    frc::PWMVictorSPX throatMtr;

    // photo electric sensors

};

#endif
