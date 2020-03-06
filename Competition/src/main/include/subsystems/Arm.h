#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/ProfiledPIDSubsystem.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/PWMVictorSPX.h>
#include <units/units.h>

#ifndef ARM_H
#define ARM_H

class Arm : public frc2::SubsystemBase {
  public:

     Arm();

     static Arm& GetInstance();
     void InitArm();

     void Periodic() override;

     void SetArmPower(double power);

 private:

     // talons
     frc::PWMVictorSPX leftArmMtr;
     frc::PWMVictorSPX rightArmMtr;

     frc::SpeedControllerGroup armMtrs{leftArmMtr, rightArmMtr};

};

#endif
