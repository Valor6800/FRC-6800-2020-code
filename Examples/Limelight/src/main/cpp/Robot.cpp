/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/AnalogPotentiometer.h>
#include <frc/Encoder.h>
#include <frc/Joystick.h>

#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <cmath>

#include <frc/PWMVictorSPX.h>
#include <rev/CANSparkMax.h>

#include <frc/SpeedControllerGroup.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "networktables/NetworkTable.h"
#include <frc/livewindow/LiveWindow.h>


#define CAN_ID_LEFT_A 1
#define CAN_ID_LEFT_B 2
#define CAN_ID_LEFT_C 3

#define CAN_ID_RIGHT_A 4
#define CAN_ID_RIGHT_B 5 
#define CAN_ID_RIGHT_C 6

#define MAX_OUTPUT 1.0
#define DEADBAND 0.05

/**
 * This sample program provides an example for ShuffleBoard, an alternative
 * to SmartDashboard for displaying values and properties of different robot
 * parts.
 *
 * ShuffleBoard can use pre-programmed widgets to display various values, such
 * as Boolean Boxes, Sliders, Graphs, and more. In addition, they can display
 * things in various Tabs.
 *
 * For more information on how to create personal layouts and more in
 * ShuffleBoard, feel free to reference the official FIRST WPILib documentation
 * online.
 */
class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override {
    // Add a widget titled 'Max Speed' with a number slider.
    m_maxSpeed = frc::Shuffleboard::GetTab("Configuration")
                     .Add("Max Speed", 1)
                     .WithWidget("Number Slider")
                     .GetEntry();
    
    testingDrive = frc::Shuffleboard::GetTab("Drivetest")
                     .Add("Testing Drive?", 1)
                     .WithWidget("Toggle Button")
                     .GetEntry();



    m_robotDrive.SetMaxOutput(MAX_OUTPUT);
    m_robotDrive.SetDeadband(DEADBAND);

    m_drive_l_A.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_drive_l_B.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_drive_l_C.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    m_drive_l_B.Follow(m_drive_l_A);
    m_drive_l_C.Follow(m_drive_l_A);

    m_drive_r_A.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_drive_r_B.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_drive_r_C.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    m_drive_r_A.SetInverted(true);
    m_drive_r_B.SetInverted(true);
    m_drive_r_C.SetInverted(true);

    m_drive_l_A.SetInverted(false);
    m_drive_l_B.SetInverted(false);
    m_drive_l_C.SetInverted(false);
    

    m_drive_r_B.Follow(m_drive_r_A);
    m_drive_r_C.Follow(m_drive_r_A);

    // Create a 'DriveBase' tab and add the drivetrain object to it.
   frc::ShuffleboardTab& driveBaseTab = frc::Shuffleboard::GetTab("DriveBase");
    driveBaseTab.Add("TankDrive", m_robotDrive);

   
   }

  void TeleopPeriodic(){

    float Kp = 0.0572f;
    float min_command = 0.0f;

    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    double targetOffsetAngle_Horizontal = table->GetNumber("tx",0.0);
    double targetOffsetAngle_Vertical = table->GetNumber("ty",0.0);
    double targetArea = table->GetNumber("ta",0.0);
    double targetSkew = table->GetNumber("ts",0.0);

    double rightStick = m_stick.GetX(frc::GenericHID::JoystickHand::kRightHand);
    double leftStick = m_stick.GetY(frc::GenericHID::JoystickHand::kLeftHand);

    float tx = table->GetNumber("tx", 0.0);
    float steering_adjust = 0;
    if(m_stick.GetRawButton(1))
    {
      steering_adjust = Kp * tx;
      m_robotDrive.TankDrive(steering_adjust , steering_adjust);
    }
    else
    {
      m_robotDrive.ArcadeDrive(leftStick , rightStick);
    }
    double maxRatio = m_maxSpeed.GetDouble(1.0);
    frc::SmartDashboard::PutNumber("Right Stick" , rightStick);
    frc::SmartDashboard::PutNumber("Max Spped",m_maxSpeed.GetDouble(1.0));
    //frc::SmartDashboard::PutNumber("Drive Testing?", testingDrive);

    frc::SmartDashboard::PutBoolean("button 1", m_stick.GetRawButton(1));
    frc::SmartDashboard::PutBoolean("button 2", m_stick.GetRawButton(2));
    frc::SmartDashboard::PutBoolean("button 3", m_stick.GetRawButton(3));
    frc::SmartDashboard::PutBoolean("button 4", m_stick.GetRawButton(4));
    
    frc::SmartDashboard::PutNumber("tx" , targetOffsetAngle_Horizontal);
    frc::SmartDashboard::PutNumber("ty" , targetOffsetAngle_Vertical);
    frc::SmartDashboard::PutNumber("ta" , targetArea);
    frc::SmartDashboard::PutNumber("ts" , targetSkew);

    frc::SmartDashboard::PutNumber("left com" , steering_adjust);
    frc::SmartDashboard::PutNumber("right com" , -steering_adjust);

    
    
    // frc::Shuffleboard::GetTab("limelight")
    //                  .Add("Lime Light", 1)
    //                  .WithWidget("Number Slider")
    //                  .GetEntry();

   }

  void AutonomousInit() override {
    // Update the Max Output for the drivetrain.
   // m_robotDrive.SetMaxOutput(m_maxSpeed.GetDouble(1.0));
  }

 private:
  // frc::PWMVictorSPX m_one{0};
  // frc::PWMVictorSPX m_two{1};
  // frc::PWMVictorSPX m_three{2};

  // frc::SpeedControllerGroup m_shooter{m_one , m_two , m_three};


  rev::CANSparkMax m_drive_l_A { CAN_ID_LEFT_A ,  rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_drive_l_B { CAN_ID_LEFT_B ,  rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_drive_l_C { CAN_ID_LEFT_C ,  rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_drive_r_A { CAN_ID_RIGHT_A ,  rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_drive_r_B { CAN_ID_RIGHT_B ,  rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_drive_r_C { CAN_ID_RIGHT_C ,  rev::CANSparkMax::MotorType::kBrushless};


  frc::DifferentialDrive m_robotDrive{m_drive_l_A, m_drive_r_A};

  
  

  frc::Joystick m_stick{0};


  nt::NetworkTableEntry m_maxSpeed;
  nt::NetworkTableEntry testingDrive;
};


#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
