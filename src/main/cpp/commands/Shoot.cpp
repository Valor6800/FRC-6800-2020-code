#include "commands/Shoot.h"

// Shoot::Shoot(Shooter* shooter, bool stop) : m_shooter{shooter}, m_stop{stop} {
//     AddRequirements({shooter});
// }
Shoot::Shoot(Shooter* shooter) : m_shooter{shooter} {
    AddRequirements({shooter});
}
void Shoot::Execute() {
    // what are shooter controls????????
    //do some math to figure out power and hood
    m_shooter->SetShooterPower(0.85);
}
// bool Shoot::IsFinished() {
//    return m;
//    //return false;
// }
// void Shoot::SetStop() {
//     m_stop = true;
// }
// void Shoot::End() {
    
// }