#include "subsystems/Shooter.h"

Shooter::Shooter() : shootMtrLeft{ShooterConstants::CAN_ID_SHOOTER_LEAD, rev::CANSparkMax::MotorType::kBrushless}, 
                     shootMtrRight{ShooterConstants::CAN_ID_SHOOTER_FOLLOW, rev::CANSparkMax::MotorType::kBrushless}, 
                     hoodServoLeft{9},
                     hoodServoRight{6},
                     hoodPotentiometer{3},
                     deadzone{0.005} {
    InitShooter(rev::CANSparkMax::IdleMode::kCoast);
    shooterPower = frc::Shuffleboard::GetTab("Configuration").Add("Shooter_Power", 1).WithWidget("Text View").GetEntry();

    kP_entry = frc::Shuffleboard::GetTab("Configuration").Add("kP", 1).WithWidget("Text View").GetEntry();
    kI_entry = frc::Shuffleboard::GetTab("Configuration").Add("kI", 1).WithWidget("Text View").GetEntry();
    kD_entry = frc::Shuffleboard::GetTab("Configuration").Add("kD", 1).WithWidget("Text View").GetEntry();
    kFF_entry = frc::Shuffleboard::GetTab("Configuration").Add("kFF", 1).WithWidget("Text View").GetEntry();
    kIzone_entry = frc::Shuffleboard::GetTab("Configuration").Add("kIzone", 1).WithWidget("Text View").GetEntry();

    hoodTarget = hoodPotentiometer.Get();
}

Shooter& Shooter::GetInstance() {
    static Shooter instance;
    return instance;
}

void Shooter::Periodic() {
    shooterPow = shooterPower.GetDouble(0.25);

    kP = kP_entry.GetDouble(0);
    kI = kI_entry.GetDouble(0);
    kD = kD_entry.GetDouble(0);
    kFF = kFF_entry.GetDouble(0);
    kIzone = kIzone_entry.GetDouble(0);

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

    m_shootMtrLeftPID.SetP(kP);
    m_shootMtrLeftPID.SetI(kI);
    m_shootMtrLeftPID.SetD(kD);
    m_shootMtrLeftPID.SetIZone(kIzone);
    m_shootMtrLeftPID.SetFF(kFF);
    m_shootMtrLeftPID.SetOutputRange(ShooterConstants::MIN_OUTPUT, ShooterConstants::MAX_OUTPUT);

    m_shootMtrRightPID.SetP(kP);
    m_shootMtrRightPID.SetI(kI);
    m_shootMtrRightPID.SetD(kD);
    m_shootMtrRightPID.SetIZone(kIzone);
    m_shootMtrRightPID.SetFF(kFF);
    m_shootMtrRightPID.SetOutputRange(ShooterConstants::MIN_OUTPUT, ShooterConstants::MAX_OUTPUT);

    shootMtrLeft.SetInverted(true);
    shootMtrRight.SetInverted(false);
}

void Shooter::SetShooterPower(double power) {
    m_shootMtrLeftPID.SetReference(power * ShooterConstants::MAX_RPM, rev::ControlType::kVelocity);
    m_shootMtrRightPID.SetReference(power * ShooterConstants::MAX_RPM, rev::ControlType::kVelocity);
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