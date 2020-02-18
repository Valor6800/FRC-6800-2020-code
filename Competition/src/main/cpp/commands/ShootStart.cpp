#include "commands/ShootStart.h"

ShootStart::ShootStart(Shooter& shooter) {
    AddRequirements({&shooter});
}
void ShootStart::Execute() {
    // what are shooter controls????????
    //do some math to figure out power and hood
    Shooter::GetInstance().SetShooterPower(0.85);
}
