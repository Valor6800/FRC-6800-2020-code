#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEAD, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_FOLLOW, rev::CANSparkMax::MotorType::kBrushless}, 
                     hoodServoLeft{ShooterConstants::PWM_ID_HOOD_LEFT},
                     hoodServoRight{ShooterConstants::PWM_ID_HOOD_RIGHT},
                     hoodPotentiometer{ShooterConstants::ID_HOOD_POTENTIOMETER} {
    InitShooter(rev::CANSparkMax::IdleMode::kCoast);
}

Shooter& Shooter::GetInstance()
{
    static Shooter instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Shooter::Periodic() {
  frc::SmartDashboard::PutNumber("hood potentiometer", hoodPotentiometer.Get());
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

void Shooter::ExtendHood() {
    hoodServoLeft.SetRaw(1899);
    hoodServoRight.SetRaw(0);
}

void Shooter::RetractHood() {
    hoodServoLeft.SetRaw(0);
    hoodServoRight.SetRaw(1899);
}

void Shooter::StopHood() {
    hoodServoLeft.SetRaw(999);
    hoodServoRight.SetRaw(999);
}