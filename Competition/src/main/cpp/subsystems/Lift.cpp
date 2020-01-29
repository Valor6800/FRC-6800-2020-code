#include "subsystems/Lift.h"

Lift::Lift() : liftMtrA{VICTOR_ID_LIFTA}, liftMtrB{VICTOR_ID_LIFTB} {
    
}

void Lift::Periodic() {
  
}

void Lift::SetLiftPower(double power) {
    liftMtrs.Set(power);
}