#include "commands/SpinIntake.h"
#include "../../include/RobotContainer.h"

SpinIntake::SpinIntake(Intake& intake, std::function<double()> rightTrigger, std::function<bool()> rightBumper) : m_rightTrig{rightTrigger},
                                                                                                  m_rightBumper{rightBumper} {
    AddRequirements({&intake});
}
void SpinIntake::Initialize() {
    
}
void SpinIntake::Execute() {
    if (abs(m_rightTrig()) > .05 && !m_rightBumper()) {
        Intake::GetInstance().SetIntakePower(m_rightTrig());
    } else if (m_rightBumper()) {
        Intake::GetInstance().SetIntakePower(-0.5);
    } else {
        Intake::GetInstance().SetIntakePower(0);
    }
}
bool SpinIntake::IsFinished() {
    return false;
}