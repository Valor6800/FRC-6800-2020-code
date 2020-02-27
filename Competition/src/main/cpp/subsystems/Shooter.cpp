#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEFT, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_RIGHT, rev::CANSparkMax::MotorType::kBrushless}, 
                     hoodServoLeft{ShooterConstants::PWM_ID_HOOD_LEFT},
                     hoodServoRight{ShooterConstants::PWM_ID_HOOD_RIGHT},
                     hoodPotentiometerLeft{ShooterConstants::ID_HOOD_POTENTIOMETER_LEFT},
                     hoodPotentiometerRight{ShooterConstants::ID_HOOD_POTENTIOMETER_RIGHT} {
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
    // m_shootMtrLeftPID.SetReference(power * kMaxRPM, rev::ControlType::kVelocity);
    // m_shootMtrRightPID.SetReference(power * kMaxRPM, rev::ControlType::kVelocity);

    shootMtrLeft.Set(power);
    shootMtrRight.Set(power);
}

void Shooter::ExtendHood() {
    hoodServoLeft.SetRaw(ShooterConstants::SERVO_CLOCKWISE);
    hoodServoRight.SetRaw(ShooterConstants::SERVO_COUNTER_CLOCKWISE);
}

void Shooter::RetractHood() {
    hoodServoLeft.SetRaw(ShooterConstants::SERVO_COUNTER_CLOCKWISE);
    hoodServoRight.SetRaw(ShooterConstants::SERVO_CLOCKWISE);
}

double Shooter::GetPotentiometerAvg() {
    return (std::abs(hoodPotentiometerLeft.Get()) + std::abs(hoodPotentiometerRight.Get())) / 2.0;
}

bool Shooter::HoodExtended() {
    return GetPotentiometerAvg() >= ShooterConstants::POTENTIOMETER_HOOD_EXTENDED;
}

bool Shooter::HoodRetracted() {
    return GetPotentiometerAvg() <= ShooterConstants::POTENTIOMETER_HOOD_RETRACTED;
}