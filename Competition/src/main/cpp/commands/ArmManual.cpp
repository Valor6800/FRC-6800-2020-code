#include "commands/ArmManual.h"

ArmManual::ArmManual(Arm& arm, std::function<double()> value) : m_value{value} {
    AddRequirements({&arm});

}

void ArmManual::Execute() {
    Arm::GetInstance().SetArmPower(m_value());
}

bool ArmManual::IsFinished() {
    return false;
}