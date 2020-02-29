#include "subsystems/Lift.h"

Lift::Lift() : liftMtrLeft{LiftConstants::PWM_ID_LIFT_LEFT}, 
               liftMtrRight{LiftConstants::PWM_ID_LIFT_RIGHT},
               ratchetServoLeft{LiftConstants::PWM_ID_LIFT_LEFT_SERVO_LOCK},
               ratchetServoRight{LiftConstants::PWM_ID_LIFT_RIGHT_SERVO_LOCK} {
    
}

Lift& Lift::GetInstance()
{
    static Lift instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Lift::Periodic() {
  frc::SmartDashboard::PutNumber("Left ratchet position", ratchetServoLeft.Get());
  frc::SmartDashboard::PutNumber("Right ratchet position", ratchetServoRight.Get());
}

void Lift::SetLiftPower(double power) {
    liftMtrLeft.Set(power);
    liftMtrRight.Set(power);
}

void Lift::LockRatchet() {
    ratchetServoLeft.Set(0.3);
    ratchetServoRight.Set(0.1);
}


void Lift::UnlockRatchet() {
    ratchetServoLeft.Set(0.65);
    ratchetServoRight.Set(0.63);
}