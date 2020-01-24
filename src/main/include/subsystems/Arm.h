#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"
#include <frc/SpeedControllerGroup.h>

class Arm : public frc2::SubsystemBase {
  public:

     Arm();
     void Periodic() override;
     void SetArmPower(double power);

 private:

     // motor type not decided
     rev::CANSparkMax leftArmMtr;
     rev::CANSparkMax rightArmMtr;

     frc::SpeedControllerGroup armMtrs{leftArmMtr, rightArmMtr};

    // add 2 encoders for arm

};
