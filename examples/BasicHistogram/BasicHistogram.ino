/**
 * LcdHistogram
 *
 * LcdHistogram_example.ino
 * Pierre Faivre - oct. 2014
 * 
 * This program needs :
 *  - 1 LCD display
 */

#include <LiquidCrystal.h>
#include <LcdHistogram.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int screenWidth = 16; // Screen width (in characters)
int screenHeight = 2; // Screen height (in characters)

// Create a new histogram
LcdHistogram lhg(&lcd, 0, 0, screenWidth);

void setup() {
    lcd.begin(screenWidth, screenHeight);
}

void loop() {
    // Get a random number between 0 and 100
    float n = random(0, 100);
    
    // Add it to the graph
    lhg.push(n);
    lhg.plot();
    
    lcd.setCursor(screenWidth-4, 1);
    lcd.print(n);
    delay(750);
}
