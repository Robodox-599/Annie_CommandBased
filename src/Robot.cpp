/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>

DriveSystem* Robot::driveSystem = new DriveSystem();
LiftSystem* Robot::liftSystem = new LiftSystem();
OI* Robot::oi = new OI();

void Robot::RobotInit() {
	printf("-- RobotInit()\n");
	//driveSystem = new DriveSystem();
	//oi = new OI();

	m_chooser.AddDefault("Nothing", nullptr);
	m_chooser.AddObject("FWD Two Seconds", new ForwardMotor(2.0));
	m_chooser.AddObject("REV Two Seconds", new ReverseMotor(2.0));
	m_chooser.AddObject("FWD 1, REV 3", new ForwardThenReverse(1.0, 3.0));
	m_chooser.AddObject("Lift Up", new LiftUp());
	m_chooser.AddObject("Lift Down", new LiftDown());
	m_chooser.AddObject("Lift Up Then Down", new LiftUpThenDown());
	frc::SmartDashboard::PutData("My Auto Mode Chooser", &m_chooser);
	//frc::SmartDashboard::PutData(driveSystem);
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
//	std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
//
//	 if (autoSelected == "Default") {
//	 	m_autonomousCommand = m_myAuto;
//	 } else {
//	 	m_autonomousCommand = nullptr; // &m_defaultAuto;
//	 }

	printf("-- AutoInit()\n"); frc::Wait(0.1);

	m_autoCommand.reset(m_chooser.GetSelected());

	if (m_autoCommand.get() != nullptr) {
		printf("-- Starting auto command\r\n");frc::Wait(0.1);
		m_autoCommand->Start();
	}
	else
	{
		printf("-- Auto command was nullptr\r\n");;frc::Wait(0.1);
	}
}

void Robot::AutonomousPeriodic() {
	// printf("-- AutoPeriodic()\r\n");

	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autoCommand != nullptr) {
		m_autoCommand->Cancel();
		m_autoCommand = nullptr;
	}

	printf("-- TeleopInit()\n");
	m_driveByJoystick.reset(new DriveByJoystick());

	printf("-- Start Command\n");
	m_driveByJoystick->Start();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)
