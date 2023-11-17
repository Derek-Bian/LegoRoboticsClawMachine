void a_return(int power){
    while (nMotorEncoder[motorA] > 0){
        motor[motorA] = motor[motorD] = -power;
    }
    motor[motorA] = motor[motorD] = 0;
    while (nMotorEncoder[motorB] > 0){
        motor[motorB] = -power;
    }
    motor[motorB] = 0;

}