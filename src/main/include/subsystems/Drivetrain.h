#pragma once

#include <frc2/command/TrapezoidProfileSubsystem.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase{
 public:

    Drivetrain();

    void Periodic() override;

    void Move(double leftInput, double rightInput);

    void Stop();

 private:

    rev::CANSparkMax leftDriveA;
    rev::CANSparkMax leftDriveB;
    rev::CANSparkMax leftDriveC;
    rev::CANSparkMax rightDriveA;
    rev::CANSparkMax rightDriveB;
    rev::CANSparkMax rightDriveC;

    frc::SpeedControllerGroup leftDrive{leftDriveA, leftDriveB, leftDriveC};
    frc::SpeedControllerGroup rightDrive{rightDriveA, rightDriveB, rightDriveC};

    frc::DifferentialDrive drive{leftDrive, rightDrive};

};