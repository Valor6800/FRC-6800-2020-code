/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include <fstream>
#include <frc/Timer.h>
#include <frc/XboxController.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include "networktables/NetworkTable.h"
#include <frc/livewindow/LiveWindow.h>

#include <cmath>

#define DEADBAND_Y 0.02
#define DEADBAND_X 0.02
#define DRIVE_MULTIPLIER_X 0.5
#define DRIVE_MULTIPLIER_Y 1

#define DRIVE_OFFSET_K 1

#define KP -0.01f
#define MIN_COMMAND 0.0f

class Robot : public frc::TimedRobot {
  /**
   * SPARK MAX controllers are intialized over CAN by constructing a CANSparkMax object
   * 
   * The CAN ID, which can be configured using the SPARK MAX Client, is passed as the
   * first parameter
   * 
   * The motor type is passed as the second parameter. Motor type can either be:
   *  rev::CANSparkMax::MotorType::kBrushless
   *  rev::CANSparkMax::MotorType::kBrushed
   * 
   * The example below initializes four brushless motors with CAN IDs 1, 2, 3 and 4. Change
   * these parameters to match your setup
   */
  static const int leftLeadDeviceID = 1, leftFollow1DeviceID = 2, leftFollow2DeviceID = 3, rightLeadDeviceID = 4, rightFollow1DeviceID = 5, rightFollow2DeviceID = 6;
  
  rev::CANSparkMax m_leftLeadMotor{leftLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_leftFollow1Motor{leftFollow1DeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_leftFollow2Motor{leftFollow2DeviceID, rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_rightLeadMotor{rightLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightFollow1Motor{rightFollow1DeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightFollow2Motor{rightFollow2DeviceID, rev::CANSparkMax::MotorType::kBrushless};

  /**
   * In order to use PID functionality for a controller, a CANPIDController object
   * is constructed by calling the GetPIDController() method on an existing
   * CANSparkMax object
   */
  rev::CANPIDController m_leftPIDController = m_leftLeadMotor.GetPIDController();
  rev::CANPIDController m_rightPIDController = m_rightLeadMotor.GetPIDController();

  // Encoder object created to display velocity values
  rev::CANEncoder m_leftEncoder = m_leftLeadMotor.GetEncoder();
  rev::CANEncoder m_rightEncoder = m_rightLeadMotor.GetEncoder();

  // motor max RPM
  const double MaxRPM = 5700;

  // default PID coefficients
    // double kP = 5e-5, kI = 1e-6, kD = 0, kIz = 0, kFF = 0.000156, kMaxOutput = 1.0, kMinOutput = -1.0;
  double kP = 0, kI = 0, kD = 0, kIz = 0, kFF = 1.0/MaxRPM, kMaxOutput = 1.0, kMinOutput = -1.0;

  double kMaxVel = 1000, kMinVel = 0, kMaxAccel = 1500, kAllError = 0;

  int file_iterator = 0;

  /**
   * In RobotInit() below, we will configure m_leftFollowMotor and m_rightFollowMotor to follow 
   * m_leftLeadMotor and m_rightLeadMotor, respectively. 
   * 
   * Because of this, we only need to pass the lead motors to m_robotDrive. Whatever commands are 
   * sent to them will automatically be copied by the follower motors
   */
  // frc::DifferentialDrive m_robotDrive{m_leftLeadMotor, m_rightLeadMotor};

  frc::XboxController m_GamepadDriver{0};

  /**
   * Output stream to log motor current
   **/
  std::ofstream logging_file;
  
 public:

  void setIdleMode(rev::CANSparkMax::IdleMode mode) {
    m_leftLeadMotor.SetIdleMode(mode);
    m_leftFollow1Motor.SetIdleMode(mode);
    m_leftFollow2Motor.SetIdleMode(mode);

    m_rightLeadMotor.SetIdleMode(mode);
    m_rightFollow1Motor.SetIdleMode(mode);
    m_rightFollow2Motor.SetIdleMode(mode);
  }

  void InitDrives() {
    /**
     * The RestoreFactoryDefaults method can be used to reset the configuration parameters
     * in the SPARK MAX to their factory default state. If no argument is passed, these
     * parameters will not persist between power cycles
     */
    m_leftLeadMotor.RestoreFactoryDefaults();
    m_leftFollow1Motor.RestoreFactoryDefaults();
    m_leftFollow2Motor.RestoreFactoryDefaults();
    m_rightLeadMotor.RestoreFactoryDefaults();
    m_rightFollow1Motor.RestoreFactoryDefaults();
    m_rightFollow2Motor.RestoreFactoryDefaults();

    /**
     * Set inversion to false to gaurentee motors go in the same direction
     **/
    m_leftLeadMotor.SetInverted(false);
    m_rightLeadMotor.SetInverted(true);
    
    /**
     * In CAN mode, one SPARK MAX can be configured to follow another. This is done by calling
     * the Follow() method on the SPARK MAX you want to configure as a follower, and by passing
     * as a parameter the SPARK MAX you want to configure as a leader.
     * 
     * This is shown in the example below, where one motor on each side of our drive train is
     * configured to follow a lead motor.
     */
    m_leftFollow1Motor.Follow(m_leftLeadMotor);
    m_rightFollow1Motor.Follow(m_rightLeadMotor);

    m_leftFollow2Motor.Follow(m_leftLeadMotor);
    m_rightFollow2Motor.Follow(m_rightLeadMotor);

    // set motors to brake mode
    setIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    
    // set PID coefficients
    m_leftPIDController.SetP(kP);
    m_leftPIDController.SetI(kI);
    m_leftPIDController.SetD(kD);
    m_leftPIDController.SetIZone(kIz);
    m_leftPIDController.SetFF(kFF);
    m_leftPIDController.SetOutputRange(kMinOutput, kMaxOutput);

    m_rightPIDController.SetP(kP);
    m_rightPIDController.SetI(kI);
    m_rightPIDController.SetD(kD);
    m_rightPIDController.SetIZone(kIz);
    m_rightPIDController.SetFF(kFF);
    m_rightPIDController.SetOutputRange(kMinOutput, kMaxOutput);

    m_rightPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    m_rightPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    m_rightPIDController.SetSmartMotionMaxAccel(kMaxAccel);
    m_rightPIDController.SetSmartMotionAllowedClosedLoopError(kAllError);
    
    m_leftPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    m_leftPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    m_leftPIDController.SetSmartMotionMaxAccel(kMaxAccel);
    m_leftPIDController.SetSmartMotionAllowedClosedLoopError(kAllError);
  }

  void LogOutput(double setpoint, double turnOffset) {
    logging_file << frc::Timer::GetFPGATimestamp() << ",";
    logging_file << setpoint << ",";
    logging_file << m_leftEncoder.GetPosition() << ",";
    logging_file << m_rightEncoder.GetPosition() << ",";
    logging_file << m_leftEncoder.GetVelocity() << ",";
    logging_file << m_rightEncoder.GetVelocity() << ",";
    logging_file << m_leftLeadMotor.GetAppliedOutput() << ",";
    logging_file << m_rightLeadMotor.GetAppliedOutput() << ",";
    logging_file << m_leftLeadMotor.GetOutputCurrent() << ",";
    logging_file << m_leftFollow1Motor.GetOutputCurrent() << ",";
    logging_file << m_leftFollow2Motor.GetOutputCurrent() << ",";
    logging_file << m_rightLeadMotor.GetOutputCurrent() << ",";
    logging_file << m_rightFollow1Motor.GetOutputCurrent() << ",";
    logging_file << m_rightFollow2Motor.GetOutputCurrent() << ",";
    logging_file << turnOffset;
    logging_file << "\n";
  }

  void TeleopInit() {
    logging_file.open("/home/lvuser/motor_output.csv");
    logging_file << "Time,SetPoint,LeftEncoder,RightEncoder,LeftSpeed,RightSpeed,LeftOutput,RightOutput,LeftLead,LeftFollow1,LeftFollow2,RightLead,RightFollow1,RightFollow2,TurnOffset\n";
  }
  
  void DisabledInit() {
    logging_file.close();
  }

  void RobotInit() {
    InitDrives();
  }

  void TeleopPeriodic() {

    double boost_multiplier = 0.5;
    // read setpoint from joystick and scale by max rpm
    if (m_GamepadDriver.GetRawButton(6)) {
      boost_multiplier = 1;
    }
    
    double joystick_y_value = m_GamepadDriver.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) - m_GamepadDriver.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand);
    if (std::abs(joystick_y_value) < DEADBAND_Y) {
      joystick_y_value = 0;
    }
    
    double direction_y = (joystick_y_value > 0) ? 1 : -1;
    double straight_target = MaxRPM * -std::pow(joystick_y_value, 2) * direction_y * DRIVE_MULTIPLIER_Y * boost_multiplier;
   
    double joystick_x_value = m_GamepadDriver.GetX(frc::GenericHID::kLeftHand);
    double direction_x = (joystick_x_value >= 0) ? 1 : -1;
    joystick_x_value = -std::pow(joystick_x_value * DRIVE_MULTIPLIER_X, 2) * direction_x;
    double turn_target = MaxRPM * joystick_x_value;
    if (direction_y == 1) {   //for inverting x and y in revese direction
      turn_target = -turn_target;
    }
    
    if (std::abs(joystick_x_value) < DEADBAND_X) {
      if (std::abs(joystick_y_value) < DEADBAND_Y)
        turn_target = 0; //if turning, don't use drive straightening
      else
        turn_target = (m_leftEncoder.GetVelocity() - m_rightEncoder.GetVelocity()) * DRIVE_OFFSET_K;
        // Robot tends to curve to the left at 50RPM slower
    }
    
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    float tx = table->GetNumber("tx", 0.0);
    float tv = table->GetNumber("tv" , 0.0);

    if (m_GamepadDriver.GetRawButton(5) && tv == 1) {
      turn_target = KP * tx * MaxRPM;
    }

    m_leftPIDController.SetReference(straight_target - turn_target, rev::ControlType::kVelocity);
    m_rightPIDController.SetReference(straight_target + turn_target, rev::ControlType::kVelocity);

    frc::SmartDashboard::PutNumber("TurnVelocity", turn_target);
    frc::SmartDashboard::PutNumber("ForwardVelocity", straight_target);
    frc::SmartDashboard::PutNumber("LeftVelocityVariable", m_leftEncoder.GetVelocity());
    frc::SmartDashboard::PutNumber("RightVelocityVariable", m_rightEncoder.GetVelocity());

    LogOutput(straight_target, turn_target);
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
