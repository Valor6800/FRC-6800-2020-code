#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/InstantCommand.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Hopper.h"
#include "subsystems/Arm.h"
#include "subsystems/Lift.h"
#include "subsystems/Muncher.h"

#include "commands/Auto/HomeTrenchAuto.h"

#include "Constants.h"
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic shouldP
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

// using namespace Constants;

class RobotContainer {
 public:
    RobotContainer();
    frc2::Command* GetAutonomousCommand(int numTrajectories);

 private:
   frc::XboxController m_GamepadDriver{OIConstants::GAMEPAD_BASE_LOCATION};
   frc::XboxController m_GamepadOperator{OIConstants::GAMEPAD_OPERATOR_LOCATION};
 
   Drivetrain& m_drivetrain = Drivetrain::GetInstance();
   Intake& m_intake = Intake::GetInstance();
   Hopper& m_hopper = Hopper::GetInstance();
   Arm& m_arm = Arm::GetInstance();
   Shooter& m_shooter = Shooter::GetInstance();
   Lift& m_lift = Lift::GetInstance();
   Muncher& m_muncher = Muncher::GetInstance();

   frc::SendableChooser<frc2::Command*> chooser; // Give options for autonomous actions
   
   void ConfigureButtonBindings();
};
