#include <iostream> 
#include <unordered_map>
#include <vector>
#include <frc/geometry/Translation2d.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>

#include "Constants.h"

struct ValorTrajectory {
    frc::Trajectory trajectory;
    enum Action { Path, Shoot } action;
};

// breaking down of individual trajectories?
// trajectory config?