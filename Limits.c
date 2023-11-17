void limit(float &max_ad, float &max_b){
    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    manual_reset_move(20);
    
    while(SensorValue(S1) != 9)
    {}

    max_ad = nMotorEncoder[motorA];
    max_b = nMotorEncoder[motorB];

    a_return(20);
}