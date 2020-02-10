#include "commands/Munch.h"

Munch::Munch(Muncher& muncher, std::function<bool()> pressed) : m_pressed{pressed} {
    AddRequirements({&muncher});

}

void Munch::Execute() {
    if (m_pressed()) {
        Muncher::GetInstance().SetMunchPower(1);
    }
    else {
        Muncher::GetInstance().SetMunchPower(0);
    }
}

bool Munch::IsFinished() {
    return false;
}