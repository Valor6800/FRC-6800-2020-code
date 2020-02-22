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

    intakePower = frc::Shuffleboard::GetTab("Configuration").Add("Intake Power", 1).WithWidget("Text View").GetEntry();
    hopperPower = frc::Shuffleboard::GetTab("Configuration").Add("Hopper Power", 1).WithWidget("Text View").GetEntry();
    shooterPower = frc::Shuffleboard::GetTab("Configuration").Add("Shooter Power", 1).WithWidget("Text View").GetEntry();

    m_drivetrain.SetDefaultCommand(DriveManual(m_drivetrain,
        [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kRightHand); },
        [this] { return m_GamepadDriver.GetTriggerAxis(frc::GenericHID::kLeftHand); },
        [this] { return m_GamepadDriver.GetX(frc::GenericHID::kLeftHand); },
        [this] { return m_GamepadDriver.GetBumper(frc::GenericHID::kLeftHand); }));

    // m_arm.SetDefaultCommand(ArmManual(m_arm, 
    //     [this] { return m_GamepadOperator.GetY(frc::GenericHID::kLeftHand); }));

    m_arm.SetDefaultCommand(ArmManual(m_arm, 
        [this] { return m_GamepadDriver.GetY(frc::GenericHID::kLeftHand); }));

    // m_lift.SetDefaultCommand(Climb(m_lift, 
    //     [this] { return m_GamepadOperator.GetY(frc::GenericHID::kRightHand); }));

    m_lift.SetDefaultCommand(Climb(m_lift, 
         [this] { return m_GamepadDriver.GetY(frc::GenericHID::kRightHand); }));

    // Configure the button bindings
    ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton driver_a{&m_GamepadDriver, OIConstants::BUTTON_A};
    frc2::JoystickButton driver_b{&m_GamepadDriver, OIConstants::BUTTON_B};
    frc2::JoystickButton driver_x{&m_GamepadDriver, OIConstants::BUTTON_X};
    frc2::JoystickButton driver_y{&m_GamepadDriver, OIConstants::BUTTON_Y};
    frc2::JoystickButton driver_leftBumper{&m_GamepadDriver, OIConstants::LEFT_BUMPER};
    frc2::JoystickButton driver_rightBumper{&m_GamepadDriver, OIConstants::RIGHT_BUMPER};
    frc2::JoystickButton driver_start{&m_GamepadDriver, OIConstants::BUTTON_START};
    frc2::JoystickButton driver_back{&m_GamepadDriver, OIConstants::BUTTON_BACK};

    frc2::JoystickButton operator_a{&m_GamepadOperator, OIConstants::BUTTON_A};
    frc2::JoystickButton operator_b{&m_GamepadOperator, OIConstants::BUTTON_B};
    frc2::JoystickButton operator_x{&m_GamepadOperator, OIConstants::BUTTON_X};
    frc2::JoystickButton operator_y{&m_GamepadOperator, OIConstants::BUTTON_Y};
    frc2::JoystickButton operator_leftBumper{&m_GamepadOperator, OIConstants::LEFT_BUMPER};
    frc2::JoystickButton operator_rightBumper{&m_GamepadOperator, OIConstants::RIGHT_BUMPER};
    frc2::JoystickButton operator_start{&m_GamepadOperator, OIConstants::BUTTON_START};
    frc2::JoystickButton operator_back{&m_GamepadOperator, OIConstants::BUTTON_BACK};


    // INTAKE/HOPPER IN
    // 0.75 intake
    // 0.8 hopper
    driver_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(intakePow); m_hopper.SetHopperPower(hopperPow); }));
    driver_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); m_hopper.SetHopperPower(0); }));

    // BOOST MULTIPLIER
    driver_rightBumper.WhenPressed(frc2::InstantCommand([&] { m_drivetrain.SetMultiplier(1); }, {&m_drivetrain}));
    driver_rightBumper.WhenReleased(frc2::InstantCommand([&] { m_drivetrain.SetMultiplier(0.5); }, {&m_drivetrain}));

    // SHOOTER
    // 0.75
    driver_start.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0); }, {&m_shooter}));
    driver_back.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(shooterPow); }, {&m_shooter}));

    // driver_x.WhenPressed(frc2::InstantCommand([&] { m_arm.SetGoal(90_deg); }, {&m_arm}));
    // driver_y.WhenPressed(frc2::InstantCommand([&] { m_arm.SetGoal(ArmConstants::kArmOffset); }, {&m_arm}));


    // MUNCHER
    // operator_y.WhenPressed(frc2::InstantCommand([&] { m_muncher.SetMunchPower(0.25); }, {&m_muncher}));
    // operator_y.WhenPressed(frc2::InstantCommand([&] { m_muncher.SetMunchPower(0); }, {&m_muncher}));

    // INTAKE/HOPPER IN
    // operator_leftBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(0.75); m_hopper.SetHopperPower(0.8); }));
    // operator_leftBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); m_hopper.SetHopperPower(0); }));

    // INTAKE OUT
    // operator_rightBumper.WhenPressed(frc2::InstantCommand([&] { m_intake.SetIntakePower(-0.75); }, {&m_intake}));
    // operator_rightBumper.WhenReleased(frc2::InstantCommand([&] { m_intake.SetIntakePower(0); }, {&m_intake}));
    
    // SHOOTER
    // operator_start.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(1); }, {&m_shooter}));
    // operator_back.WhenPressed(frc2::InstantCommand([&] { m_shooter.SetShooterPower(0); }, {&m_shooter}));


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

    intakePow = intakePower.GetDouble(0.25);
    hopperPow = hopperPower.GetDouble(0.25);
    shooterPow = shooterPower.GetDouble(0.25);
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
