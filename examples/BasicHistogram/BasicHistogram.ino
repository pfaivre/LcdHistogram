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


/***[ Parameters ]*******************************/

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int screenWidth = 16; // Screen width (in characters)
int screenHeight = 2; // Screen height (in characters)

/***[ End of parameters ]*************************/


void setup() {
    lcd.begin(screenWidth, screenHeight);
    
    LcdHistogram lhg(&lcd, 0, 0, 16);
    
    lhg.plot(); // not functionnal yet, it will just display some bars
}

void loop() {
    
}


