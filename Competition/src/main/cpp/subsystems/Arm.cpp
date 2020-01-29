#include "subsystems/Arm.h"

Arm::Arm() : leftArmMtr{CAN_ID_LEFT_ARM, rev::CANSparkMax::MotorType::kBrushless}, 
             rightArmMtr{CAN_ID_RIGHT_ARM, rev::CANSparkMax::MotorType::kBrushless} {
    leftArmMtr.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightArmMtr.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    armMtrs.Set(power);
}