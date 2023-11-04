/*
Group 4-4

This code is an initial prototype of a grab object and release object function


*/

//Constants
int claw = motor[motorA];

//uses timer 1
void grab_object(int claw){
	time1[T1] = 0;
	nMotorEncoder[claw] = 0;
	motor[claw] = -30;
	while(time1[T1] < 10000)
	{}
	motor[claw] = 0;
}

void release_object(int claw){
	motor[claw] = 30;
	while(nMotorEncoder[claw] < 0)
	{}
	motor[claw] = 0;
}

task main()
{
	grab_object(claw);

	wait1Msec(5000);

	release_object(claw);


}
