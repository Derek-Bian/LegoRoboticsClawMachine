/*
Group 4-4 Yiting Han, Colin Macmillan, Jade Lee, Derek Bian


Motors that move the axis are A and D, the motor that moves the cart is B
this funcion moves the robot in the x-y axes without checking the motor encoder values
*/

void manual_reset_move(int power){
    switch(sensorValue(S1)){
        case 1:
            motor[motorA] = motor[motorD] = power;
        case 2:
            motor[motorA] = motor[motorD] = -power;
        case 3:
            motor[motorB] = power;
        case 4:
            motor[motorB] = -power;
    }

    while(sensorValue(S1) != 0)

    {}

    motor[motorA] = motor[motorD] = 0;
}