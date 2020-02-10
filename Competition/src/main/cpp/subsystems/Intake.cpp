#include "subsystems/Intake.h"



Intake::Intake() : intakeMtr{IntakeConstants::VICTOR_ID_INTAKE} {
    intakeMtr.SetInverted(!intakeMtr.GetInverted());
}

Intake& Intake::GetInstance()
{
    static Intake instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Intake::Periodic() {
  
}

void Intake::SetIntakePower(double power) {
    intakeMtr.Set(power);
}