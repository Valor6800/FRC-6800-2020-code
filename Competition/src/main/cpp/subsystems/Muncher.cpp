#include "subsystems/Muncher.h"

Muncher::Muncher() : leftMuncherMtr{VICTOR_ID_LEFT_MUNCHER}, rightMuncherMtr{VICTOR_ID_RIGHT_MUNCHER} {

}

void Muncher::Periodic() {
  
}

void Muncher::SetMunchPower(double power) {
    muncherMtrs.Set(power);
}