#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"
#include <frc/Servo.h>
#include <frc/DigitalInput.h>

#ifndef LIFT_H
#define LIFT_H

class Lift : public frc2::SubsystemBase {
 public:

    Lift();

    static Lift& GetInstance();
    void InitLift();

    void Periodic() override;

    void SetLiftPower(double power);
    void SetServoUnlock();
    void SetServoLock();

    bool GetLimitSwitches();
    
 private:

    frc::PWMVictorSPX liftMtrLeft;
    frc::PWMVictorSPX liftMtrRight;

    frc::SpeedControllerGroup liftMtrs{liftMtrLeft, liftMtrRight};

    frc::Servo ratchetServoLeft;
    frc::Servo ratchetServoRight;

    frc::DigitalInput limitSwitchLeft;
    frc::DigitalInput limitSwitchRight;

};

#endif