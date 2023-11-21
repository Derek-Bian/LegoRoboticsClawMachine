int getColorValue() {
    // Read color sensor value
    int color = getColorName(colorSensor);

    // Check color and return corresponding output
    if (color == colorRed) 
    {
    return 0;  // Red
    } 
    else if (color == colorGreen) 
    {
    return 1;  // Green
    } 
    else if (color == colorWhite) 
    {
    return 2;  // White
    } 
    else 
    {
      return -1;  // Unknown color or no color detected
    }
}
