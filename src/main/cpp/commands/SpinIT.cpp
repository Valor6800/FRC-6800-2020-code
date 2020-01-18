#include "commands/SpinIT.h"
#include "../../include/RobotContainer.h"

SpinIT::SpinIT(IT* it, std::function<double()> rightTrigger) : m_it{it}, rightTrig{rightTrigger} {
    AddRequirements({it});
}
void SpinIT::Initialize() {
    
}
void SpinIT::Execute() {
    if (abs(rightTrig()) > .05) {
        m_it->SetIntakePower(rightTrig());
        m_it->SetThroatPower(rightTrig());
    } else {
        m_it->SetIntakePower(0);
        m_it->SetThroatPower(0);
    }
}
bool SpinIT::IsFinished() {
    return false;
}
