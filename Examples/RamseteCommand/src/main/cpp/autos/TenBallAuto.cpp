#include "autos/TenBallAuto.h"

TenBallAuto::TenBallAuto(){
} 

frc2::Command* TenBallAuto::GetTenBallAutoCommand() {
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

        

        Auto3Traj1Poses[0],

    // Pull Waypoints from Auto1Traj1Translations
    //{frc::Translation2d(5.8_m, 0.9_m),frc::Translation2d(5.8_m, 0.4_m)},
        {/*Auto3Taj1Translations[0]*/},

    // Pull endpoint Pose from Auto1Traj1Poses
        Auto3Traj1Poses[1],
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

        Auto3Traj2Poses[0],

    // Pass through these two interior waypoints, making an 's' curve path
    {},
    // End 3 meters straight ahead of where we started, facing forward
        Auto3Traj2Poses[1],
    // Pass the config
    configB);



    auto exampleTrajectory3 = frc::TrajectoryGenerator::GenerateTrajectory(
    // Start at the origin facing the +X direction

        

        Auto3Traj3Poses[0],

    // Pull Waypoints from Auto1Traj1Translations
    //{frc::Translation2d(5.8_m, 0.9_m),frc::Translation2d(5.8_m, 0.4_m)},
        {},

    // Pull endpoint Pose from Auto1Traj1Poses
        Auto3Traj3Poses[1],
    // Pass the config
        configF);


    auto exampleTrajectory4 = frc::TrajectoryGenerator::GenerateTrajectory(
    //frc::Pose2d(3.05_m, 2.44_m, frc::Rotation2d(0_deg)),

        Auto3Traj4Poses[0],

    // Pass through these two interior waypoints, making an 's' curve path
    {},
    // End 3 meters straight ahead of where we started, facing forward
        Auto3Traj4Poses[1],
    // Pass the config
    configB);

    auto exampleTrajectory6 = frc::TrajectoryGenerator::GenerateTrajectory(
    //frc::Pose2d(3.05_m, 2.44_m, frc::Rotation2d(0_deg)),

        Auto3Traj6Poses[0],

    // Pass through these two interior waypoints, making an 's' curve path
    {},
    // End 3 meters straight ahead of where we started, facing forward
        Auto3Traj6Poses[1],
    // Pass the config
    configB);

    auto exampleTrajectory5 = frc::TrajectoryGenerator::GenerateTrajectory(
    // Start at the origin facing the +X direction

        

        Auto3Traj5Poses[0],

    // Pull Waypoints from Auto1Traj1Translations
    //{frc::Translation2d(5.8_m, 0.9_m),frc::Translation2d(5.8_m, 0.4_m)},
        {Auto3Traj5Translations[0]},

    // Pull endpoint Pose from Auto1Traj1Poses
        Auto3Traj5Poses[1],
    // Pass the config
        configF);

    frc2::RamseteCommand ramseteCommand(
    exampleTrajectory1, [this](){ return m_driveT.GetPose(); },
    frc::RamseteController(AutoConstants::kRamseteB,
                            AutoConstants::kRamseteZeta),
    frc::SimpleMotorFeedforward<units::meters>(
        DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
    DriveConstants::kDriveKinematics,
    [this](){ return m_driveT.GetWheelSpeeds(); },
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    [this](auto left, auto right) { m_driveT.TankDriveVolts(left, right); },
    {&m_driveT});

    frc2::RamseteCommand ramseteCommandP2(
    exampleTrajectory2, [this](){ return m_driveT.GetPose(); },
    frc::RamseteController(AutoConstants::kRamseteB,
                            AutoConstants::kRamseteZeta),
    frc::SimpleMotorFeedforward<units::meters>(
        DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
    DriveConstants::kDriveKinematics,
    [this](){ return m_driveT.GetWheelSpeeds(); },
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    [this](auto left, auto right) { m_driveT.TankDriveVolts(left, right); },
    {&m_driveT});



    frc2::RamseteCommand ramseteCommandP3(
    exampleTrajectory3, [this](){ return m_driveT.GetPose(); },
    frc::RamseteController(AutoConstants::kRamseteB,
                            AutoConstants::kRamseteZeta),
    frc::SimpleMotorFeedforward<units::meters>(
        DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
    DriveConstants::kDriveKinematics,
    [this](){ return m_driveT.GetWheelSpeeds(); },
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    [this](auto left, auto right) { m_driveT.TankDriveVolts(left, right); },
    {&m_driveT});

    frc2::RamseteCommand ramseteCommandP4(
    exampleTrajectory4, [this](){ return m_driveT.GetPose(); },
    frc::RamseteController(AutoConstants::kRamseteB,
                            AutoConstants::kRamseteZeta),
    frc::SimpleMotorFeedforward<units::meters>(
        DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
    DriveConstants::kDriveKinematics,
    [this](){ return m_driveT.GetWheelSpeeds(); },
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    [this](auto left, auto right) { m_driveT.TankDriveVolts(left, right); },
    {&m_driveT});

    frc2::RamseteCommand ramseteCommandP5(
    exampleTrajectory5, [this](){ return m_driveT.GetPose(); },
    frc::RamseteController(AutoConstants::kRamseteB,
                            AutoConstants::kRamseteZeta),
    frc::SimpleMotorFeedforward<units::meters>(
        DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
    DriveConstants::kDriveKinematics,
    [this](){ return m_driveT.GetWheelSpeeds(); },
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    [this](auto left, auto right) { m_driveT.TankDriveVolts(left, right); },
    {&m_driveT});

    frc2::RamseteCommand ramseteCommandP6(
    exampleTrajectory6, [this](){ return m_driveT.GetPose(); },
    frc::RamseteController(AutoConstants::kRamseteB,
                            AutoConstants::kRamseteZeta),
    frc::SimpleMotorFeedforward<units::meters>(
        DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
    DriveConstants::kDriveKinematics,
    [this](){ return m_driveT.GetWheelSpeeds(); },
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
    [this](auto left, auto right) { m_driveT.TankDriveVolts(left, right); },
    {&m_driveT});
    

    
    return new SequentialCommandGroup(  
        std::move(ramseteCommand),
        frc2::InstantCommand([this] { m_driveT.TankDriveVolts(0_V, 0_V); }, {}),

        //frc2::InstantCommand([this] { m_timer.Get(); }, {}),
  
        std::move(ramseteCommandP2),
        frc2::InstantCommand([this] { m_driveT.TankDriveVolts(0_V, 0_V);}, {}),

        std::move(ramseteCommandP3),
        frc2::InstantCommand([this] { m_driveT.TankDriveVolts(0_V, 0_V); }, {}),

        //frc2::InstantCommand([this] { m_timer.Get(); }, {}),
  
        std::move(ramseteCommandP4),
        frc2::InstantCommand([this] { m_driveT.TankDriveVolts(0_V, 0_V); }, {}),

        std::move(ramseteCommandP5),
        frc2::InstantCommand([this] { m_driveT.TankDriveVolts(0_V, 0_V); }, {}),

        std::move(ramseteCommandP6),
        frc2::InstantCommand([this] { m_driveT.TankDriveVolts(0_V, 0_V); }, {})
        );
    }