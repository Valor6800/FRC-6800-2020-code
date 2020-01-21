#include "subsystems/Intake.h"



Intake::Intake() : intakeMtr{VICTOR_ID_INTAKE} {
    intakeMtr.SetInverted(!intakeMtr.GetInverted());
}

void Intake::Periodic() {
  
}

void Intake::SetIntakePower(double power) {
    intakeMtr.Set(power);
}