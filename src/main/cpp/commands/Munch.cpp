#include "commands/Munch.h"

Munch::Munch(Muncher* muncher, std::function<bool()> pressed) 
            : m_muncher{muncher}, m_pressed{pressed} {
    AddRequirements({muncher});

}

void Munch::Execute() {
    if (m_pressed()) {
        m_muncher->SetMunchPower(1);
    }
    else {
        m_muncher->SetMunchPower(0);
    }
}

bool Munch::IsFinished() {
    return false;
}