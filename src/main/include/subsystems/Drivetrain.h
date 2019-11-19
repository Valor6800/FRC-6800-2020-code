/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/PIDSubsystem.h>

#include <rev/CANSparkMax.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

/**
 * Drivetrain subsytem for moving the chassis
 * @author Michael Ray
 * @version 1.0
 **/
class Drivetrain : public frc::PIDSubsystem {

// Variables
private:

    // Member variables for the 4 drive motors
    rev::CANSparkMax leftDriveA;
    rev::CANSparkMax leftDriveB;
    rev::CANSparkMax rightDriveA;
    rev::CANSparkMax rightDriveB;

    // Speed controller groups
    frc::SpeedControllerGroup leftDrive {leftDriveA, leftDriveB};
    frc::SpeedControllerGroup rightDrive {rightDriveA, rightDriveB};

    // Drivetrain style
    frc::DifferentialDrive drive{leftDrive, rightDrive};

// Functions
public:

    /**
     * Default constructor
     **/
    Drivetrain();

    /**
     * Initialize the default command to run with this subsystem
     **/
    void InitDefaultCommand() override;

    double ReturnPIDInput() override;

    void UsePIDOutput(double output) override;

    /**
     * Stop the drive
     **/
    void stop();

    void reset();

    /**
     * Move with a left and right input specified.
     * Helper function so that we can specify the drive type in one place
     * @param leftInput Input from the left joystick
     * @param rightInput Input from the right joystick
     **/
    void move(double leftInput, double rightInput);
};
