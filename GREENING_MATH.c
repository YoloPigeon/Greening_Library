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

//FUNCTIONS//

void placeholder() {
	displayText(line1, "**Placeholder**");
	moveMotorTarget(Left, 100, 100);
};




//END OF LIBRARY