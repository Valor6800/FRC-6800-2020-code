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

#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Hopper.h"
#include "subsystems/Arm.h"
#include "subsystems/Lift.h"
#include "subsystems/Muncher.h"

#include "commands/Auto/HomeTrenchAuto.h"

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
   frc::XboxController m_GamepadDriver{OIConstants::GAMEPAD_BASE_LOCATION};
   frc::XboxController m_GamepadOperator{OIConstants::GAMEPAD_OPERATOR_LOCATION};
 
   Drivetrain& m_drivetrain = Drivetrain::GetInstance();
   Intake& m_intake = Intake::GetInstance();
   Hopper& m_hopper = Hopper::GetInstance();
   Arm& m_arm = Arm::GetInstance();
   Shooter& m_shooter = Shooter::GetInstance();
   Lift& m_lift = Lift::GetInstance();
   Muncher& m_muncher = Muncher::GetInstance();

   Trajectories m_trajectories;

   frc::SendableChooser<frc2::Command*> chooser; // Give options for autonomous actions
   std::string selectedAuto;
   std::vector<ValorTrajectory> selectedPath;

   frc2::SequentialCommandGroup* autoCommandGroup;
   
   void ConfigureButtonBindings();
};

#endif