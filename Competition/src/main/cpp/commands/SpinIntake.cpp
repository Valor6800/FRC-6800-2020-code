#include "commands/SpinIntake.h"

SpinIntake::SpinIntake(Intake* intake, std::function<double()> rightTrigger, std::function<bool()> rightBumper) : m_intake{intake},
                                                                                                    m_rightTrig{rightTrigger},
                                                                                                    m_rightBumper{rightBumper} {
    AddRequirements({intake});
}
void SpinIntake::Initialize() {
    
}
void SpinIntake::Execute() {
    if (abs(m_rightTrig()) > .05 && !m_rightBumper()) {
        m_intake->SetIntakePower(m_rightTrig());
    } else if (m_rightBumper()) {
        m_intake->SetIntakePower(-0.5);
    } else {
        m_intake->SetIntakePower(0);
    }
}
bool SpinIntake::IsFinished() {
    return false;
}