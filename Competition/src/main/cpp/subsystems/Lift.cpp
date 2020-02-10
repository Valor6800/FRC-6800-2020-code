#include "subsystems/Lift.h"

Lift::Lift() : liftMtrA{LiftConstants::VICTOR_ID_LIFT_A}, liftMtrB{LiftConstants::VICTOR_ID_LIFT_B} {
    
}

Lift& Lift::GetInstance()
{
    static Lift instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Lift::Periodic() {
  
}

void Lift::SetLiftPower(double power) {
    liftMtrs.Set(power);
}