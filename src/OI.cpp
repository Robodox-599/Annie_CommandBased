/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "Commands/LiftUp.h"
#include "Commands/LiftDown.h"

OI::OI() {
	joy = new Joystick(1);
	JoystickButton* Button1 = new JoystickButton(joy, 1);
	JoystickButton* Button2 = new JoystickButton(joy, 2);

	Button1->WhenPressed(new LiftUp());
	Button2->WhenPressed(new LiftDown());
	// Process operator interface input here.
}
