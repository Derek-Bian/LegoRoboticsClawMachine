int limit(float &max_ad, float &max_b){
    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    bool exit = false;
    while(!exit){
        manual_reset_move(20);

        //exits if the user presses enter
        if(getButtonPress(buttonEnter)){
            while(!getButtonPress(buttonEnter)
            {}
            exit = true;
        }

        //exits if inactive
        if(time1[T1] > MAX_TIME)
            return 1;
    }

    max_ad = nMotorEncoder[motorA];
    max_b = nMotorEncoder[motorB];

    return_to_origin(20);
    return 0;
}
