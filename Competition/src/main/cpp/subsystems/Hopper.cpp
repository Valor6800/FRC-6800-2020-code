#include "subsystems/Hopper.h"

Hopper::Hopper() : hopperMtr{HopperConstants::VICTOR_ID_HOPPER_A} {

}

Hopper& Hopper::GetInstance()
{
    static Hopper instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Hopper::Periodic() {
  
}

void Hopper::SetHopperPower(double power) {
    hopperMtr.Set(power);
}