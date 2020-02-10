#include "commands/Climb.h"

Climb::Climb(Lift& lift, std::function<double()> value) : m_value{value} {
    AddRequirements({&lift});

}

void Climb::Execute() {
    if (m_value() > DEADBAND) {
        Lift::GetInstance().SetLiftPower(1);
    }
    else {
        Lift::GetInstance().SetLiftPower(0);
    }
}

bool Climb::IsFinished() {
    return false;
}