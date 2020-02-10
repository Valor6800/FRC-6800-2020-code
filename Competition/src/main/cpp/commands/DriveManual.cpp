#include "commands/DriveManual.h"

DriveManual::DriveManual(Drivetrain& drivetrain, std::function<double()> straightValue, std::function<double()> reverseValue, std::function<double()> turnValue, std::function<bool()> limelightInput) 
            : m_straightValue{straightValue}, m_reverseValue{reverseValue}, m_turnValue{turnValue}, m_limelightInput{limelightInput} {
    AddRequirements({&drivetrain});

}

void DriveManual::Execute() {
    //m_drivetrain->ArcadeDrive(m_leftValue(), m_rightValue());
    Drivetrain::GetInstance().RocketLeagueDrive(m_straightValue(), m_reverseValue(), m_turnValue(), m_limelightInput());
}

bool DriveManual::IsFinished() {
    return false;
}