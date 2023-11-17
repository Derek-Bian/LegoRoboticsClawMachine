void return_to_origin(int power = 10){
    motor[motorA] = motor[motorD] = -power;
    while (nMotorEncoder[motorA] > 0)
    {}
    motor[motorA] = motor[motorD] = 0;

    motor[motorB] = -power;
    while (nMotorEncoder[motorB] > 0)
    {}
    motor[motorB] = 0;

}
