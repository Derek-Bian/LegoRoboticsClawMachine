void limit(float &max_ad, float &max_b){
    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    bool exit = false;
    while(!exit){
        manual_reset_move(20);
        if(getButtonPress(buttonEnter)){
            while(!getButtonPress(buttonEnter)
            {}
            exit = true;
        }
    }

    max_ad = nMotorEncoder[motorA];
    max_b = nMotorEncoder[motorB];

    return_to_origin(20);
}
