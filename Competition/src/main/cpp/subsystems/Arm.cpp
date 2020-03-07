#include "subsystems/Arm.h"

Arm::Arm() : armMtrLeft{ArmConstants::TALON_ID_LEFT_ARM}, 
             armMtrRight{ArmConstants::TALON_ID_RIGHT_ARM} {
    
}

Arm& Arm::GetInstance() {
    static Arm instance;
    return instance;
}

void Arm::InitArm() {
    armMtrLeft.ConfigFactoryDefault();
    armMtrRight.ConfigFactoryDefault();

    armMtrLeft.SetNeutralMode(NeutralMode::Brake);
    armMtrRight.SetNeutralMode(NeutralMode::Brake);

    armMtrLeft.SetInverted(false);
    armMtrRight.SetInverted(false);
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    armMtrLeft.Set(ControlMode::PercentOutput, power * 0.25);
    armMtrRight.Set(ControlMode::PercentOutput, power * 0.25);
}