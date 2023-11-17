//power of 30 for 10s deemed sufficient

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