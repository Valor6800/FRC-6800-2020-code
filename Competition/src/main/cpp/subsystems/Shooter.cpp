#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEAD, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_FOLLOW, rev::CANSparkMax::MotorType::kBrushless}, 
                     hoodServoLeft{9},
                     hoodServoRight{6},
                     hoodPotentiometer{3},
                     deadzone{0.005} {
    InitShooter(rev::CANSparkMax::IdleMode::kCoast);
    shooterPower = frc::Shuffleboard::GetTab("Configuration").Add("Shooter_Power", 1).WithWidget("Text View").GetEntry();
    hoodTarget = hoodPotentiometer.Get();
}

Shooter& Shooter::GetInstance()
{
    static Shooter instance; // Guaranteed to be destroyed. Instantiated on first use.
    return instance;
}

void Shooter::Periodic() {
    shooterPow = shooterPower.GetDouble(0.25);
    frc::SmartDashboard::PutNumber("hood potentiometer", hoodPotentiometer.Get());
    frc::SmartDashboard::PutBoolean("extended", HoodExtended());

    frc::SmartDashboard::PutBoolean("Should stop", (hoodPotentiometer.Get() < hoodTarget + deadzone && hoodPotentiometer.Get() > hoodTarget - deadzone));
    frc::SmartDashboard::PutBoolean("Should extend", extending && hoodPotentiometer.Get() >= hoodTarget);
    frc::SmartDashboard::PutBoolean("Should retract", (!extending && hoodPotentiometer.Get() <= hoodTarget));

    if (hoodPotentiometer.Get() < hoodTarget + deadzone && hoodPotentiometer.Get() > hoodTarget - deadzone) {
        StopHood();
    }
    else if (extending && hoodPotentiometer.Get() >= hoodTarget) {
        ExtendHood();
    }
    else if (!extending && hoodPotentiometer.Get() <= hoodTarget) {
        RetractHood();
    }
    

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

void Shooter::ExtendHood() {
    hoodServoLeft.SetRaw(1899);
    hoodServoRight.SetRaw(99);
}

void Shooter::RetractHood() {
    hoodServoLeft.SetRaw(99);
    hoodServoRight.SetRaw(1899);
}

void Shooter::StopHood() {
    hoodServoLeft.SetRaw(999);
    hoodServoRight.SetRaw(999);
}

bool Shooter::HoodExtended() {
    return hoodPotentiometer.Get() <= 0.715;
}

bool Shooter::HoodRetracted() {
    return hoodPotentiometer.Get() >= 0.8;
}

void Shooter::SetHoodTarget(double target) {
    hoodTarget = target;
    if (hoodTarget == 0.715) {
        extending = true;
    }
    else {
        extending = false;
    }
}