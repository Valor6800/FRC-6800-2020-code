#include "subsystems/Arm.h"

Arm::Arm() : leftArmMtr{ArmConstants::CAN_ID_LEFT_ARM}, rightArmMtr{ArmConstants::CAN_ID_RIGHT_ARM} {
    
}

Arm& Arm::GetInstance()
{
    static Arm instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    leftArmMtr.Set(ControlMode::PercentOutput, power*0.25);
    rightArmMtr.Set(ControlMode::PercentOutput, power*0.25);
}