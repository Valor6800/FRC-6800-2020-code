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
    // Configure the button bindings
    ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    // Start shooter button (Operator: Start)
    frc2::JoystickButton operator_start{&m_GamepadOperator, 8};
    // Stop shooter button (Operator: Back)
    frc2::JoystickButton operator_back{&m_GamepadOperator, 7};

    // Driver button (unused) (Driver: A)
    frc2::JoystickButton driver_a{&m_GamepadDriver, 1};
    // Driver boost button (Driver: B)
    frc2::JoystickButton driver_b{&m_GamepadDriver, 2};
    // Driver button (unused) (Driver: X)
    frc2::JoystickButton driver_x{&m_GamepadDriver, 3};
    // Driver button (unused) (Driver: Y)
    frc2::JoystickButton driver_y{&m_GamepadDriver, 4};

    // Operator button (unused) (Operator: A)
    frc2::JoystickButton operator_a{&m_GamepadOperator, 1};
    // Operator boost button (Operator: B)
    frc2::JoystickButton operator_b{&m_GamepadOperator, 2};
    // Operator button (unused) (Operator: X)
    frc2::JoystickButton operator_x{&m_GamepadOperator, 3};
    // Operator button (unused) (Operator: Y)
    frc2::JoystickButton operator_y{&m_GamepadOperator, 4};
}
