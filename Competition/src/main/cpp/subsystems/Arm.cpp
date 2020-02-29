#include "subsystems/Arm.h"

Arm::Arm() {
    
}

Arm& Arm::GetInstance()
{
    static Arm instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
}