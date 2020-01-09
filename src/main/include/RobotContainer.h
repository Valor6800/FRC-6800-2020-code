#pragma once

#include <frc2/command/Command.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Arm.h"
#include "subsystems/IT.h"
#include "subsystems/Lift.h"
#include "subsystems/Muncher.h"
#include "subsystems/Shooter.h"

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

    frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
    Drivetrain m_drivetrain;
    Arm m_arm;
    IT m_it;
    Lift m_lift;
    Shooter m_shooter;
    Muncher m_muncher;

    ExampleCommand m_autonomousCommand;

  void ConfigureButtonBindings();
};
