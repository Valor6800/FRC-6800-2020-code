#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

class Lift : public frc2::SubsystemBase {
 public:

    Lift();

    void SetLiftPower(double power);
    void Periodic() override;

 private:

    rev::CANSparkMax liftA{7, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax liftB{8, rev::CANSparkMax::MotorType::kBrushless};

};