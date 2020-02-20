#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEFT, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_RIGHT, rev::CANSparkMax::MotorType::kBrushless}, 
                     hoodServoLeft{ShooterConstants::PWM_ID_HOOD_LEFT},
                     hoodServoRight{ShooterConstants::PWM_ID_HOOD_RIGHT} {
    InitShooter();
}

Shooter& Shooter::GetInstance()
{
    static Shooter instance;
    return instance;
}

void Shooter::InitShooter() {
    shootMtrLeft.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    shootMtrRight.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    shootMtrLeft.SetInverted(true);
    shootMtrRight.SetInverted(false);
}

void Shooter::Periodic() {
  
}

void Shooter::SetShooterPower(double power) {
    shootMtrs.Set(power); 
}