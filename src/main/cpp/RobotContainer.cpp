#include "RobotContainer.h"

#include "commands/DriveManual.h"


RobotContainer::RobotContainer() /*: m_driveManual(&m_drivetrain)*/ {
  // Initialize all of your commands and subsystems here

  m_drivetrain->SetDefaultCommand(DriveManual(m_drivetrain,
      [this] { return mGamepadDriver.GetY(frc::GenericHID::kLeftHand); },
      [this] { return mGamepadDriver.GetX(frc::GenericHID::kRightHand); }));
         
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    
    
}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return &m_autonomousCommand;
// }
