#include "RobotContainer.h"

#define GAMEPAD_BASE_LOCATION 1
#define GAMEPAD_OPERATOR_LOCATION 0

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    frc::XboxController mGamepadDriver{GAMEPAD_DRIVER_LOCATION};
    frc::XboxController mGamepadOperator{GAMEPAD_OPERATOR_LOCATION};
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
