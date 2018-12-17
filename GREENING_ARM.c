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

float Height0 = 0; //Floor
float Height1 = -100; //Place HighScored Hub and Move MultiPusher Over Field Lines
float Height2 = -200; //Position HighScored Hub
float Height3 = -300; //Static Height / Moving height for balance
float Height4 = -500; //Bonus Hub Position
float Height5 = -680; //Bonus Hub PickUp
int ArmPresetValue = 0; // the preset number that tells the preset code how high to move the arm

//FUNCTIONS//
void ArmTopLimit() {
	if (getBumperValue(ArmTopBumper)==1 && getJoystickValue(BtnRUp)){
		stopMultipleMotors(ArmLeft, ArmRight);
	};
};


void ArmHeightMove() {
	switch(ArmPresetValue) {  //moves the arm by reading the variable (ArmPresetValue)
	case 0://Position 0
		setMotorTarget(ArmLeft, Height0, 100);
		setMotorTarget(ArmRight, Height0, 100);
		setTouchLEDColor(LED,colorOrange);
		setTouchLEDColor(LED,colorNone);
		break;

	case 1://Position 1
		setMotorTarget(ArmLeft, Height1, 100);
		setMotorTarget(ArmRight, Height1, 100);
		setTouchLEDColor(LED,colorOrange);
		setTouchLEDColor(LED,colorNone);
		break;

	case 2://Position 2
		setMotorTarget(ArmLeft, Height2, 100);
		setMotorTarget(ArmRight, Height2, 100);
		setTouchLEDColor(LED,colorOrange);
		setTouchLEDColor(LED,colorNone);
		break;

	case 3://Position 3
		setMotorTarget(ArmLeft, Height3, 100);
		setMotorTarget(ArmRight, Height3, 100);
		setTouchLEDColor(LED,colorOrange);
		setTouchLEDColor(LED,colorNone);
		break;

	case 4://Position 4
		setMotorTarget(ArmLeft, Height4, 100);
		setMotorTarget(ArmRight, Height4, 100);
		setTouchLEDColor(LED,colorOrange);
		setTouchLEDColor(LED,colorNone);
		break;

	case 5://Position 5
		setMotorTarget(ArmLeft, Height5, 100);
		setMotorTarget(ArmRight, Height5, 100);
		setTouchLEDColor(LED,colorOrange);
		setTouchLEDColor(LED,colorNone);
		break;

	};
};

void ArmReset() {
	if (getBumperValue(ArmBottomBumper)==1) {
		resetMotorEncoder(ArmLeft);
		resetMotorEncoder(ArmRight);
		setTouchLEDColor(LED,colorBlue);
		setTouchLEDColor(LED,colorNone);

	}
}



// END OF LIBRARY
