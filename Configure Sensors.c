/*
Group 4-4 Yiting Han, Colin MacMillan, Jade Lee, Derek Bian

This function resets all the sensors
IR1 Touch 2 color 3
*/

void configureSensors(){
    SensorType[S1] = sensorEV3_IRSensor;
    wait1Msec(50);
    SensorMode[S1] = modeEV3IR_Remote;
    wait1Msec(50);
    SensorType[S2] = sensorEV3_Touch;
    wait1Msec(50);
    SensorType[S3] = sensorEV3_Color;
    wait1Msec(50);
    SensorMode[S3] = modeEV3Color_Color;
}
