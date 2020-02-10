#include "subsystems/Muncher.h"

Muncher::Muncher() : muncherMtr{MuncherConstants::VICTOR_ID_MUNCHER} {

}

Muncher& Muncher::GetInstance()
{
    static Muncher instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Muncher::Periodic() {
  
}

void Muncher::SetMunchPower(double power) {
    muncherMtr.Set(power);
}