#include "subsystems/Throat.h"



Throat::Throat() : throatMtrA{VICTOR_ID_THROATA}/*, throatMtrB{VICTOR_ID_THROATB} */{
}

void Throat::Periodic() {
  
}

void Throat::SetThroatPower(double power) {
    throatMtrA.Set(power);
    //throatMtrB.Set(power);
}