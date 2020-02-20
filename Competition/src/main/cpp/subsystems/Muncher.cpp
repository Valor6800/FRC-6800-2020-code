#include "subsystems/Muncher.h"

Muncher::Muncher() : muncherMtr{MuncherConstants::PWM_ID_MUNCHER} {
    InitMuncher();
}

Muncher& Muncher::GetInstance() {
    static Muncher instance;
    return instance;
}

void Muncher::InitMuncher() {
    muncherMtr.SetInverted(false);
}

void Muncher::Periodic() {
  
}

void Muncher::SetMunchPower(double power) {
    muncherMtr.Set(power);
}