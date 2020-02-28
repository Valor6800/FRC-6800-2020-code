#include "subsystems/Arm.h"

// Arm::Arm() : frc2::ProfiledPIDSubsystem<units::degrees>
//                 (frc::ProfiledPIDController<units::degrees>(ArmConstants::kP, 0, 0, {ArmConstants::kMaxSpeed, ArmConstants::kMaxAcceleration})),
//              armMtrLeft{ArmConstants::TALON_ID_ARM_LEFT}, 
//              armMtrRight{ArmConstants::TALON_ID_ARM_RIGHT},
//              m_feedforward(ArmConstants::kS, ArmConstants::kCos, ArmConstants::kV, ArmConstants::kA) {
//     InitArm();
//     SetGoal(State{ArmConstants::kArmOffset, 0_rad_per_s});
// }

// Arm& Arm::GetInstance() {
//     static Arm instance;
//     return instance;
// }

// void Arm::InitArm() {
//     armMtrLeft.ConfigFactoryDefault();
//     armMtrRight.ConfigFactoryDefault();

//     armMtrLeft.SetInverted(false);
//     armMtrRight.SetInverted(true);
// }

// void Arm::Periodic() {
  
// }

// void Arm::SetArmPower(double power) {
//     armMtrLeft.Set(power);
//     armMtrRight.Set(power);
// }

// void Arm::UseOutput(double output, State setpoint) {
//   feedforward = m_feedforward.Calculate(setpoint.position, setpoint.velocity);

// //   armMtrLeft.SetVoltage(units::volt_t(output) + feedforward);
// //   armMtrLeft.
// //   armMtrRight.SetVoltage(units::volt_t(output) + feedforward);
// }

// units::degree_t Arm::GetMeasurement() {
//   //return units::degree_t(m_encoder.GetDistance()) + ArmConstants::kArmOffset;
//   return 0_deg;
// }

Arm::Arm() : armMtrLeft{ArmConstants::TALON_ID_ARM_LEFT}, armMtrRight{ArmConstants::TALON_ID_ARM_RIGHT} {
    InitArm();
}

Arm& Arm::GetInstance() {
    static Arm instance;
    return instance;
}

void Arm::InitArm() {
    armMtrLeft.ConfigFactoryDefault();
    armMtrRight.ConfigFactoryDefault();

    // armMtrLeft.ConfigForwardLimitSwitchSource(motorcontrol::LimitSwitchSource_Deactivated, motorcontrol::LimitSwitchNormal_Disabled, 10);
    // armMtrLeft.ConfigReverseLimitSwitchSource(motorcontrol::LimitSwitchSource_Deactivated, motorcontrol::LimitSwitchNormal_Disabled, 10);
    // armMtrRight.ConfigForwardLimitSwitchSource(motorcontrol::LimitSwitchSource_Deactivated, motorcontrol::LimitSwitchNormal_Disabled, 10);
    // armMtrRight.ConfigReverseLimitSwitchSource(motorcontrol::LimitSwitchSource_Deactivated, motorcontrol::LimitSwitchNormal_Disabled, 10);

    armMtrLeft.SetInverted(false);
    armMtrRight.SetInverted(true);
}

void Arm::Periodic() {
  
}

void Arm::SetArmPower(double power) {
    armMtrLeft.Set(ControlMode::PercentOutput, power * 0.25);
    armMtrRight.Set(ControlMode::PercentOutput, power * 0.25);
}

bool Arm::GetRestLimitSwitches() {
    return restLimitSwitchLeft.Get() && restLimitSwitchRight.Get();
}