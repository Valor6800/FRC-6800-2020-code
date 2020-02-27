#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>
#include <rev/CANPIDController.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"
#include <frc/Servo.h>
#include <frc/PWMVictorSPX.h>
#include <frc/AnalogPotentiometer.h>

#ifndef SHOOTER_H
#define SHOOTER_H

#define kMaxRPM 5700
#define kProp 0
#define kInte 0
#define kDeriv 0
#define kIzone 0
#define kFeedForward 1.0/kMaxRPM
#define miOutput 0.0
#define maOutput 1.0

class Shooter : public frc2::SubsystemBase {
 public:
    Shooter();

    static Shooter& GetInstance();
    void InitShooter();
    
    void Periodic() override;

    void SetShooterPower(double power);
    void ExtendHood();
    void RetractHood();

    double GetPotentiometerAvg();
    bool HoodExtended();
    bool HoodRetracted();
    
 private:
    rev::CANSparkMax shootMtrLeft;
    rev::CANSparkMax shootMtrRight;

    rev::CANEncoder encoderLeft = shootMtrLeft.GetEncoder();
    rev::CANEncoder encoderRight = shootMtrRight.GetEncoder();

    rev::CANPIDController m_shootMtrLeftPID = shootMtrLeft.GetPIDController();
    rev::CANPIDController m_shootMtrRightPID = shootMtrRight.GetPIDController();

    frc::Servo hoodServoLeft;
    frc::Servo hoodServoRight;

    frc::AnalogPotentiometer hoodPotentiometerLeft;
    frc::AnalogPotentiometer hoodPotentiometerRight;
    
    frc::SpeedControllerGroup shootMtrs{shootMtrLeft, shootMtrRight};

};

#endif