#include "RobotContainer.h"



RobotContainer::RobotContainer() /*: m_autonomousCommand(&m_subsystem)*/ {
  // Initialize all of your commands and subsystems here
  
  m_drivetrain->SetDefaultCommand(&m_drivetrain, DriveManual(m_drivetrain,
         mGamepadDriver.GetY(frc::GenericHID::JoystickHand::kLeftHand),
         mGamepadDriver.GetX(frc::GenericHID::JoystickHand::kRightHand)));
         
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    
    
}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return &m_autonomousCommand;
// }
