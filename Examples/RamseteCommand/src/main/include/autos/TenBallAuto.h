
#include "Trajectories.h"
#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

#include <frc/controller/PIDController.h>
#include <frc/controller/RamseteController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <units/units.h>
#include <wpi/math>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <vector>
#include <frc2/command/CommandHelper.h>
class TenBallAuto : frc2::SequentialCommandGroup  {
public:
    TenBallAuto();
    frc2::Command* GetTenBallAutoCommand();
private:
    DriveSubsystem m_driveT;
};