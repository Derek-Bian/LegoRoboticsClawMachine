/*
Group 4-4 Yiting Han, Colin MacMillan, Jade Lee, Derek Bian

*/

/*
Timer 1 is the user inactivity timer
EV3:
S1: IR
S2: Touch
S3: Color

Motor A/D: Metal moving motors
Motor B: Cart motor
Motor C: Claw
*/

/*
To Do:
change move during game function to factor in get_colour() -> See line 86, 239
add Jade's function
*/

//global timeout variable
const int MAX_TIME = 3*60*1000;

void configureSensors(){
    SensorType[S1] = sensorEV3_IRSensor;
    wait1Msec(2000);
    SensorMode[S1] = modeEV3IR_Remote;
    wait1Msec(2000);
    SensorType[S2] = sensorEV3_Touch;
    wait1Msec(50);
    SensorType[S3] = sensorEV3_Color;
    wait1Msec(50);
    SensorMode[S3] = modeEV3Color_Color;
    wait1Msec(50);
}

int getcolour();

//true: closes the claw, false: opens the claw
void ClawGrab(bool close = true){
    if(close){
        motor[motorC] = -30;
    }
    else{
        motor[motorC] = 30;
    }

    time1[T2] = 0;
    while(time1[T2] < 10000)
    {}

    motor[motorC] = 0;
}

/*exit coding:
0 - Normal return (user stopped pressing button)
1 - Out of maze
2 - Out of bounds
*/
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

void manual_reset_move(int power = 10){
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

    while(SensorValue(S1) != 0)
    {}

	//counted as active until user releases button
	time1[T1] = 0;

    motor[motorA] = motor[motorB] = motor[motorD] = 0;
}

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

/*exit coding:
0 - normal
1 - timeout
*/
int limit(float &max_ad, float &max_b, int power = 10){

    bool at_origin = false;
    //allows user to move to origin until they hit the enter button
    displayString(5, "Press Enter at start...");
    while(!at_origin){
        manual_reset_move(power);

        //checks inactivity
        if(time1[T1] > MAX_TIME)
            return 1;

        //exits if the user presses enter
        if(getButtonPress(buttonEnter)){
            //waits for user to lift off of enter
            while(!getButtonPress(buttonEnter))
            {}
            at_origin = true;
        }

    }

    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    displayString(5, "Press Enter at end...");
    bool exit = false;
    while(!exit){
        manual_reset_move(power);

        //exits if the user presses enter
        if(getButtonPress(buttonEnter)){
            //waits for user to lift off of enter
            while(!getButtonPress(buttonEnter))
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

task main(){
    int power = 20;
    float max_ad = 0;
    float max_b = 0;
    bool exit_all = false;

    //false: claw open, true: claw closed
    bool claw_status = false;

    configureSensors();

    //limit will change max_ad and max_b values to max encoder values
    if(exit_all == false){
        if(!limit(max_ad, max_b)){
            //only here if timeout
            exit_all = true;
        }
        return_to_origin();
    }

    //start of game:
    while(exit_all == false){
        //checks if user wants to move, while the move function checks for timer and limits
        int movement_return = 0;
        movement_return = move_during_game(max_ad, max_b, power);
        if(movement_return){
            //exit code of 1 or 2
            if(movement_return == 1){
                displayString(5, "You took the goose out of the maze.");
                displayCenteredBigTextLine(8, "GAME OVER.");
            }
            else {
                //movment return is 2
                displayString(5, "You took the goose out of bounds.");
                displayCenteredBigTextLine(8, "GAME OVER.");
            }
            exit_all = true;
        }

        //checks for touch sensor
        if(SensorValue(S2)){
            //touch sensor is active, waits until user lets go
            while(SensorValue(S2))
            {}
            ClawGrab(!claw_status);
            claw_status = !claw_status;
        }

        //checks for victory
        //needs colin's function
        if(true){
            //user reached the end
            displayCenteredBigTextLine(5, "You won!");
            exit_all = true;
        }

    }

    //returning to start, then exiting
    return_to_origin();
    //releases goose if holding it
    if(claw_status){
        ClawGrab(false);
    }
}
