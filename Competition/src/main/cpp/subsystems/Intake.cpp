#include "subsystems/Intake.h"

Intake::Intake() : intakeMtr{IntakeConstants::PWM_ID_INTAKE} {
    InitIntake();
}

void Intake::InitIntake() {
    intakeMtr.SetInverted(false);
}

Intake& Intake::GetInstance() {
    static Intake instance;
    return instance;
}

void Intake::Periodic() {
  
}

void Intake::SetIntakePower(double power) {
    intakeMtr.Set(power);
}