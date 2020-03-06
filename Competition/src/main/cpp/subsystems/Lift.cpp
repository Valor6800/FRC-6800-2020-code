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

}

void Lift::Periodic() {
    frc::SmartDashboard::PutNumber("Left ratchet position", ratchetServoLeft.Get());
    frc::SmartDashboard::PutNumber("Right ratchet position", ratchetServoRight.Get());
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

void Lift::LockRatchet() {
    ratchetServoLeft.Set(LiftConstants::RATCHET_LOCK_LEFT_POS);
    ratchetServoRight.Set(LiftConstants::RATCHET_LOCK_RIGHT_POS);
}


void Lift::UnlockRatchet() {
    ratchetServoLeft.Set(LiftConstants::RATCHET_UNLOCK_LEFT_POS);
    ratchetServoRight.Set(LiftConstants::RATCHET_UNLOCK_RIGHT_POS);
}