#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEAD, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_FOLLOW, rev::CANSparkMax::MotorType::kBrushless}, 
                     hoodServoLeft{ShooterConstants::PWM_ID_HOOD_LEFT},
                     hoodServoRight{ShooterConstants::PWM_ID_HOOD_RIGHT},
                     hoodPotentiometer{ShooterConstants::ID_HOOD_POTENTIOMETER},
                     deadzone{ShooterConstants::POTENTIOMETER_DEADZONE} {
    shooterPower = frc::Shuffleboard::GetTab("Configuration").Add("Shooter_Power", 1).WithWidget("Text View").GetEntry();
    hoodTarget = hoodPotentiometer.Get();

    InitShooter();
}

Shooter& Shooter::GetInstance() {
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
    shooterPow = shooterPower.GetDouble(0.25);
    
    frc::SmartDashboard::PutNumber("Potentiometer value", hoodPotentiometer.Get());

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

void Shooter::SetShooterPower(double power) {
    shootMtrs.Set(power);
}

double Shooter::GetShooterNTPower() {
    return shooterPow;
}

void Shooter::ExtendHood() {
    hoodServoLeft.SetRaw(ShooterConstants::SERVO_COUNTER_CLOCKWISE);
    hoodServoRight.SetRaw(ShooterConstants::SERVO_CLOCKWISE);
}

void Shooter::RetractHood() {
    hoodServoLeft.SetRaw(ShooterConstants::SERVO_CLOCKWISE);
    hoodServoRight.SetRaw(ShooterConstants::SERVO_COUNTER_CLOCKWISE);
}

void Shooter::StopHood() {
    hoodServoLeft.SetRaw(ShooterConstants::SERVO_STATIONARY);
    hoodServoRight.SetRaw(ShooterConstants::SERVO_STATIONARY);
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