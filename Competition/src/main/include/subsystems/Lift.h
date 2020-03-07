#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"
#include <frc/Servo.h>

#ifndef LIFT_H
#define LIFT_H

class Lift : public frc2::SubsystemBase {
 public:

    Lift();

    static Lift& GetInstance();

    void SetLiftPower(double power);
    void Periodic() override;

    void LiftDrive(double stickInput);

    void UnlockRatchet();
    void LockRatchet();

 private:

    frc::PWMVictorSPX liftMtrLeft;
    frc::PWMVictorSPX liftMtrRight;

    frc::Servo ratchetServoLeft;
    frc::Servo ratchetServoRight;

    //frc::SpeedControllerGroup liftMtrs{liftMtrA, liftMtrB};

};

#endif