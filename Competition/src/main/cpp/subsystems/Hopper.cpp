#include "subsystems/Hopper.h"

Hopper::Hopper() : hopperMtr{HopperConstants::VICTOR_ID_HOPPER_A} {

}

void Hopper::Periodic() {
  
}

void Hopper::SetHopperPower(double power) {
    hopperMtr.Set(power);
}