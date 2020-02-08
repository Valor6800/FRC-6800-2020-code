#include "Constants.h"

Constants::Constants() {
    kTrajectoryConfig.SetKinematics(RamseteConstants::kDriveKinematics);
    kTrajectoryConfig.AddConstraint(RamseteConstants::kDifferentialDriveVoltageConstraint);
}