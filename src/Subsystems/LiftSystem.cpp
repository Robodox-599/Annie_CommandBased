/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LiftSystem.h"
#include "../RobotMap.h"

LiftSystem::LiftSystem() : Subsystem("LiftSystem") {
	liftMotor = new TalonSRX(4);
	liftMotor->SetInverted(false);
}

void LiftSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LiftSystem::RunLift(float power)
{
	liftMotor->Set(ControlMode::PercentOutput, power/15);
}
