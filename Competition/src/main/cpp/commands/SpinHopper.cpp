#include "commands/SpinHopper.h"
#include "../../include/RobotContainer.h"

SpinHopper::SpinHopper(Hopper& hopper, std::function<double()> leftTrigger, std::function<bool()> leftBumper) : m_leftTrig{leftTrigger}, m_leftBumper{leftBumper} {
    AddRequirements({&hopper});
}
void SpinHopper::Initialize() {
    
}

void SpinHopper::Execute() {
    if (abs(m_leftTrig()) > .05 && !m_leftBumper()) {
        Hopper::GetInstance().SetHopperPower(m_leftTrig());
    } else if (m_leftBumper()) {
        Hopper::GetInstance().SetHopperPower(-0.5);
    }
    else {
        Hopper::GetInstance().SetHopperPower(0);
    }
}

bool SpinHopper::IsFinished() {
    return false;
}
