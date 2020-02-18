#include "subsystems/Hopper.h"

Hopper::Hopper() : hopperMtr{HopperConstants::VICTOR_ID_HOPPER_A},
                   throatMtr{ShooterConstants::VICTOR_ID_THROAT} {
    InitHopper();
}

Hopper& Hopper::GetInstance()
{
    static Hopper instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Hopper::InitHopper() {
    throatMtr.SetInverted(true);
}

void Hopper::Periodic() {
  
}

void Hopper::SetHopperPower(double power) {
    hopperMtr.Set(power);
    throatMtr.Set(power);
}