#include "subsystems/Lift.h"

Lift::Lift() : liftMtrA{LiftConstants::VICTOR_ID_LIFTA}, liftMtrB{LiftConstants::VICTOR_ID_LIFTB} {
    
}

void Lift::Periodic() {
  
}

void Lift::SetLiftPower(double power) {
    liftMtrs.Set(power);
}