#include "commands/ShootStart.h"

ShootStart::ShootStart(Shooter& shooter) {
    AddRequirements({&shooter});
}
void ShootStart::Execute() {
    Shooter::GetInstance().SetShooterPower(0.75);
}
