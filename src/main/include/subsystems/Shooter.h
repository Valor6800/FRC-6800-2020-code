#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/Servo.h>

class Shooter : public frc2::SubsystemBase {
 public:

    Shooter();

    void SetShooterPower(double power);
    void TiltHood(double pos);
    void Periodic() override;

 private:

   // need to add encoder?
   // check controller type
    rev::CANSparkMax shooter;
    frc::Servo hood;
    
};