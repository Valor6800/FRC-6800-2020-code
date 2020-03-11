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
    frc::SmartDashboard::PutNumber("arm applied power", appliedPow);
}

void Arm::SetArmPower(double power) {
    if (std::abs(power) <= 0.05) {
        armMtrLeft.Set(ControlMode::PercentOutput, 0);
        armMtrRight.Set(ControlMode::PercentOutput, 0);
    } else if (power < -.05) {
        armMtrLeft.Set(ControlMode::PercentOutput, -0.5);
        armMtrRight.Set(ControlMode::PercentOutput, -0.5);
    } else if (power > .05 && power < 0.85) {
        armMtrLeft.Set(ControlMode::PercentOutput, -0.042);
        armMtrRight.Set(ControlMode::PercentOutput, -0.042);
    } else {
        armMtrLeft.Set(ControlMode::PercentOutput, 0.1);
        armMtrRight.Set(ControlMode::PercentOutput, 0.1);
    }
    appliedPow = power;
}

void Arm::SetArmPowerAuto(double power) {
    armMtrLeft.Set(ControlMode::PercentOutput, -power);
    armMtrRight.Set(ControlMode::PercentOutput, -power);
}