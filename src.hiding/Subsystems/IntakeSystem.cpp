/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IntakeSystem.h"
#include <CTRE/Phoenix.h>
#include <WPILib.h>
#include "../RobotMap.h"

IntakeSystem::IntakeSystem() : Subsystem("IntakeSystem") {;
	intakePiston = new DoubleSolenoid(4, 7);
}

void IntakeSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeSystem::IntakeDown()
{
	intakePiston->Set(DoubleSolenoid::kForward);
}

void IntakeSystem::IntakeUp()
{
	intakePiston->Set(DoubleSolenoid::kReverse);
}

bool IntakeSystem::IntakePosition()
{
	if(intakePiston->Get() == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
