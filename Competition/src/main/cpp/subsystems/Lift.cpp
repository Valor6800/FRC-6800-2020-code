#include "subsystems/Lift.h"

Lift::Lift() : liftMtrLeft{LiftConstants::PWM_ID_LIFT_LEFT}, 
               liftMtrRight{LiftConstants::PWM_ID_LIFT_RIGHT},  
               ratchetServoLeft{LiftConstants::PWM_ID_RATCHET_LEFT},
               ratchetServoRight{LiftConstants::PWM_ID_RATCHET_RIGHT} {
    InitLift();
}

Lift& Lift::GetInstance() {
    static Lift instance;
    return instance;
}

void Lift::InitLift() {
    liftMtrLeft.SetInverted(true);
    liftMtrRight.SetInverted(false);
}

void Lift::Periodic() {
  
}

void Lift::SetLiftPower(double power) {
    liftMtrs.Set(power);
}