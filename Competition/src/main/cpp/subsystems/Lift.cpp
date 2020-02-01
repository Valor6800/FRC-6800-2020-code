#include "subsystems/Lift.h"

Lift::Lift() : liftMtrA{LiftConstants::VICTOR_ID_LIFT_A}, liftMtrB{LiftConstants::VICTOR_ID_LIFT_B} {
    
}

void Lift::Periodic() {
  
}

void Lift::SetLiftPower(double power) {
    liftMtrs.Set(power);
}