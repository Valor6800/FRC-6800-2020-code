#pragma once

#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/StartEndCommand.h>
#include <frc2/command/RunCommand.h>
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

#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Hopper.h"
#include "subsystems/Arm.h"
#include "subsystems/Lift.h"
#include "subsystems/Muncher.h"

#include "commands/Auto/HomeTrenchAuto.h"
#include "commands/Auto/TenBallAuto.h"
#include "commands/Auto/SixBallAuto.h"

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
   frc::XboxController m_GamepadDriver{OIConstants::GAMEPAD_BASE_LOCATION};
   frc::XboxController m_GamepadOperator{OIConstants::GAMEPAD_OPERATOR_LOCATION};
 
   Drivetrain& m_drivetrain = Drivetrain::GetInstance();
   Intake& m_intake = Intake::GetInstance();
   Hopper& m_hopper = Hopper::GetInstance();
   Arm& m_arm = Arm::GetInstance();
   Shooter& m_shooter = Shooter::GetInstance();
   Lift& m_lift = Lift::GetInstance();
   Muncher& m_muncher = Muncher::GetInstance();

   //HomeTrenchAuto m_homeTrenchAuto;
   TenBallAuto m_tenBallAuto;
   //SixBallAuto m_sixBallAuto;

   Trajectories m_trajectories;

   frc::SendableChooser<frc2::Command*> chooser; // Give options for autonomous actions
   std::string selectedAuto;
   nt::NetworkTableEntry shooterPower;

   double shooterPow;

   std::vector<ValorTrajectory> selectedPath;
   int pathLength;
   
   
   void ConfigureButtonBindings();
};

#endif