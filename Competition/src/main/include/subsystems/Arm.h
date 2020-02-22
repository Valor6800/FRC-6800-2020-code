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

// class Arm : public frc2::ProfiledPIDSubsystem<units::degrees> {
  
//   using State = frc::TrapezoidProfile<units::degrees>::State;
//   public:
//      Arm();

//      static Arm& GetInstance();
//      void InitArm();

//      void Periodic() override;

//      void SetArmPower(double power);

//      void UseOutput(double output, State setpoint) override;
//      units::degree_t GetMeasurement() override;

//  private:

//      // talons
//      frc::PWMVictorSPX armMtrLeft;
//      frc::PWMVictorSPX armMtrRight;

//      ctre::phoenix::motorcontrol::can::TalonSRX armMtrLeft;
//      ctre::phoenix::motorcontrol::can::TalonSRX armMtrRight;
    
//      frc::ArmFeedforward m_feedforward;

//      units::volt_t feedforward;
     

//     // add 2 encoders for arm

// };

class Arm : public frc2::SubsystemBase {

  public:
     Arm();

     static Arm& GetInstance();
     void InitArm();

     void Periodic() override;

     void SetArmPower(double power);

 private:
    //  ctre::phoenix::motorcontrol::can::TalonSRX armMtrLeft;
    //  ctre::phoenix::motorcontrol::can::TalonSRX armMtrRight;     

    // add 2 encoders for arm

};

#endif
