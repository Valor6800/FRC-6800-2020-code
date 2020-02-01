#include "commands/ShootStop.h"

ShootStop::ShootStop(Shooter* shooter) : m_shooter{shooter} {
    AddRequirements({shooter});
}

void ShootStop::Initialize() {
    m_shooter->SetShooterPower(0);
}
bool ShootStop::IsFinished() {
   return true;
}
// void Shoot::SetStop() {
//     m_stop = true;
// }