#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/XboxController.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/IT.h"

#include "commands/DriveManual.h"
#include "commands/Shoot.h"
#include "commands/SpinIT.h"

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

 private:
   // The robot's subsystems and commands are defined here...

   frc::XboxController mGamepadDriver{GAMEPAD_BASE_LOCATION};
   frc::XboxController mGamepadOperator{GAMEPAD_OPERATOR_LOCATION};

    Drivetrain m_drivetrain;
    IT m_it;
    // Arm m_arm;
    Shooter m_shooter;
    
    // Lift m_lift;
    // Muncher m_muncher;
    
    

  void ConfigureButtonBindings();
};
