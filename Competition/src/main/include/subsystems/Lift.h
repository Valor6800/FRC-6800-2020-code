#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SpeedControllerGroup.h>
#include "Constants.h"
#include <frc/Servo.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "networktables/NetworkTable.h"
#include <frc/livewindow/LiveWindow.h>

#ifndef LIFT_H
#define LIFT_H

class Lift : public frc2::SubsystemBase {
 public:

    Lift();

    static Lift& GetInstance();

    void SetLiftPower(double power);
    void Periodic() override;
    void LiftDrive(double stickInput);

    void LockRatchet();
    void UnlockRatchet();

 private:

    frc::PWMVictorSPX liftMtrLeft;
    frc::PWMVictorSPX liftMtrRight;

    frc::SpeedControllerGroup liftMtrs{liftMtrLeft, liftMtrRight};

    frc::Servo ratchetServoLeft;
    frc::Servo ratchetServoRight;

};

#endif