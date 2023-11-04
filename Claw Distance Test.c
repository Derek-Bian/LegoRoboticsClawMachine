/*
Group 4-4

This code is outputing a motorencoder value to see how many turns must be made to close the claw.

Test 1 Yielded Value of -3309
Test 2 Yielded Value of -3026
Test 3: -3095

*/



task main()
{
	displayString(3, "Press any button");
	//waiting for button to be pressed
	while(!getButtonPress(buttonAny))
	{}
	motor[motorA] = -30;
	nMotorEncoder[motorA] = 0;

	//waiting for button to be released
	while(getButtonPress(buttonAny))
	{}

	motor[motorA] = 0;
	displayString(5, "%f", nMotorEncoder[motorA]);
	displayString(6, "Press any button to terminate");

	//waiting for button to be pressed to terminate
	while(!getButtonPress(buttonAny))
	{}

}
