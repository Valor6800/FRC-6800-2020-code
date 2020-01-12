#include "commands/DriveManual.h"

DriveManual::DriveManual(Drivetrain* drivetrain, double leftValue, double rightValue) : m_drivetrain{drivetrain} {
    leftVal = leftValue;
    rightVal = rightValue;
}
void DriveManual::Initialize() {

}
void DriveManual::Execute() {
    m_drivetrain->Move(leftVal, rightVal);
}
bool DriveManual::IsFinished() {
    return false;
}
// void DriveManual::End() {
//     m_drivetrain->Stop();
// }
// void DriveManual::Interrupted() {
    
// }

