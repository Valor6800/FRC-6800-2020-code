#include "commands/SpinThroat.h"
#include "../../include/RobotContainer.h"

SpinThroat::SpinThroat(Throat* throat, std::function<double()> leftTrigger, std::function<bool()> leftBumper) : m_throat{throat},
                                                                                                     m_leftTrig{leftTrigger}, 
                                                                                                     m_leftBumper{leftBumper} {
    AddRequirements({throat});
}
void SpinThroat::Initialize() {
    
}
void SpinThroat::Execute() {
    if (abs(m_leftTrig()) > .05 && !m_leftBumper()) {
        m_throat->SetThroatPower(m_leftTrig());
    } else if (m_leftBumper()) {
        m_throat->SetThroatPower(-0.5);
    }
    else {
        m_throat->SetThroatPower(0);
    }
}
bool SpinThroat::IsFinished() {
    return false;
}
