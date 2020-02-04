#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>

#include <frc/controller/PIDController.h>
#include <frc2/command/RamseteCommand.h>
#include <frc/controller/RamseteController.h>

#include "subsystems/Drivetrain.h"

#include "Constants.h"

class InitHomeTrench : public frc2::CommandHelper<frc2::CommandBase, InitHomeTrench> {
 public:
    InitHomeTrench(Drivetrain* drivetrain);
    
    //void Initialize() override;

    void Execute() override;

 private:
    frc::DifferentialDriveVoltageConstraint m_autoVoltageConstraint;
    frc::TrajectoryConfig m_config;
    frc::DifferentialDriveKinematics m_driveKinematics;

    frc2::RamseteCommand* ramseteCommand;

    Drivetrain* m_drivetrain;

};