/*
Group 4-4 Yiting Han, Colin Macmillan, Jade Lee, Derek Bian


Motors that move the axis are A and D, the motor that moves the cart is B
this funcion moves the robot in the x-y axes without checking the motor encoder values
*/

void manual_reset_move(int power = 10){
    int sense = SensorValue(S1);
	if(sense == 1){
	    motor[motorA] = motor[motorD] = power;
    }
    else if(sense == 2){
    	motor[motorA] = motor[motorD] = -power;
    }
    else if(sense ==3){
    	motor[motorB] = power;
  	}
  	else if(sense == 4){
  		motor[motorB] = -power;
  	}

    while(SensorValue(S1) != 0)
    {}

    motor[motorA] = motor[motorB] = motor[motorD] = 0;
}
