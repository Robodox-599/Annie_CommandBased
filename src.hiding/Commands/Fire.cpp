/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Fire.h"
#include "../Robot.h"

Fire::Fire() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::catapultSystem);
}

// Called just before this Command runs the first time
void Fire::Initialize() {
	Robot::catapultSystem->FirePiston();
}

// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	return Robot::catapultSystem->PistonPosition();
}

// Called once after isFinished returns true
void Fire::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	End();
}
