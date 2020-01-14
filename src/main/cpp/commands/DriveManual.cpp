#include "commands/DriveManual.h"

DriveManual::DriveManual(Drivetrain* drivetrain, std::function<double()> leftValue, std::function<double()> rightValue) 
            : m_drivetrain{drivetrain}, m_leftValue{leftValue}, m_rightValue{rightValue} {
    AddRequirements({drivetrain});

}

void DriveManual::Execute() {
    m_drivetrain->Move(m_leftValue(), m_rightValue());
}

bool DriveManual::IsFinished() {
    return false;
}

