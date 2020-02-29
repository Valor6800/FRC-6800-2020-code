#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEAD, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_FOLLOW, rev::CANSparkMax::MotorType::kBrushless}, 
                     hoodServoLeft{ShooterConstants::PWM_ID_HOOD_LEFT},
                     hoodServoRight{ShooterConstants::PWM_ID_HOOD_RIGHT} {
    InitShooter(rev::CANSparkMax::IdleMode::kCoast);
}

Shooter& Shooter::GetInstance()
{
    static Shooter instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Shooter::Periodic() {
  hoodServoLeft.Set(hoodServoLeft.Get());
  hoodServoRight.Set(hoodServoRight.Get());

  frc::SmartDashboard::PutNumber("Left hood position", hoodServoLeft.Get());
  frc::SmartDashboard::PutNumber("Right hood position", hoodServoRight.Get());
}

void Shooter::InitShooter(rev::CANSparkMax::IdleMode idleMode) {
    shootMtrLeft.SetIdleMode(idleMode);
    shootMtrRight.SetIdleMode(idleMode);

    shootMtrLeft.SetInverted(true);
    shootMtrRight.SetInverted(false);
    

}

void Shooter::SetShooterPower(double power) {
    shootMtrs.Set(power);
    
}