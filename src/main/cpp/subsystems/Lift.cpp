#include "subsystems/Lift.h"

Lift::Lift() {
    
}

void Lift::Periodic() {
  
}

void Lift::SetLiftPower(double power) {
    liftA.Set(power);
    liftB.Set(power);
}