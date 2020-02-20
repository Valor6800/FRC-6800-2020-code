#include "subsystems/Hopper.h"

Hopper::Hopper() : hopperMtr{HopperConstants::PWM_ID_HOPPER}, throatMtr{ShooterConstants::PWM_ID_THROAT} {
    InitHopper();
}

Hopper& Hopper::GetInstance() {
    static Hopper instance;
    return instance;
}

void Hopper::InitHopper() {
    hopperMtr.SetInverted(false);
    throatMtr.SetInverted(true);
}

void Hopper::Periodic() {
  
}

void Hopper::SetHopperPower(double power) {
    hopperMtr.Set(power);
    throatMtr.Set(power);
}