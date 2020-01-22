#include "subsystems/Arm.h"

Arm::Arm() : armMtr{CAN_ID_ARM, rev::CANSparkMax::MotorType::kBrushless} {
    armMtr.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    armMtr.Set(power);
}
 