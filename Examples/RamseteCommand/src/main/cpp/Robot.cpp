/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/shuffleboard/Shuffleboard.h>

void Robot::RobotInit() {

  m_maxSpeed = frc::Shuffleboard::GetTab("Configuration")
                     .Add("Max Speed", 0.5)
                     .WithWidget("Number Slider")
                     .GetEntry();
}
bool potFReached = true;
bool potBReached = true;
/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {
if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {

  frc::SmartDashboard::PutNumber("Servo Angle", m_servo.GetAngle());
  frc::SmartDashboard::PutNumber("Servo Position", m_servo.GetPosition());
  frc::SmartDashboard::PutNumber("Servo Raw", m_servo.GetRaw());
  frc::SmartDashboard::PutNumber("Servo Speed", m_servo.GetSpeed());
  frc::SmartDashboard::PutNumber("PotVal", m_potentiometer.Get());
  
  frc::SmartDashboard::PutBoolean("Switch",  m_limitSwitch.Get());

  double maxSpeed = m_maxSpeed.GetDouble(0.5);
  
  // if(OperatorController.GetRawButton(1) && m_limitSwitch.Get()) {
  //   //m_servo.SetPosition(maxSpeed);
  //     m_servo.SetRaw(1899);

  // } else if(OperatorController.GetRawButton(2)){
  //   m_servo.SetRaw(99);
  //   } else {
  //     m_servo.SetPosition(0.5);
  // }

  if (OperatorController.GetRawButton(4))
  {
    potFReached = false;
  }else if(OperatorController.GetRawButton(3))
  {
    potBReached = false;
  }

  if(m_potentiometer.Get() <= potUpperSetpoint && potFReached == false)
  {
    m_servo.SetRaw(1899);
  }

  if(m_potentiometer.Get() >= potUpperSetpoint && potFReached == false)
  {
    potFReached = true;
    m_servo.SetRaw(999);
  }



  if(m_potentiometer.Get() >= potLowerSetpoint && potBReached == false)
  {
    m_servo.SetRaw(99);
  }

  if(m_potentiometer.Get() <= potLowerSetpoint && potBReached == false)
  {
    potBReached = true;
    m_servo.SetRaw(999);
  }



}
/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
