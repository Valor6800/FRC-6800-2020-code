#include "subsystems/Hopper.h"

Hopper::Hopper() : hopperMtrA{VICTOR_ID_HOPPERA}, hopperMtrB{VICTOR_ID_HOPPERB} {

}

void Hopper::Periodic() {
  
}

void Hopper::SetHopperPower(double power) {
    hopperMtrs.Set(power);
}