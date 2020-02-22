#include "subsystems/Intake.h"

Intake::Intake() : intakeMtr{IntakeConstants::PWM_ID_INTAKE} {
    InitIntake();
}

Intake& Intake::GetInstance() {
    static Intake instance;
    return instance;
}

void Intake::InitIntake() {
    intakeMtr.SetInverted(false);
}

void Intake::Periodic() {
  
}

void Intake::SetIntakePower(double power) {
    intakeMtr.Set(power);
}