#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrA{ShooterConstants::CAN_ID_SHOOTER_A, rev::CANSparkMax::MotorType::kBrushless}, 
                    shootMtrB{ShooterConstants::CAN_ID_SHOOTER_B, rev::CANSparkMax::MotorType::kBrushless}, hood{ShooterConstants::PWM_ID_HOOD} {

}

void Shooter::Periodic() {
  
}

void Shooter::SetShooterPower(double power) {
    shootMtrs.Set(power);
}

void Shooter::Stop() {
    shootMtrs.Set(0);
}