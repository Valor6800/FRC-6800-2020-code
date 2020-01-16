#include "subsystems/IT.h"



IT::IT() : intake{VICTOR_ID_INTAKE}, throatA{VICTOR_ID_THROATA}, throatB{VICTOR_ID_THROATB} {
}

void IT::Periodic() {
  
}

void IT::SetIntakePower(double power) {
    intake.Set(power);
}
void IT::SetThroatPower(double power) {
    throatA.Set(power);
    throatB.Set(power);
}