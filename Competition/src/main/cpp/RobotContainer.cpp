#include "RobotContainer.h"

#include "commands/DriveManual.h"
#include "commands/ShootStart.h"
#include "commands/SpinIntake.h"
#include "commands/SpinHopper.h"
#include "commands/ShootStop.h"
#include "commands/ArmManual.h"
#include "commands/Climb.h"
#include "commands/Munch.h"

RobotContainer::RobotContainer() {
    m_drivetrain.SetDefaultCommand(DriveManual(m_drivetrain,
        [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kRightHand); },
        [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kLeftHand); },
        [this] { return m_GamepadDriver.GetX(frc::GenericHID::kLeftHand); },
        [this] { return m_GamepadDriver.GetBumper(frc::GenericHID::kLeftHand); }));

    m_intake.SetDefaultCommand(SpinIntake(m_intake, 
        [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kRightHand); }, 
        [this] { return m_GamepadDriver.GetBumper(frc::GenericHID::kRightHand); }));
            
    m_hopper.SetDefaultCommand(SpinHopper(m_hopper, 
        [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kLeftHand); }, 
        [this] { return m_GamepadDriver.GetBumper(frc::GenericHID::kLeftHand); }));

    m_arm.SetDefaultCommand(ArmManual(m_arm, 
        [this] { return m_GamepadDriver.GetY(frc::GenericHID::kLeftHand); }));

    m_lift.SetDefaultCommand(Climb(m_lift, 
        [this] { return m_GamepadDriver.GetY(frc::GenericHID::kRightHand); }));

    m_muncher.SetDefaultCommand(Munch(m_muncher, 
        [this] { return m_GamepadDriver.GetYButton(); }));

    // Configure the button bindings
    ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton operator_start{&m_GamepadOperator, 8};
    frc2::JoystickButton operator_back{&m_GamepadOperator, 7};

    // frc::JoystickButton m_a{&m_GamepadDriver, 1};
    frc2::JoystickButton operator_b{&m_GamepadOperator, 2};
    // frc::JoystickButton m_x{&m_GamepadDriver, 3};
    //frc2::JoystickButton m_y{&m_GamepadDriver, 4};
    frc2::JoystickButton driver_rightBumper{&m_GamepadDriver, 6};
    
    driver_rightBumper.WhenPressed(frc2::InstantCommand([this] { m_drivetrain.SetMultiplier(1); }, {&m_drivetrain}));
    driver_rightBumper.WhenReleased(frc2::InstantCommand([this] { m_drivetrain.SetMultiplier(0.5); }, {&m_drivetrain}));

    operator_start.WhenPressed(ShootStart(m_shooter));
    operator_back.WhenPressed(ShootStop(m_shooter));
}
