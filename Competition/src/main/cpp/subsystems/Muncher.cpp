#include "subsystems/Muncher.h"

Muncher::Muncher() : muncherMtr{MuncherConstants::VICTOR_ID_MUNCHER} {

}

void Muncher::Periodic() {
  
}

void Muncher::SetMunchPower(double power) {
    muncherMtr.Set(power);
}