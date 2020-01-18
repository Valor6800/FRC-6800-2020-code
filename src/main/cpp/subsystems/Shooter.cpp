#include "subsystems/Shooter.h"

Shooter::Shooter() /*, hood{SERVO_ID_HOOD} */ {

}

void Shooter::Periodic() {
  
}

void Shooter::SetShooterPower(double power) {
    m_flyWheel.Set(power);
}

// void Shooter::TiltHood(double pos) {
//     hood.Set(pos);
// }