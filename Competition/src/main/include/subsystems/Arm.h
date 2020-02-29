#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/ProfiledPIDSubsystem.h>
#include "Constants.h"
#include <frc/SpeedControllerGroup.h>
#include <units/units.h>

#ifndef ARM_H
#define ARM_H

class Arm/* : public frc2::ProfiledPIDSubsystem<units::degrees>*/ : public frc2::SubsystemBase {
    //using State = frc::TrapezoidProfile<units::degrees>::State;
  public:
     Arm();

     static Arm& GetInstance();

    //  void UseOutput(double output, State setpoint) override;
    //  units::degree_t GetMeasurement() override;

     void Periodic() override;
     void SetArmPower(double power);

 private:

     // 2 servos

    //  frc::SpeedControllerGroup armMtrs{leftArmMtr, rightArmMtr};

    // add 2 encoders for arm

};

#endif
