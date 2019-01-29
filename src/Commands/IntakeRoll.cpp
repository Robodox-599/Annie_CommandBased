/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IntakeRoll.h"
#include "Pause.h"
#include "../Robot.h"

IntakeRoll::IntakeRoll() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(globalRobot.chassis.get());
	Requires(&globalRobot.intakeRollerSystem);
}

// Called just before this Command runs the first time
void IntakeRoll::Initialize() {
	globalRobot.intakeRollerSystem.IntakeRoll(1);
	SetTimeout(4);
}

// Called repeatedly when this Command is scheduled to run
void IntakeRoll::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeRoll::IsFinished() {
		return IsTimedOut();
}

// Called once after isFinished returns true
void IntakeRoll::End() {
	globalRobot.intakeRollerSystem.IntakeRoll(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeRoll::Interrupted() {
	End();
}
