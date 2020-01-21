#include "subsystems/Shooter.h"

Shooter::Shooter() : flywheelA{VICTOR_ID_FLYWHEEL_A}, flywheelB{VICTOR_ID_FLYWHEEL_B} /*, hood{SERVO_ID_HOOD} */ {

}

void Shooter::Periodic() {
  
}

void Shooter::SetShooterPower(double power) {
    flywheel.Set(power);
}

void Shooter::Stop() {
    flywheel.Set(0);
}

// void Shooter::TiltHood(double pos) {
//     hood.Set(pos);
// }