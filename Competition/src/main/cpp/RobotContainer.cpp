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
    //m_chooser.InitSendable()

    m_chooser.AddOption("TenBallHomeAuto", &m_tenBallHomeAuto);
    m_chooser.AddOption("EightBallHomeAuto", &m_eightBallHomeAuto);
    frc::SmartDashboard::PutData("Auto modes", &m_chooser);

    // intakePower = frc::Shuffleboard::GetTab("Configuration").Add("Intake Power", 1).WithWidget("Text View").GetEntry();
    // hopperPower = frc::Shuffleboard::GetTab("Configuration").Add("Hopper Power", 1).WithWidget("Text View").GetEntry();
    // shooterPower = frc::Shuffleboard::GetTab("Configuration").Add("Shooter Power", 1).WithWidget("Text View").GetEntry();

    m_drivetrain.SetDefaultCommand(DriveManual(m_drivetrain,
        [this] { return m_gamepadDriver.GetTriggerAxis(frc::GenericHID::kRightHand); },
        [this] { return m_gamepadDriver.GetTriggerAxis(frc::GenericHID::kLeftHand); },
        [this] { return m_gamepadDriver.GetX(frc::GenericHID::kLeftHand); },
        [this] { return m_gamepadDriver.GetAButton(); }));

    m_arm.SetDefaultCommand(ArmManual(m_arm, 
        [this] { return m_gamepadOperator.GetY(frc::GenericHID::kLeftHand); }));

    m_arm.SetDefaultCommand(ArmManual(m_arm, 
        [this] { return m_gamepadDriver.GetY(frc::GenericHID::kLeftHand); }));

    // m_lift.SetDefaultCommand(Climb(m_lift, 
    //     [this] { return m_GamepadOperator.GetY(frc::GenericHID::kRightHand); }));

    m_lift.SetDefaultCommand(Climb(m_lift, 
         [this] { return m_gamepadDriver.GetY(frc::GenericHID::kRightHand); }));

    // Configure the button bindings
    ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    // BOOST MULTIPLIER
    driver_rightBumper.WhenPressed(frc2::InstantCommand([&] { m_drivetrain.SetMultiplier(1); }, {&m_drivetrain}));
    driver_rightBumper.WhenReleased(frc2::InstantCommand([&] { m_drivetrain.SetMultiplier(0.5); }, {&m_drivetrain}));

    driver_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(1); m_hopper.SetHopperPower(0.8); }));
    driver_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); m_hopper.SetHopperPower(0); }));

    // INTAKE IN
    operator_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(1); }));
    operator_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); }));

    // INTAKE OUT
    operator_rightBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(-0.75); }, {&m_intake}));
    operator_rightBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); }, {&m_intake}));
    
    // SHOOTER
    operator_start.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0); }, {&m_shooter}));
    operator_back.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0.75); }, {&m_shooter}));

    // operator_start.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0); }, {&m_shooter}).BeforeStarting([&] { m_shooter.RetractHood(); }));
    // operator_back.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0.75); }, {&m_shooter}).BeforeStarting([&] { m_shooter.ExtendHood(); }));

    // CLIMB
    // operator_leftTrigger.ToggleWhenActive(frc2::InstantCommand([&] { m_lift.SetLiftPower(0.25); }).BeforeStarting([&] { m_lift.SetServoUnlock(); }).WithInterrupt([&] { return !m_lift.GetClimbLimitSwitches(); }).AndThen([&] { m_lift.SetServoLock(); }));
    // operator_rightTrigger.WhileActiveContinous(frc2::InstantCommand([&] { m_lift.SetLiftPower(-0.25); }));

    // HOOD
    operator_x.WhenPressed(frc2::InstantCommand([&] { m_shooter.ExtendHood(); }).WithInterrupt([&] { return m_shooter.HoodExtended(); }).AndThen([&] { m_shooter.StopHood(); }));
    operator_a.WhenPressed(frc2::InstantCommand([&] { m_shooter.RetractHood(); }).WithInterrupt([&] { return m_shooter.HoodRetracted(); }).AndThen([&] { m_shooter.StopHood(); }));

    // driver_b.WhenPressed(frc2::InstantCommand([&] { m_arm.SetGoal(90_deg); }));

    // MUNCHER
    // operator_y.WhenPressed(frc2::InstantCommand([&] { m_muncher.SetMunchPower(0.25); }));
    // operator_y.WhenPressed(frc2::InstantCommand([&] { m_muncher.SetMunchPower(0); }));

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

    // intakePow = intakePower.GetDouble(0.25);
    // hopperPow = hopperPower.GetDouble(0.25);
    // shooterPow = shooterPower.GetDouble(0.25);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    m_drivetrain.ResetOdometry(frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)));
    m_drivetrain.ResetEncoders();
    m_drivetrain.ResetIMU();
    
    //need to add in chooser with strings of auto names
    /*
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

   return m_chooser.GetSelected();
}
