// #include "commands/SpinIT.h"
// #include "../../include/RobotContainer.h"

// SpinIT::SpinIT(IT* it, double leftTrigger, double rightTrigger) : m_it{it} {
//     m_it = it;
//     leftTrig = leftTrigger;
//     rightTrig = rightTrigger;
// }
// void SpinIT::Initialize() {

// }
// void SpinIT::Execute() {
//     if (abs(leftTrig) > .05) {
//         m_it.SetIntakePower(leftTrig);
//         m_it.SetThroatPower(leftTrig);
//     } else if (abs(rightTrig) > .05) {
//         m_it.SetIntakePower(rightTrig);
//     } else {
//         m_it.SetIntakePower(0);
//         m_it.SetThroatPower(0);
//     }
// }
// bool SpinIT::IsFinished() {
//     return false;
// }
// void SpinIT::End() {
//     m_it.SetIntakePower(0);
//     m_it.SetThroatPower(0);
// }
// void SpinIT::Interrupted() {
    
// }