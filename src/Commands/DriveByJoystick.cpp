/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveByJoystick.h"
#include "../Robot.h"

DriveByJoystick::DriveByJoystick() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveSystem);
}

// Called just before this Command runs the first time
void DriveByJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveByJoystick::Execute() {

//	double x = Robot::m_oi.getJoystick()->GetRawAxis(0);
//	double y = Robot::m_oi.getJoystick()->GetRawAxis(1);
	Robot::driveSystem->JoystickDrive(Robot::oi->joy->GetRawAxis(0)/5.0, Robot::oi->joy->GetRawAxis(1)/5.0);

	frc::SmartDashboard::PutNumber("Joy Y", Robot::oi->joy->GetRawAxis(1));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveByJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveByJoystick::End() {
	Robot::driveSystem->JoystickDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByJoystick::Interrupted() {
	End();
}
