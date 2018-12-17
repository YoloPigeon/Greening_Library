#pragma systemFile
/*
// CALL ALL DEVICES BASED ON SETUP LIST BELOW OR THE CODE WILL NOT WORK
//SENSORS
#pragma config(Sensor, port2,  ArmBottomBumper, sensorVexIQ_Touch)
#pragma config(Sensor, port5,  ArmTopBumper,   sensorVexIQ_Touch)
#pragma config(Sensor, port3,  Main_Gyro,      sensorVexIQ_Gyro)
#pragma config(Sensor, port4,  LED,            sensorVexIQ_LED)
#pragma config(Sensor, port7,  LeftColor,      sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port8,  MidColor,       sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port9,  RightColor,     sensorVexIQ_ColorGrayscale)
//MOTORS
#pragma config(Motor,  motor1,          Left,          tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          Right,         tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor10,         ArmRight,      tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor11,         ArmLeft,       tmotorVexIQ, PIDControl, encoder)
*/
//VARIABLES//
float Setting; // for DriveSelection
//FUNCTIONS//

void driveDistance(float distance) {
	float MoveDistanceRotations=distance/200;
	setMotorTarget(ArmLeft, MoveDistanceRotations, 100);
	setMotorTarget(ArmRight, MoveDistanceRotations, 100);
};

bool TurnDegrees (float varTurnDegrees) {
	if (varTurnDegrees>0) {
		setMotorSpeed(Left, 50);
		setMotorSpeed(Right, -50);
		if (getGyroDegrees(Main_Gyro)>varTurnDegrees) {
			return false;
		}
		} else {
		setMotorSpeed(Left, -50);
		setMotorSpeed(Right, 50);
		if (getGyroDegrees(Main_Gyro)<varTurnDegrees) {
			return false;

		}

	}
	return true;
}

void DriveSelection () { // Must Run in Loop
	setTouchLEDColor(LED, colorGreen);
	// change Setting
	if (getTouchLEDValue(LED)) {
		Setting = Setting + 1;
		delay(100);

	}
	// Math Function

	if (Setting < 0) {
		Setting = 0;
		} else if (Setting > 3) {\
		Setting = 0;
	};

	// Drive Style Switch
	switch (Setting) {
	case 0: // Left
		arcadeControl(ChB, ChA, 15);
		armControl(ArmLeft, BtnLUp, BtnLDown, 100);
		armControl(ArmRight, BtnLUp, BtnLDown, 100);
		displayText(line1, "Left");
		break;

	case 1: // Right
		arcadeControl(ChC, ChD, 15);
		armControl(ArmLeft, BtnLUp, BtnLDown, 100);
		armControl(ArmRight, BtnLUp, BtnLDown, 100);
		displayText(line1, "Right");
		break;

	case 2: // Split L
		arcadeControl(ChC, ChA, 15);
		armControl(ArmLeft, BtnLUp, BtnLDown, 100);
		armControl(ArmRight, BtnLUp, BtnLDown, 100);
		displayText(line1, "Split L");
		break;

	case 3: // Split R
		arcadeControl(ChB, ChD, 15);
		armControl(ArmLeft, BtnLUp, BtnLDown, 100);
		armControl(ArmRight, BtnLUp, BtnLDown, 100);
		displayText(line1, "Split R");
		break;

		/*case 4: // Tank
		if(abs(getJoystickValue(ChA))>25 || abs(getJoystickValue(ChD))>25) {	//if the absoloute value of ChA is above 20 or the absoloute value of ChD is above 15 then allow the Motors to
		setMotorSpeed(Left, getJoystickValue(ChA)); //set the value of the motor to the value of the controller joystick
		setMotorSpeed(Right, getJoystickValue(ChD)); //set the value of the motor to the value of the controller joystick
		}
		else { setMotorSpeed(Left, 0);	// if nothing is happening on the controller set the motor speed to 0
		setMotorSpeed(Right, 0); // if nothing is happening on the controller set the motor speed to 0
		};
		armControl(LiftL, BtnLUp, BtnLDown, 100);
		armControl(LiftR, BtnLUp, BtnLDown, 100);
		displayText(line1, "Tank");
		break;*/

	default: Setting = 0;
	}
}

// END OF LIBRARY
