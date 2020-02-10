#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/PWMVictorSPX.h>

class Arm : public frc2::SubsystemBase {
  public:

     Arm();

     static Arm& GetInstance();

     void Periodic() override;
     void SetArmPower(double power);

 private:

     // talons
     frc::PWMVictorSPX leftArmMtr;
     frc::PWMVictorSPX rightArmMtr;

     // 2 servos

     frc::SpeedControllerGroup armMtrs{leftArmMtr, rightArmMtr};

    // add 2 encoders for arm

};
