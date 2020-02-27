#include "subsystems/Arm.h"

Arm::Arm() : leftArmMtr{ArmConstants::TALON_ID_LEFT_ARM}, rightArmMtr{ArmConstants::TALON_ID_RIGHT_ARM} {
    InitArm();
}

Arm& Arm::GetInstance()
{
    static Arm instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Arm::InitArm() {
    leftArmMtr.ConfigFactoryDefault();
    rightArmMtr.ConfigFactoryDefault();

    leftArmMtr.SetInverted(false);
    rightArmMtr.SetInverted(true);
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    leftArmMtr.Set(ControlMode::PercentOutput, power * 0.25);
    rightArmMtr.Set(ControlMode::PercentOutput, power * 0.25);
}