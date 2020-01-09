#include "subsystems/Shooter.h"

Shooter::Shooter() {
    shooter.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void Shooter::Periodic() {
  
}

void Shooter::SetShooterPower(double power) {
    shooter.Set(power);
}

void Shooter::TiltHood(double pos) {
    hood.Set(pos);
}