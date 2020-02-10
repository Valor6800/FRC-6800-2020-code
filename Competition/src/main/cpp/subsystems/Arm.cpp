#include "subsystems/Arm.h"

Arm::Arm() : leftArmMtr{ArmConstants::VICTOR_ID_LEFT_ARM}, rightArmMtr{ArmConstants::VICTOR_ID_RIGHT_ARM} {
    
}

Arm& Arm::GetInstance()
{
    static Arm instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    armMtrs.Set(power);
}