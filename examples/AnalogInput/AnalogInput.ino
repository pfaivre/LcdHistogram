/**
 * LcdHistogram
 *
 * AnalogInput.ino
 * Pierre Faivre - oct. 2014
 * 
 * This program needs :
 *  - 1 LCD display
 *  - 1 potentiometer on analog 0 (A0)
 */

#include <LiquidCrystal.h>
#include <LcdHistogram.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int screenWidth = 16; // Screen width (in characters)
int screenHeight = 2; // Screen height (in characters)

int sensorPin = A0;   // The input pin for the potentiometer
int sensorValue = 0;  // Variable to store the value coming from the sensor

// Create a new histogram
LcdHistogram lhg(&lcd, 0, 0, screenWidth);

void setup() {
    lcd.begin(screenWidth, screenHeight);

    lhg.setMode(FIXED);     // Fixed mode
    lhg.setBounds(0, 1023); // set the drawing limits to the min and max analog values.
}

void loop() {
    // Get the current sensor value
    sensorValue = analogRead(sensorPin);  
    
    // Add it to the graph
    lhg.push(sensorValue);
    lhg.plot();
    
    // Print the number below the graph
    lcd.setCursor(screenWidth-4, 1);
    lcd.print(toString(sensorValue, 4));

    // And wait a moment
    delay(500);
}

/**
 * Convert a integer into a string with fixed number of characters, filled with spaces if needed.
 * Useful to print a variable number on a sceen.
 */
String toString(int number, int nbChar) {
    String s = (String)number;

    while (s.length() < nbChar) {
        s = " " + s;
    }

    return s;
}
