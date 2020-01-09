#include "subsystems/IT.h"

IT::IT() {
  
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