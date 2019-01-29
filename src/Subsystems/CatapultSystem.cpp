/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Subsystems/CatapultSystem.h>
#include <CTRE/Phoenix.h>
#include <frc/WPILib.h>
#include "../RobotMap.h"

using namespace frc;

CatapultSystem::CatapultSystem() : Subsystem("CatapultSystem"), winchMotor(3), releasePiston(5, 6), catapultLimit(8) {
}

void CatapultSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void CatapultSystem::PullBack(float power)
{
	winchMotor.Set(ControlMode::PercentOutput, power);
}

void CatapultSystem::FirePiston()
{
	releasePiston.Set(DoubleSolenoid::kReverse);
}

void CatapultSystem::ResetPiston()
{
	releasePiston.Set(DoubleSolenoid::kForward);
}

bool CatapultSystem::GetLimitSwitch()
{
	return catapultLimit.Get();
}

bool CatapultSystem::PistonPosition()
{
	if(releasePiston.Get() == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
