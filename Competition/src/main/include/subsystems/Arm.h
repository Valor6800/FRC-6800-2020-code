#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/ProfiledPIDSubsystem.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/PWMVictorSPX.h>
#include <units/units.h>
#include <ctre/Phoenix.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "networktables/NetworkTable.h"
#include <frc/livewindow/LiveWindow.h>

#ifndef ARM_H
#define ARM_H

class Arm/* : public frc2::ProfiledPIDSubsystem<units::degrees>*/ : public frc2::SubsystemBase {
    //using State = frc::TrapezoidProfile<units::degrees>::State;
  public:
     Arm();

     static Arm& GetInstance();

    //  void UseOutput(double output, State setpoint) override;
    //  units::degree_t GetMeasurement() override;

     void InitArm();

     void Periodic() override;
     void SetArmPower(double power);
     void SetArmPowerAuto(double power);

 private:

     // talons
     TalonSRX armMtrLeft;
     TalonSRX armMtrRight;

     double appliedPow;

};

#endif
