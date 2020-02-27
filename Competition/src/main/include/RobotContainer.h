#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/InstantCommand.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/CommandHelper.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "networktables/NetworkTable.h"
#include <frc/livewindow/LiveWindow.h>
#include <frc/AnalogTrigger.h>
#include <frc2/command/button/Trigger.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Hopper.h"
#include "subsystems/Arm.h"
#include "subsystems/Lift.h"
#include "subsystems/Muncher.h"

#include "commands/Auto/TenBallHomeAuto.h"
#include "commands/Auto/EightBallHomeAuto.h"

#include <vector>
#include "ValorTrajectory.h"
#include "Trajectories.h"
#include "Constants.h"

#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

class RobotContainer {
 public:
    RobotContainer();
    frc2::Command* GetAutonomousCommand();

 private:
   frc::XboxController m_gamepadDriver{OIConstants::GAMEPAD_BASE_LOCATION};
   frc::XboxController m_gamepadOperator{OIConstants::GAMEPAD_OPERATOR_LOCATION};

   frc2::JoystickButton driver_a{&m_gamepadDriver, OIConstants::BUTTON_A};
   frc2::JoystickButton driver_b{&m_gamepadDriver, OIConstants::BUTTON_B};
   frc2::JoystickButton driver_x{&m_gamepadDriver, OIConstants::BUTTON_X};
   frc2::JoystickButton driver_y{&m_gamepadDriver, OIConstants::BUTTON_Y};
   frc2::JoystickButton driver_leftBumper{&m_gamepadDriver, OIConstants::LEFT_BUMPER};
   frc2::JoystickButton driver_rightBumper{&m_gamepadDriver, OIConstants::RIGHT_BUMPER};
   frc2::JoystickButton driver_start{&m_gamepadDriver, OIConstants::BUTTON_START};
   frc2::JoystickButton driver_back{&m_gamepadDriver, OIConstants::BUTTON_BACK};

   frc2::JoystickButton operator_a{&m_gamepadOperator, OIConstants::BUTTON_A};
   frc2::JoystickButton operator_b{&m_gamepadOperator, OIConstants::BUTTON_B};
   frc2::JoystickButton operator_x{&m_gamepadOperator, OIConstants::BUTTON_X};
   frc2::JoystickButton operator_y{&m_gamepadOperator, OIConstants::BUTTON_Y};
   frc2::JoystickButton operator_leftBumper{&m_gamepadOperator, OIConstants::LEFT_BUMPER};
   frc2::JoystickButton operator_rightBumper{&m_gamepadOperator, OIConstants::RIGHT_BUMPER};
   frc2::Trigger operator_leftTrigger{[this] { return m_gamepadOperator.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.2; }};
   frc2::Trigger operator_rightTrigger{[this] { return m_gamepadOperator.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.2; }};
   frc2::JoystickButton operator_start{&m_gamepadOperator, OIConstants::BUTTON_START};
   frc2::JoystickButton operator_back{&m_gamepadOperator, OIConstants::BUTTON_BACK};
   
 
   // SUBSYSTEMS
   Drivetrain& m_drivetrain = Drivetrain::GetInstance();
   Intake& m_intake = Intake::GetInstance();
   Hopper& m_hopper = Hopper::GetInstance();
   Arm& m_arm = Arm::GetInstance();
   Shooter& m_shooter = Shooter::GetInstance();
   Lift& m_lift = Lift::GetInstance();
   Muncher& m_muncher = Muncher::GetInstance();


   // AUTO
   EightBallHomeAuto m_eightBallHomeAuto;
   TenBallHomeAuto m_tenBallHomeAuto;

   Trajectories m_trajectories;

   frc::SendableChooser<frc2::Command*> m_chooser;
   std::string selectedAuto;

   std::vector<ValorTrajectory> selectedPath;
   int pathLength;
   
   nt::NetworkTableEntry intakePower;
   nt::NetworkTableEntry hopperPower;
   nt::NetworkTableEntry shooterPower;

   double intakePow;
   double hopperPow;
   double shooterPow;

   void ConfigureButtonBindings();
};

#endif