/*
Group 4-4

This code is outputing a motorencoder value to see how many turns must be made to close the claw.

*/



task main()
{
	//waiting for button to be pressed
	while(!getButtonPress(buttonAny))
	{}
	motor[motorA] = 10;
	nMotorEncoder[motorA] = 0;

	//waiting for button to be released
	while(getButtonPress(buttonAny)
	{}

	motor[motorA] = 0;
	displayString(5, "%f", nMotorEncoder[motorA]);
	displayString(6, "Press any button to terminate");

	//waiting for button to be pressed to terminate
	while(!getButtonPress(buttonAny))
	{}

}
