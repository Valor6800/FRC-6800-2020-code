#include "commands/SpinIT.h"
#include "../../include/RobotContainer.h"

SpinIT::SpinIT(IT* it) : m_it{it} {
    Requires(RobotContainer::m_it);
}
void SpinIT::Initialize() {

}
void SpinIT::Execute() {
    double leftTrig = RobotContainer::mGamepadDriver.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand);
    double rightTrig = RobotContainer::mGamepadDriver.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand);
    if (abs(leftTrig) > .05) {
        RobotContainer::m_it.SetIntakePower(leftTrig);
        RobotContainer::m_it.SetThroatPower(leftTrig);
    } else if (abs(rightTrig) > .05) {
        RobotContainer::m_it.SetIntakePower(rightTrig);
    } else {
        RobotContainer::m_it.SetIntakePower(0);
        RobotContainer::m_it.SetThroatPower(0);
    }
}
bool SpinIT::IsFinished() {
    
}
void SpinIT::End() {
    
}
void SpinIT::Interrupted() {
    
}