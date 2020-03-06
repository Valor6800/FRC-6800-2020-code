#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"
#include <frc/Servo.h>
#include <frc/PWMVictorSPX.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "networktables/NetworkTable.h"
#include <frc/livewindow/LiveWindow.h>
#include <frc/AnalogPotentiometer.h>

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter : public frc2::SubsystemBase {
 public:

    Shooter();

    static Shooter& GetInstance();
    void InitShooter();

    void Periodic() override;
    
    void SetShooterPower(double power);
    
    double GetShooterNTPower();

    void ExtendHood();
    void RetractHood();
    void StopHood();

    void SetHoodTarget(double target);
    
 private:

    rev::CANSparkMax shootMtrLeft;
    rev::CANSparkMax shootMtrRight;
    
    frc::SpeedControllerGroup shootMtrs{shootMtrLeft, shootMtrRight};
    
    frc::Servo hoodServoLeft;
    frc::Servo hoodServoRight;

    frc::AnalogPotentiometer hoodPotentiometer;
    nt::NetworkTableEntry shooterPower;
    nt::NetworkTableEntry potentiometerBoolean;

    double hoodTarget;

    bool extending;

    double deadzone;

    double shooterPow;

};

#endif