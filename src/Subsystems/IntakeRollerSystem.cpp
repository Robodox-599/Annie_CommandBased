/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <CTRE/Phoenix.h>
#include <Subsystems/IntakeRollerSystem.h>
#include <frc/WPILib.h>
#include "../RobotMap.h"

IntakeRollerSystem::IntakeRollerSystem() : Subsystem("IntakeRollerSystem"), intakeRoller(2) {
}

void IntakeRollerSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeRollerSystem::IntakeRoll(float power)
{
	intakeRoller.Set(ControlMode::PercentOutput, power);
}
