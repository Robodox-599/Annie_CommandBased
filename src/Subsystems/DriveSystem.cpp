/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveSystem.h"
#include "../RobotMap.h"

DriveSystem::DriveSystem() : Subsystem("DriveSystem") {
	//frontLeftMotor = new TalonSRX(1);
	rearLeftMotor = new TalonSRX(2);
	//frontRightMotor = new TalonSRX(3);
	//rearRightMotor = new TalonSRX(4);

	//frontLeftMotor->SetInverted(false);
	rearLeftMotor->SetInverted(false);
	//frontRightMotor->SetInverted(true);
	//rearRightMotor->SetInverted(true);
}

void DriveSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveSystem::JoystickDrive(double x, double y)
{
	double l;
	double r;
	double max;

	if(y<=0)
		{l=-y+x; r=-y-x;}
	else
		{l= -y-x; r=-y+x;}

	max=abs(l);
	if(max<abs(r)) max=abs(r);

	if(max>1) {l/=max; r/=max;}

	//frontLeftMotor->Set(ControlMode::PercentOutput, l);
	rearLeftMotor->Set(ControlMode::PercentOutput, l);
	//frontRightMotor->Set(ControlMode::PercentOutput, r);
	//rearRightMotor->Set(ControlMode::PercentOutput, r);
}


