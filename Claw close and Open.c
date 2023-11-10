/*
Group 4-4 Yiting Han, Colin MacMillan, Jade Lee, Derek Bian

This function closes or opens the claw for a given time, with a passed int of 1 for closing, and -1 for opening

NOTE: time is a "magic number"
Power at 30% deemed to be sufficient
*/
void ClawGrab(int close = 1){
    motor[motorC] = -30 * close;
	time1[T1] = 0;

    while(time1[T1] < 10000)
    {}

    motor[motorC] = 0;
}