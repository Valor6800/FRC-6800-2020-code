#include "subsystems/Hopper.h"

Hopper::Hopper() : hopperMtrA{HopperConstants::VICTOR_ID_HOPPERA}, hopperMtrB{HopperConstants::VICTOR_ID_HOPPERB} {

}

void Hopper::Periodic() {
  
}

void Hopper::SetHopperPower(double power) {
    hopperMtrs.Set(power);
}