/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoTurn.h"
#include "../Robot.h"

AutoTurn::AutoTurn(double time) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveSystem);
	seconds = time;
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
	Robot::driveSystem->AutoTurn(0.5);
	SetTimeout(seconds);
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoTurn::End() {
	Robot::driveSystem->AutoTurn(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {
	End();
}
