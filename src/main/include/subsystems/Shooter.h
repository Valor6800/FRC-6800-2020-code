#pragma once

#include <frc2/command/SubsystemBase.h>
// #include <frc/VictorSP.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
//#include <frc/Servo.h>
#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
 public:

    Shooter();

    void SetShooterPower(double power);
    //void TiltHood(double pos);
    void Periodic() override;
    void Stop();
 private:

   // need to add encoder?
   // check controller type
    frc::PWMVictorSPX flywheelA;
    frc::PWMVictorSPX flywheelB;

    frc::SpeedControllerGroup flywheel{flywheelA, flywheelB};

   // frc::Servo hood;
    
};