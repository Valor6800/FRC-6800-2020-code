#include "commands/Shoot.h"

Shoot::Shoot(Shooter* shooter, double value) : m_shooter{shooter}, val{value} {
    AddRequirements({shooter});
}
void Shoot::Execute() {
    // what are shooter controls????????
    //do some math to figure out power and hood
    m_shooter->SetShooterPower(val);
}
bool Shoot::IsFinished() {
    return false;
}