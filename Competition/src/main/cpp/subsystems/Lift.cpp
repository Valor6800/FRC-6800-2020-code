#include "subsystems/Lift.h"

Lift::Lift() : liftMtrLeft{LiftConstants::VICTOR_ID_LIFT_A}, 
               liftMtrRight{LiftConstants::VICTOR_ID_LIFT_B},
               ratchetServoLeft{LiftConstants::PWM_ID_SERVO_RATCHET_LEFT},
               ratchetServoRight{LiftConstants::PWM_ID_SERVO_RATCHET_RIGHT} {
    LockRatchet();
}

Lift& Lift::GetInstance() {
    static Lift instance;
    return instance;
}

void Lift::Periodic() {
  
}

void Lift::LiftDrive(double stickInput) {
    if (std::abs(stickInput) > LiftConstants::kDeadbandY) {
        liftMtrLeft.Set(-stickInput);
        liftMtrRight.Set(stickInput);
    }
    else {
        liftMtrLeft.Set(0);
        liftMtrRight.Set(0);
    }
}

void Lift::SetLiftPower(double power) {
    liftMtrLeft.Set(power);
    liftMtrRight.Set(power);
}

void Lift::UnlockRatchet() {
    ratchetServoLeft.Set(LiftConstants::RATCHET_UNLOCK_LEFT_POS);
    ratchetServoRight.Set(LiftConstants::RATCHET_UNLOCK_RIGHT_POS);
}

void Lift::LockRatchet() {
    ratchetServoLeft.Set(LiftConstants::RATCHET_LOCK_LEFT_POS);
    ratchetServoRight.Set(LiftConstants::RATCHET_LOCK_RIGHT_POS);
}