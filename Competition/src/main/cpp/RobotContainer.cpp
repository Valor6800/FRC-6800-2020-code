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

    m_arm.SetDefaultCommand(ArmManual(m_arm, 
        [this] { return m_GamepadDriver.GetY(frc::GenericHID::kLeftHand); }));

    m_lift.SetDefaultCommand(Climb(m_lift, 
        [this] { return m_GamepadDriver.GetY(frc::GenericHID::kRightHand); }));

    // Configure the button bindings
    ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton driver_rightBumper{&m_GamepadDriver, 6};
    frc2::JoystickButton driver_leftBumper{&m_GamepadDriver, 5};

    frc2::JoystickButton operator_start{&m_GamepadOperator, 8};
    frc2::JoystickButton operator_back{&m_GamepadOperator, 7};
    frc2::JoystickButton operator_leftBumper{&m_GamepadOperator, 5};
    frc2::JoystickButton operator_rightBumper{&m_GamepadOperator, 6};

    frc2::JoystickButton m_a{&m_GamepadDriver, 1};
    frc2::JoystickButton operator_b{&m_GamepadOperator, 2};
    frc2::JoystickButton m_x{&m_GamepadDriver, 3};
    frc2::JoystickButton operator_y{&m_GamepadOperator, 4};

    
    driver_rightBumper.WhenPressed(frc2::InstantCommand([&] { m_drivetrain.SetMultiplier(1); }, {&m_drivetrain}));
    driver_rightBumper.WhenReleased(frc2::InstantCommand([&] { m_drivetrain.SetMultiplier(0.5); }, {&m_drivetrain}));

    driver_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(0.5); }));
    driver_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_hopper.SetHopperPower(0.5); }));
    driver_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); }));
    driver_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_hopper.SetHopperPower(0); }));

    operator_start.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(1); }, {&m_shooter}));
    operator_back.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0); }, {&m_shooter}));

    operator_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(0.5); }, {&m_intake}));
    operator_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); }, {&m_intake}));
    operator_rightBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(-0.5); }, {&m_intake}));
    operator_rightBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); }, {&m_intake}));
    
    operator_y.WhenPressed(frc2::InstantCommand([&] { m_muncher.SetMunchPower(1); }, {&m_muncher}));
}

frc2::Command* GetAutonomousCommand(int numTrajectories) {
    auto trajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
      {frc::Translation2d(2.3_m, -1.3_m)},
      frc::Pose2d(7.5_m, -1.3_m, frc::Rotation2d(0_deg)),
      m_drivetrain.kTrajectoryConfig);

    frc2::RamseteCommand ramseteCommand(
      trajectory, [&] () { return m_drivetrain.GetPose(); },
      frc::RamseteController(RamseteConstants::kRamseteB, RamseteConstants::kRamseteZeta),
      m_drivetrain.kSimpleMotorFeedforward,
      m_drivetrain.kDriveKinematics,
      [&] { return m_drivetrain.GetWheelSpeeds(); },
      frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
      frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
      [&] (auto left, auto right) { m_drivetrain.TankDriveVolts(left, right); },
      {m_drivetrain});

    return new frc2::SequentialCommandGroup(
      std::move(ramseteCommand),
      frc2::InstantCommand([&] { m_drivetrain.TankDriveVolts(0_V, 0_V); }, {}));
}
