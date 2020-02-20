#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/ProfiledPIDSubsystem.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/PWMVictorSPX.h>
#include <units/units.h>
#include <frc/controller/ArmFeedforward.h>
// #include <ctre/Phoenix.h>
// #include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

#ifndef ARM_H
#define ARM_H

class Arm : public frc2::ProfiledPIDSubsystem<units::degrees> /*: public frc2::SubsystemBase*/{
  
  using State = frc::TrapezoidProfile<units::degrees>::State;
  public:
     Arm();

     static Arm& GetInstance();
     void InitArm();

     void Periodic() override;

     void SetArmPower(double power);

     void UseOutput(double output, State setpoint) override;
     units::degree_t GetMeasurement() override;

 private:

     // talons
     frc::PWMVictorSPX armMtrLeft;
     frc::PWMVictorSPX armMtrRight;
      
    // TalonSRX armMtrLeft;
    // TalonSRX armMtrRight;
     frc::ArmFeedforward m_feedforward;

     units::volt_t feedforward;
     

    // add 2 encoders for arm

};

#endif
