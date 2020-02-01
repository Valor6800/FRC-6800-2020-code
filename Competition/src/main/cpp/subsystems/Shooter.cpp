#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtr{ShooterConstants::VICTOR_ID_SHOOTER} {

}

void Shooter::Periodic() {
  
}

void Shooter::SetShooterPower(double power) {
    shootMtr.Set(power);
}

void Shooter::Stop() {
    shootMtr.Set(0);
}