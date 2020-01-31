#include "RobotContainer.h"


RobotContainer::RobotContainer() /*: m_driveManual(&m_drivetrain)*/ {
  // Initialize all of your commands and subsystems here
 
  m_drivetrain.SetDefaultCommand(DriveManual(&m_drivetrain,
      [this] { return m_GamepadDriver.GetY(frc::GenericHID::kLeftHand); },
      [this] { return m_GamepadDriver.GetX(frc::GenericHID::kRightHand); }));

  m_intake.SetDefaultCommand(SpinIntake(&m_intake, [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kRightHand); }, [this] { return m_GamepadDriver.GetBumper(frc::GenericHID::kRightHand); }));
        
  m_hopper.SetDefaultCommand(SpinHopper(&m_hopper, [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kLeftHand); }, [this] { return m_GamepadDriver.GetBumper(frc::GenericHID::kLeftHand); }));

  m_arm.SetDefaultCommand(ArmManual(&m_arm, [this] { return m_GamepadDriver.GetY(frc::GenericHID::kLeftHand); }));

  m_lift.SetDefaultCommand(Climb(&m_lift, [this] { return m_GamepadDriver.GetY(frc::GenericHID::kRightHand); }));

  m_muncher.SetDefaultCommand(Munch(&m_muncher, [this] { return m_GamepadDriver.GetYButton(); }));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton m_start{&m_GamepadDriver, 8};
    frc2::JoystickButton m_back{&m_GamepadDriver, 7};

    // frc::JoystickButton m_a{&m_GamepadDriver, 1};
    // frc::JoystickButton m_b{&m_GamepadDriver, 2};
    // frc::JoystickButton m_x{&m_GamepadDriver, 3};
    frc::JoystickButton m_y{&m_GamepadDriver, 4};
    
    m_y.WhenPressed(frc2::InstantCommand([&m_drivetrain] { m_drivetrain.SetMultiplier(.5); }, {&m_drivetrain}));

    m_start.WhenPressed(ShootStart(&m_shooter));
    m_back.WhenPressed(ShootStop(&m_shooter));
    
}
// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return &m_autonomousCommand;
// }
