/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <CTRE/Phoenix.h>
#include <WPILib.h>

class LiftSystem : public frc::Subsystem {
private:
	TalonSRX* liftMotor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	LiftSystem();
	void InitDefaultCommand() override;
	void RunLift(float power);
};

