int move_during_game(int max_ad = 0, int max_b = 0, int power = 10){
    int sense = SensorValue(S1);
    if(sense == 1){
        motor[motorA] = motor[motorD] = power;
    }
    else if(sense == 2){
    	motor[motorA] = motor[motorD] = -power;
    }
    else if(sense == 3){
    	motor[motorB] = power;
    }
    else if(sense == 4){
        motor[motorB] = -power;
    }

    int exit_code = -1;

    while (exit_code == -1)
    {
        //checking user input
        if(SensorValue(S1) == 0)
            exit_code = 0;
        //PLEASE CHANGE THIS WHEN COLIN FINALLY DECIDES TO CONTRIBUTE TO THE ROBOT PROJECT THANK YOU 4EVA
        else if(false)
            exit_code = 1;
        else if(nMotorEncoder(motorA) < max_ad || nMotorEncoder(motorA) > 0 || nMotorEncoder(motorB) < max_b || nMotorEncoder(motorB) > 0)
            exit_code = 2;
    }

	//counted as active until user releases button
	time1[T1] = 0;

    motor[motorA] = motor[motorB] = motor[motorD] = 0;

    return exit_code;
}
