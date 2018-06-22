/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Subsystems/CatapultSystem.h>
#include <CTRE/Phoenix.h>
#include <WPILib.h>
#include "../RobotMap.h"

CatapultSystem::CatapultSystem() : Subsystem("CatapultSystem") {
	winchMotor = new TalonSRX(3);
	releasePiston = new DoubleSolenoid(5, 6);
}

void CatapultSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void CatapultSystem::pullBack(float power)
{
	winchMotor->Set(ControlMode::PercentOutput, power);
}

void CatapultSystem::firePiston()
{
	releasePiston->Set(DoubleSolenoid::kReverse);
}

void CatapultSystem::resetPiston()
{
	releasePiston->Set(DoubleSolenoid::kForward);
}
