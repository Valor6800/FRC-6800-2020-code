#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"
#include <frc/Servo.h>

class Shooter : public frc2::SubsystemBase {
 public:

    Shooter();

    static Shooter& GetInstance();

    void SetShooterPower(double power);
    void Periodic() override;
    void Stop();
 private:
    rev::CANSparkMax shootMtrA;
    rev::CANSparkMax shootMtrB;

    frc::SpeedControllerGroup shootMtrs{shootMtrA, shootMtrB};

    frc::Servo hood;

};