/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc/controller/PIDController.h>
#include <frc/controller/RamseteController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/WaitCommand.h>
#include <frc/Timer.h>

#include "Constants.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drive.ArcadeDrive(
            m_driverController.GetY(frc::GenericHID::kLeftHand),
            m_driverController.GetX(frc::GenericHID::kRightHand));
      },
      {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // While holding the shoulder button, drive at half speed
  frc2::JoystickButton(&m_driverController, 6)
      .WhenPressed(&m_driveHalfSpeed)
      .WhenReleased(&m_driveFullSpeed);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {

    m_drive.ResetImu();
    m_drive.ResetEncoders();
  // Create a voltage constraint to ensure we don't accelerate too fast
  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics, 10_V);

  // Set up config for trajectory
  frc::TrajectoryConfig configF(AutoConstants::kMaxSpeed,
                               AutoConstants::kMaxAcceleration);
  // Add kinematics to ensure max speed is actually obeyed
  configF.SetKinematics(DriveConstants::kDriveKinematics);
  // Apply the voltage constraint
  configF.AddConstraint(autoVoltageConstraint);
  //not reversed
  configF.SetReversed(false);

  // An example trajectory to follow.  All units in meters.
  auto exampleTrajectory1 = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction

        

        AutoConstants::Auto2Traj1Poses[0],

      // Pull Waypoints from Auto1Traj1Translations
      //{frc::Translation2d(5.8_m, 0.9_m),frc::Translation2d(5.8_m, 0.4_m)},
        {AutoConstants::Auto2Taj1Translations},

      // Pull endpoint Pose from Auto1Traj1Poses
        AutoConstants::Auto2Traj1Poses[1],
      // Pass the config
        configF);

      frc::TrajectoryConfig configB(AutoConstants::kMaxSpeed,
                               AutoConstants::kMaxAcceleration);
    // Add kinematics to ensure max speed is actually obeyed
    configB.SetKinematics(DriveConstants::kDriveKinematics);
    // Apply the voltage constraint
    configB.AddConstraint(autoVoltageConstraint);
    //Revese
    configB.SetReversed(true);

    auto exampleTrajectory2 = frc::TrajectoryGenerator::GenerateTrajectory(
     //frc::Pose2d(3.05_m, 2.44_m, frc::Rotation2d(0_deg)),

        AutoConstants::Auto2Traj2Poses[0],
 
      // Pass through these two interior waypoints, making an 's' curve path
      {},
      // End 3 meters straight ahead of where we started, facing forward
        AutoConstants::Auto2Traj2Poses[1],
      // Pass the config
      configB);

  frc2::RamseteCommand ramseteCommand(
      exampleTrajectory1, [this]() { return m_drive.GetPose(); },
      frc::RamseteController(AutoConstants::kRamseteB,
                             AutoConstants::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      [this] { return m_drive.GetWheelSpeeds(); },
      frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
      frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
      [this](auto left, auto right) { m_drive.TankDriveVolts(left, right); },
      {&m_drive});

  frc2::RamseteCommand ramseteCommandP2(
      exampleTrajectory2, [this]() { return m_drive.GetPose(); },
      frc::RamseteController(AutoConstants::kRamseteB,
                             AutoConstants::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      [this] { return m_drive.GetWheelSpeeds(); },
      frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
      frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
      [this](auto left, auto right) { m_drive.TankDriveVolts(left, right); },
      {&m_drive});

 

  frc2::WaitCommand commandIntermission(units::second_t(1));
  // no auto
  return new frc2::SequentialCommandGroup(

      //frc2::InstantCommand([this] { m_timer.Reset(); }, {}),
      //frc2::InstantCommand([this] { m_timer.Start(); }, {}),

      std::move(ramseteCommand),
      frc2::InstantCommand([this] { m_drive.TankDriveVolts(0_V, 0_V); }, {}),

      //frc2::InstantCommand([this] { m_timer.Get(); }, {}),
  
      std::move(ramseteCommandP2),
      frc2::InstantCommand([this] { m_drive.TankDriveVolts(0_V, 0_V); }, {})
    );
}