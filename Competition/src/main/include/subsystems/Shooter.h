#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"
#include <frc/Servo.h>
#include <frc/PWMVictorSPX.h>

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter : public frc2::SubsystemBase {
 public:
    Shooter();

    static Shooter& GetInstance();

    void SetShooterPower(double power);
    void Periodic() override;
    void InitShooter(rev::CANSparkMax::IdleMode idleMode);
    
 private:
    rev::CANSparkMax shootMtrLeft;
    rev::CANSparkMax shootMtrRight;
    
    frc::SpeedControllerGroup shootMtrs{shootMtrLeft, shootMtrRight};
    

    frc::Servo hood;

};

#endif