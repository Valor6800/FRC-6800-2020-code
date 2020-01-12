#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/XboxController.h>

#include "subsystems/Arm.h"
#include "subsystems/Muncher.h"
#include "subsystems/Shooter.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/IT.h"
#include "subsystems/Lift.h"

#include "commands/DriveManual.h"
#include "commands/Shoot.h"
#include "commands/SpinIT.h"

#define GAMEPAD_BASE_LOCATION 1
#define GAMEPAD_OPERATOR_LOCATION 0

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
    RobotContainer();

   // frc2::Command* GetAutonomousCommand();
    frc::XboxController mGamepadDriver{GAMEPAD_BASE_LOCATION};
    frc::XboxController mGamepadOperator{GAMEPAD_OPERATOR_LOCATION};

    // Arm m_arm;
    // IT m_it;
    // Lift m_lift;
    // Shooter m_shooter;
    // Muncher m_muncher;


    frc2::Command* m_default = nullptr;
    // Shoot m_shoot;
    // SpinIT m_spinIT;
 private:
  // The robot's subsystems and commands are defined here...
  DriveManual m_driveManual;

  Drivetrain *m_drivetrain;
 
    

  void ConfigureButtonBindings();
};
