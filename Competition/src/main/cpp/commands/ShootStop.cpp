#include "commands/ShootStop.h"

ShootStop::ShootStop(Shooter* shooter) : m_shooter{shooter} {
    AddRequirements({shooter});
}

void ShootStop::Initialize() {
    // what are shooter controls????????
    //do some math to figure out power and hood
    m_shooter->SetShooterPower(0);
}
bool ShootStop::IsFinished() {
   return true;
}
// void Shoot::SetStop() {
//     m_stop = true;
// }