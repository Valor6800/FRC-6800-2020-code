#include "commands/DriveManual.h"
#include "../../include/RobotContainer.h"

DriveManual::DriveManual(Drivetrain* drivetrain) : m_drivetrain{drivetrain} {
    Requires(RobotContainer::m_Drivetrain);
}
void DriveManual::Initialize() {

}
void DriveManual::Execute() {
    double leftVal = RobotContainer::mGamepadDriver.GetY(frc::GenericHID::JoystickHand::kLeftHand);
    double rightVal = RobotContainer::mGamepadDriver.GetY(frc::GenericHID::JoystickHand::kRightHand);
    RobotContainer::m_Drivetrain->move(leftVal, rightVal);
}
bool DriveManual::IsFinished() {
    
}
void DriveManual::End() {
    
}
void DriveManual::Interrupted() {
    
}

