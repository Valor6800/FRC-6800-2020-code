#include "commands/Climb.h"

Climb::Climb(Lift& lift, std::function<double()> value) : m_value{value} {
    AddRequirements({&lift});

}

void Climb::Execute() {
    Lift::GetInstance().LiftDrive(m_value());
}

bool Climb::IsFinished() {
    return false;
}