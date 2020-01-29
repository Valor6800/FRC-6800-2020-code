#include "commands/SpinHopper.h"
#include "../../include/RobotContainer.h"

SpinHopper::SpinHopper(Hopper* hopper, std::function<double()> leftTrigger, std::function<bool()> leftBumper) : m_hopper{hopper},
                                                                                                     m_leftTrig{leftTrigger}, 
                                                                                                     m_leftBumper{leftBumper} {
    AddRequirements({hopper});
}
void SpinHopper::Initialize() {
    
}
void SpinHopper::Execute() {
    if (abs(m_leftTrig()) > .05 && !m_leftBumper()) {
        m_hopper->SetHopperPower(m_leftTrig());
    } else if (m_leftBumper()) {
        m_hopper->SetHopperPower(-0.5);
    }
    else {
        m_hopper->SetHopperPower(0);
    }
}
bool SpinHopper::IsFinished() {
    return false;
}
