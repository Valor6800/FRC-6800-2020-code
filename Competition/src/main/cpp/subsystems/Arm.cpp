#include "subsystems/Arm.h"

Arm::Arm() : leftArmMtr{ArmConstants::CAN_ID_LEFT_ARM, rev::CANSparkMax::MotorType::kBrushless}, 
             rightArmMtr{ArmConstants::CAN_ID_RIGHT_ARM, rev::CANSparkMax::MotorType::kBrushless} {
    leftArmMtr.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightArmMtr.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    armMtrs.Set(power);
}