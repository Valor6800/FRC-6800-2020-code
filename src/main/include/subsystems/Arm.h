#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"

class Arm : public frc2::SubsystemBase {
  public:

     Arm();
     void Periodic() override;
     void SetArmPower(double power);

 private:

     rev::CANSparkMax armMtr;
    //add potentiometer/gyro? to track position
    //limit switch?

};
