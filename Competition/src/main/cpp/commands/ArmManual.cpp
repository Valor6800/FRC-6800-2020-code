#include "commands/ArmManual.h"

ArmManual::ArmManual(Arm* arm, std::function<double()> value) 
            : m_arm{arm}, m_value{value} {
    AddRequirements({arm});

}

void ArmManual::Execute() {
    m_arm->SetArmPower(m_value());
}

bool ArmManual::IsFinished() {
    return false;
}