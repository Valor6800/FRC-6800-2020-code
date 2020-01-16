#include "subsystems/Shooter.h"

Shooter::Shooter() : m_shooter{VICTOR_ID_SHOOTER}, hood{SERVO_ID_HOOD} {

}

void Shooter::Periodic() {
  
}

void Shooter::SetShooterPower(double power) {
    m_shooter.Set(power);
}

void Shooter::TiltHood(double pos) {
    hood.Set(pos);
}