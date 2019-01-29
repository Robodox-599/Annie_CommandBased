/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ForwardMotor.h"

#include "../Robot.h"

ForwardMotor::ForwardMotor(float secondsToRun) {
	// Use Requires() here to declare subsystem dependencies
	Requires(&globalRobot.driveSystem);

	m_secondsToRun = secondsToRun;
}

// Called just before this Command runs the first time
void ForwardMotor::Initialize() {
	printf("m_secondsToRun: %f", m_secondsToRun);
	SetTimeout(m_secondsToRun); // Drive time in Seconds
	globalRobot.driveSystem.JoystickDrive(0, .1);
}

// Called repeatedly when this Command is scheduled to run
void ForwardMotor::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ForwardMotor::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ForwardMotor::End() {
	globalRobot.driveSystem.JoystickDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForwardMotor::Interrupted() {
	End();
}
