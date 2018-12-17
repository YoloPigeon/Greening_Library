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
bool overTemp; // if any of the motors are overtemp set this value to true
bool currentLimitFlag; // if any of the motors are using current above the default value set this value to true

//FUNCTIONS//

void EMERGENCYSTOP (float delay) { // if emergency stop buttons are pushed stop all motor and blink red on touch led
	if ((getJoystickValue(BtnEDown)==1)&&(getJoystickValue(BtnFDown)==1)| (overTemp==true)|(currentLimitFlag==true)) {
		sleep(delay);
		repeatUntil(getTouchLEDValue(LED)==1 || (getJoystickValue(BtnEDown)==1) || (getJoystickValue(BtnFDown)==1)) {
			setTouchLEDColor(LED,colorRed);
			setTouchLEDBlinkTime(LED, 12.5, 7.5);
			stopAllMotors();
			playSound(soundCarAlarm2);
		};
		setTouchLEDColor(LED, colorNone);
	};
};

void MotorDiagnostics() { // checks for motor overtemp or currentLimitFlag and plays an alarm if they are true
	if ((overTemp==true)|(currentLimitFlag==true))
		playSound(soundCarAlarm2);
};




// END OF LIBRARY
