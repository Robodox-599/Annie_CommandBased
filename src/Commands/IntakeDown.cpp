/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IntakeDown.h"
#include "../Robot.h"

IntakeDown::IntakeDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(globalRobot.chassis.get());
	Requires(&globalRobot.intakeSystem);
}

// Called just before this Command runs the first time
void IntakeDown::Initialize() {
	globalRobot.intakeSystem.IntakeDown();
}

// Called repeatedly when this Command is scheduled to run
void IntakeDown::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeDown::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void IntakeDown::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeDown::Interrupted() {
	End();
}
