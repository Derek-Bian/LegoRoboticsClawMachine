int move_during_game(int &maxx, int &maxy){
    switch(SensorValue(S1)){
        case 1:
            while (nMotorEncoder(motorA) < maxy){
                motor[motorA] = motor[motorD] = power;
            }
            motor[motorA] = motor[motorD] = 0;
        case 2:
            while (nMotorEncoder(motorA) > 0){
                motor[motorA] = motor[motorD] = -power;
            }
            motor[motorA]= motor[motorD] = 0;
        case 3:
            while (nMotorEncoder(motorB) < maxx){
                motor[motorB] = power;
            }
            motor[motorB] = 0;
        case 4:
            while (nMotorEncoder(motorB) > 0){
                motor[motorB] = -power;
            }
            motor[motorB] = 0;
    }

    while (SensorValue(S1) != 0)
    {}

    motor[motorA] = motor[motorB] = motor[motorB] = 0;
}