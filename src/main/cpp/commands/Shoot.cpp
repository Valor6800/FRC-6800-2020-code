#include "commands/Shoot.h"
#include "../../include/RobotContainer.h"

Shoot::Shoot(Shooter* shooter) : m_shooter{shooter} {
    Requires(RobotContainer::m_shooter);
}
void Shoot::Initialize() {

}
void Shoot::Execute() {
    // what are shooter controls????????
    // replace val
    double val;
    if (abs(val) > .05) {
        RobotContainer::m_shooter.SetShooterPower(val);
    }  else {
        RobotContainer::m_it.SetShooterPower(0);
    }
}
bool Shoot::IsFinished() {
    
}
void Shoot::End() {
    
}
void Shoot::Interrupted() {
    
}