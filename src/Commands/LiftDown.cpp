/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LiftDown.h"
#include "../Robot.h"

LiftDown::LiftDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::liftSystem);
}

// Called just before this Command runs the first time
void LiftDown::Initialize() {
	SetTimeout(3.0);
	Robot::liftSystem->RunLift(-1);
}

// Called repeatedly when this Command is scheduled to run
void LiftDown::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LiftDown::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void LiftDown::End() {
	Robot::liftSystem->RunLift(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftDown::Interrupted() {
	End();
}
