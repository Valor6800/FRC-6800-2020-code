#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/XboxController.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"

#include "commands/DriveManual.h"
#include "commands/Shoot.h"

#include "Constants.h"
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

// using namespace Constants;

class RobotContainer {
 public:
    RobotContainer();

   // frc2::Command* GetAutonomousCommand();

    // SpinIT m_spinIT;

 private:
   // The robot's subsystems and commands are defined here...

   frc::XboxController mGamepadDriver{GAMEPAD_BASE_LOCATION};
   frc::XboxController mGamepadOperator{GAMEPAD_OPERATOR_LOCATION};

    // Arm m_arm;
    // IT m_it;
    // Lift m_lift;
    // Muncher m_muncher;
    Drivetrain m_drivetrain;
    // Shooter m_shooter;

  void ConfigureButtonBindings();
};
