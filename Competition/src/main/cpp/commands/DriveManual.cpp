#include "commands/DriveManual.h"

DriveManual::DriveManual(Drivetrain* drivetrain, std::function<double()> straightValue, std::function<double()> turnValue) 
            : m_drivetrain{drivetrain}, m_straightValue{straightValue}, m_turnValue{turnValue} {
    AddRequirements({drivetrain});

}

void DriveManual::Execute() {
    //m_drivetrain->ArcadeDrive(m_leftValue(), m_rightValue());
    m_drivetrain->RocketLeagueDrive(m_straightValue(), m_turnValue());
}

bool DriveManual::IsFinished() {
    return false;
}