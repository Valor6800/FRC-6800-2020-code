#include "commands/Climb.h"

Climb::Climb(Lift* lift, std::function<double()> value) 
            : m_lift{lift}, m_value{value} {
    AddRequirements({lift});

}

void Climb::Execute() {
    if (m_value() > DEADBAND) {
        m_lift->SetLiftPower(1);
    }
    else {
        m_lift->SetLiftPower(0);
    }
}

bool Climb::IsFinished() {
    return false;
}