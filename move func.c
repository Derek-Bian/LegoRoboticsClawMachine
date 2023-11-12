int move_during_game(int maxx = 0, int maxy = 0, int power = 10){
    switch(SensorValue(S1)){
        case 1:
            motor[motorA] = motor[motorD] = power;
        case 2:
            motor[motorA] = motor[motorD] = -power;
        case 3:
            motor[motorB] = power;
        case 4:
            motor[motorB] = -power;
    }

    while (SensorValue(S1) != 0 && nMotorEncoder(motorA) < maxy && nMotorEncoder(motorA) > 0 && nMotorEncoder(motorB) < maxx && nMotorEncoder(motorB) > 0)
    {}

    motor[motorA] = motor[motorB] = motor[motorB] = 0;
}
