#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/XboxController.h>
//#include <frc2/command/button/Button.h>
#include <frc2/command/button/JoystickButton.h>


#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Throat.h"
#include "subsystems/Arm.h"
#include "subsystems/Lift.h"
#include "subsystems/Muncher.h"

#include "commands/DriveManual.h"
#include "commands/ShootStart.h"
#include "commands/SpinIntake.h"
#include "commands/SpinThroat.h"
#include "commands/ShootStop.h"
#include "commands/ArmManual.h"
#include "commands/Climb.h"

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


   // frc2::Command* GetAutonomousCommand();
   frc2::Command* GetShootCommmand();

 private:
   // The robot's subsystems and commands are defined here...

    frc::XboxController m_GamepadDriver{GAMEPAD_BASE_LOCATION};
    frc::XboxController m_GamepadOperator{GAMEPAD_OPERATOR_LOCATION};

    Drivetrain m_drivetrain;
    Intake m_intake;
    Throat m_throat;
    Arm m_arm;
    Shooter m_shooter;
    Lift m_lift;
    // Muncher m_muncher;
    
  void ConfigureButtonBindings();
};
