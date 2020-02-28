#include "subsystems/Lift.h"

Lift::Lift() : liftMtrLeft{LiftConstants::PWM_ID_LIFT_LEFT}, liftMtrRight{LiftConstants::PWM_ID_LIFT_RIGHT} {
    
}

Lift& Lift::GetInstance()
{
    static Lift instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Lift::Periodic() {
  
}

void Lift::SetLiftPower(double power) {
    liftMtrLeft.Set(power);
    liftMtrRight.Set(power);
}