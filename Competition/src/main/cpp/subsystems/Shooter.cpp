#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEFT, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_RIGHT, rev::CANSparkMax::MotorType::kBrushless}, 
                     hoodServoLeft{ShooterConstants::PWM_ID_HOOD_LEFT},
                     hoodServoRight{ShooterConstants::PWM_ID_HOOD_RIGHT} {
    InitShooter();

}

Shooter& Shooter::GetInstance() {
    static Shooter instance;
    return instance;
}

void Shooter::InitShooter() {
    shootMtrLeft.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    shootMtrRight.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    m_shootMtrLeftPID.SetP(kProp);
    m_shootMtrLeftPID.SetI(kInte);
    m_shootMtrLeftPID.SetD(kDeriv);
    m_shootMtrLeftPID.SetIZone(kIzone);
    m_shootMtrLeftPID.SetFF(kFeedForward);
    m_shootMtrLeftPID.SetOutputRange(miOutput, maOutput);

    m_shootMtrRightPID.SetP(kProp);
    m_shootMtrRightPID.SetI(kInte);
    m_shootMtrRightPID.SetD(kDeriv);
    m_shootMtrRightPID.SetIZone(kIzone);
    m_shootMtrRightPID.SetFF(kFeedForward);
    m_shootMtrRightPID.SetOutputRange(miOutput, maOutput);

    shootMtrLeft.SetInverted(true);
    shootMtrRight.SetInverted(false);
}

void Shooter::Periodic() {
  
}

void Shooter::SetShooterPower(double power) {
    m_shootMtrLeftPID.SetReference(power * kMaxRPM, rev::ControlType::kVelocity);
    m_shootMtrRightPID.SetReference(power * kMaxRPM, rev::ControlType::kVelocity);
}