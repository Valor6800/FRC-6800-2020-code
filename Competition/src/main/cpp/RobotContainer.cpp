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
        [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kLeftHand); },
        [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kRightHand); },
        [this] { return m_GamepadDriver.GetX(frc::GenericHID::kLeftHand); },
        [this] { return m_GamepadDriver.GetYButton(); }));

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

    frc2::JoystickButton driver_start{&m_GamepadDriver, 8};
    frc2::JoystickButton driver_back{&m_GamepadDriver, 7};

    frc2::JoystickButton operator_start{&m_GamepadOperator, 8};
    frc2::JoystickButton operator_back{&m_GamepadOperator, 7};
    frc2::JoystickButton operator_leftBumper{&m_GamepadOperator, 5};
    frc2::JoystickButton operator_rightBumper{&m_GamepadOperator, 6};

    frc2::JoystickButton driver_a{&m_GamepadDriver, 1};
    frc2::JoystickButton driver_b{&m_GamepadDriver, 2};
    frc2::JoystickButton driver_x{&m_GamepadDriver, 3};

    frc2::JoystickButton operator_y{&m_GamepadOperator, 4};
    frc2::JoystickButton operator_b{&m_GamepadOperator, 2};

    //for running drivetrain for 8 min
    // driver_a.WhenPressed(DriveManual(m_drivetrain,
    //     [this] { return 1; },
    //     [this] { return 0; },
    //     [this] { return 0; },
    //     [this] { return false; }));
    // driver_x.WhenPressed(DriveManual(m_drivetrain,
    //     [this] { return 0; },
    //     [this] { return 1; },
    //     [this] { return 0; },
    //     [this] { return false; }));
    // driver_b.WhenPressed(DriveManual(m_drivetrain,
    //     [this] { return 0; },
    //     [this] { return 0; },
    //     [this] { return 0; },
    //     [this] { return false; }));
    


    driver_rightBumper.WhenPressed(frc2::InstantCommand([&] { m_drivetrain.SetMultiplier(1); }, {&m_drivetrain}));
    driver_rightBumper.WhenReleased(frc2::InstantCommand([&] { m_drivetrain.SetMultiplier(0.5); }, {&m_drivetrain}));

    driver_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(0.8); m_hopper.SetHopperPower(1); }));
    driver_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); m_hopper.SetHopperPower(0); }));

    operator_back.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(m_shooter.GetShooterNTPower()); }, {&m_shooter}));
    operator_start.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0); }, {&m_shooter}));

    // driver_start.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(1); }, {&m_shooter}));
    // driver_back.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0); }, {&m_shooter}));

    operator_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(0.8); }, {&m_intake}));
    operator_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); }, {&m_intake}));
    operator_rightBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(-0.8); }, {&m_intake}));
    operator_rightBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); }, {&m_intake}));
    
    operator_y.WhenPressed(frc2::InstantCommand([&] { m_muncher.SetMunchPower(1); }, {&m_muncher}));
    operator_y.WhenPressed(frc2::InstantCommand([&] { m_muncher.SetMunchPower(0); }, {&m_muncher}));

    

    
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    m_drivetrain.ResetOdometry(frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)));
    m_drivetrain.ResetEncoders();
    m_drivetrain.ResetIMU();
    /*
    //need to add in chooser with strings of auto names
    selectedAuto = "EightBallAuto";

    selectedPath = m_trajectories.GetAutosMap().at(selectedAuto);

    pathLength = selectedPath.size();

    for (int i = 0; i < pathLength; i++) {
        if (selectedPath[i].action == ValorTrajectory::Path) {
            frc2::RamseteCommand ramseteCommand(selectedPath[i].trajectory,
                                                [&] () { return m_drivetrain.GetPose(); },
                                                frc::RamseteController(RamseteConstants::kRamseteB, RamseteConstants::kRamseteZeta),
                                                m_drivetrain.kSimpleMotorFeedforward,
                                                m_drivetrain.kDriveKinematics,
                                                [&] { return m_drivetrain.GetWheelSpeeds(); },
                                                frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
                                                frc2::PIDController(RamseteConstants::kPDriveVel, 0, 0),
                                                [&] (auto left, auto right) { m_drivetrain.TankDriveVolts(left, right); },
                                                {&Drivetrain::GetInstance()});

            // sequential command group add ramsete command
            autoCommandGroup->AddCommands(std::move(ramseteCommand));
        }
        else {
            // sequential command group add command for shoot
            autoCommandGroup->AddCommands(frc2::InstantCommand([&] {m_intake.SetIntakePower(1); }, {&m_intake} ));
        }
    }

    */

   return &m_tenBallAuto;

}
