#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>

class Lift : public frc2::SubsystemBase {
 public:

    Lift();

    void SetLiftPower(double power);
    void Periodic() override;

 private:

   // need to add encoder
   // limit switch?
   // ratchet with servo?
    frc::VictorSP liftA;
    frc::VictorSP liftB;

};