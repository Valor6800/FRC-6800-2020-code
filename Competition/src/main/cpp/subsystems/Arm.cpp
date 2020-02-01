#include "subsystems/Arm.h"

Arm::Arm() : leftArmMtr{ArmConstants::VICTOR_ID_LEFT_ARM}, rightArmMtr{ArmConstants::VICTOR_ID_RIGHT_ARM} {
    
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    armMtrs.Set(power);
}