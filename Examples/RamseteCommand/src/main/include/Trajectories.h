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

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <units/units.h>
#include <wpi/math>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <vector>
#include <utility>
#include <units/units.h>

#include "Constants.h"
#include "Robot.h"
namespace AutoConstants {
constexpr auto kMaxSpeed = 4.4_mps;//4.2 
constexpr auto kMaxAcceleration = 4_mps_sq;
// Reasonable baseline values for a RAMSETE follower in units of meters and
// seconds
constexpr double kRamseteB = 2;
constexpr double kRamseteZeta = 0.7;
}  // namespace AutoConstants
//relative to wall
constexpr units::length::meter_t  kStartPos = 4.88_m;
constexpr units::length::meter_t  kCenterline = 0.94_m;



//Definsive 2 ball auto
    //start pos allignment:
    //Center line of robot alligned with tip of target triangle (2.44m off wall). 
    //Front bar of robot parallel with initiation line.
    // const std::vector<frc::Translation2d> Auto1Taj1Translations = {frc::Translation2d(2.5_m,0.0_m)};
    // const std::vector<frc::Pose2d> Auto1Traj1Poses = {frc::Pose2d(0_m,0_m,frc::Rotation2d(0_deg)),frc::Pose2d(3.5_m,-2.0_m,frc::Rotation2d(-60_deg))};
    // const std::vector<frc::Pose2d> Auto1Traj2Poses = {Auto1Traj1Poses[1],frc::Pose2d(-1_m,0_m,frc::Rotation2d(0_deg))};

    // //Offensive 5 ball auto
    // //start pos allignment:
    //     //Center line of robot alligned with tip of target triangle (2.44m off wall). 
    //     //Front bar of robot parallel with initiation line.
    // const std::vector<frc::Translation2d> Auto2Taj1Translations = {frc::Translation2d(0.75_m,1.1_m),
    //                                                                 frc::Translation2d(2.2_m,kCenterline)};  //center line needs to be adjusted
    // const std::vector<frc::Pose2d> Auto2Traj1Poses = {frc::Pose2d(0_m,0_m,frc::Rotation2d(63_deg)),frc::Pose2d(6_m,kCenterline,frc::Rotation2d(10_deg))};
    // const std::vector<frc::Pose2d> Auto2Traj2Poses = {Auto2Traj1Poses[1] ,frc::Pose2d(7_m,kCenterline + 0.2_m,frc::Rotation2d(0_deg))};
    // const std::vector<frc::Pose2d> Auto2Traj3Poses = {Auto2Traj2Poses[1],frc::Pose2d(2.2_m,0.75_m,frc::Rotation2d(20_deg))};


//Offensive/Defensive 10 ball auto
    //start pos alignment: Anywhere you want it--thats the way you need it
    //Center line of robot alligned with tip of target triangle (2.44m off wall). 
    //Front bar of robot parallel with initiation line.
    //2 balls at end of trench
    const std::vector<frc::Translation2d> Auto3Taj1Translations = {frc::Translation2d(2.5_m,0.0_m)};
    const std::vector<frc::Pose2d> Auto3Traj1Poses = {frc::Pose2d(0_m,0_m,frc::Rotation2d(0_deg)),frc::Pose2d(3.7_m,(-7.64_m  + kStartPos),frc::Rotation2d(-60_deg))};
        //return
    const std::vector<frc::Pose2d> Auto3Traj2Poses = {Auto3Traj1Poses[1],frc::Pose2d(0_m,(-2.69_m + kStartPos),frc::Rotation2d(0_deg))};
    //Balls on the bar
    const std::vector<frc::Pose2d> Auto3Traj3Poses = {Auto3Traj2Poses[1],frc::Pose2d(3.3_m,(-3.04_m + kStartPos),frc::Rotation2d(-35_deg))};
    //ball pos: 2.9,0.5    3.3,0.7
        //return
    const std::vector<frc::Pose2d> Auto3Traj4Poses = {Auto3Traj3Poses[1],frc::Pose2d(1.5_m,(-kCenterline + kStartPos),frc::Rotation2d(0_deg))};
    //3 Trench balls         x's 23ft 5in(7.134m) 25ft 8in(7.823)        2.44m to wall tip of triangle
    const std::vector<frc::Translation2d> Auto3Traj5Translations = {frc::Translation2d(2.2_m,(-kCenterline + kStartPos))};  //center line needs to be adjusted
    const std::vector<frc::Pose2d> Auto3Traj5Poses = {frc::Pose2d(Auto3Traj4Poses[1]),frc::Pose2d(5_m,(-kCenterline + kStartPos),frc::Rotation2d(0_deg))};
    //ShootSpot
    const std::vector<frc::Pose2d> Auto3Traj6Poses = {Auto3Traj5Poses[1] ,frc::Pose2d(4_m,(-kCenterline + kStartPos -0.2_m),frc::Rotation2d(15_deg))};