#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEAD, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_FOLLOW, rev::CANSparkMax::MotorType::kBrushless}, 
                     hood{ShooterConstants::PWM_ID_HOOD} {
    InitShooter(rev::CANSparkMax::IdleMode::kCoast);
    shooterPower = frc::Shuffleboard::GetTab("Configuration").Add("Shooter_Power", 1).WithWidget("Text View").GetEntry();
}

Shooter& Shooter::GetInstance()
{
    static Shooter instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Shooter::Periodic() {
    
    shooterPow = shooterPower.GetDouble(0.25);
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

double Shooter::GetShooterNTPower() {
    return shooterPow;
}