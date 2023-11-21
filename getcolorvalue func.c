int getColorValue() {
    // Read color sensor value
    int color = getColorName(colorSensor);

    // Check color and return corresponding output
    if (color == colorGreen) 
    {
    return 0;  // Green
    } 
    else if (color == colorBlue) 
    {
    return 1;  // Blue
    } 
    else if (color == colorWhite) 
    {
    return 2;  // Unknown
    } 
}
