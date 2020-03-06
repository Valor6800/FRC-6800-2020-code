#include "subsystems/Arm.h"

Arm::Arm() : leftArmMtr{ArmConstants::TALON_ID_LEFT_ARM}, 
             rightArmMtr{ArmConstants::TALON_ID_RIGHT_ARM} {
    InitArm();   
}

Arm& Arm::GetInstance() {
    static Arm instance;
    return instance;
}

void Arm::InitArm() {

}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    armMtrs.Set(power);
}