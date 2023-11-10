/*
IR Remote Mode Values
0 - No button
1 - Red Up
2 - Red Down
3 - Blue Up
4 - Blue Down
5 - Red Up Blue Up
6 - Red Up Blue Down
7 - Red Down Blue Up
8 - Red Down Blue Down
9 - Beacon (large top button)
10 - Red Up Red Down
11 - Blue Up Blue Down
*/


task main()
{
	int IR_button_value = 0;

	SensorType(S4) = sensorEV3_IRSensor;
	wait1Msec(50);
	SensorMode(S4) = modeEV3IR_Remote;
	wait1Msec(50);


	while(true){
		IR_button_value = SensorValue(S4);
		displayString(5, "%i", IR_button_value);
	}


}
