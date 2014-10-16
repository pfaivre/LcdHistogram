/**
 * LcdHistogram
 *
 * LcdHistogram.cpp
 * Pierre Faivre - oct. 2014
 */

#include <Arduino.h>
#include "LcdHistogram.h"


/**
 * Creates a new histogram to show on the screen
 * @param lcd The screen to write on
 * @param posx Row on the screen of the first bar
 * @param posy Line on the screen of the first bar
 * @param length Length of the histogram in characters
 */
LcdHistogram::LcdHistogram(LiquidCrystal* lcd, int posx, int posy, int length) {
      _lcd = lcd;
      _posx = posx;
      _posy = posy;
      _length = length;
      
      _data = NULL;
      
      _init();
}

/**
 * Destroy the histogram and all the data added to it
 */
LcdHistogram::~LcdHistogram() {
    
}

/**
 * Prepare the screen to be used with LcdHistogram.
 * Note : this will use 8 of the custom characters
 */
void LcdHistogram::_init() {
    byte bar1[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11111
    };
    
    byte bar2[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11111,
        0b11111
    };
    
    byte bar3[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11111,
        0b11111,
        0b11111
    };
    
    byte bar4[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11111,
        0b11111,
        0b11111,
        0b11111
    };
    
    byte bar5[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111
    };
    
    byte bar6[8] = {
        0b00000,
        0b00000,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111
    };
    
    byte bar7[8] = {
        0b00000,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111
    };
    
    byte bar8[8] = {
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111
    };
    
    _lcd->createChar(1, bar1);
    _lcd->createChar(2, bar2);
    _lcd->createChar(3, bar3);
    _lcd->createChar(4, bar4);
    _lcd->createChar(5, bar5);
    _lcd->createChar(6, bar6);
    _lcd->createChar(7, bar7);
    _lcd->createChar(8, bar8);
}

/**
 * Add a value
 * @param number
 */
void LcdHistogram::push(float number) {
    
}

/**
 * Print the histogram to the screen
 */
void LcdHistogram::plot() {
    _lcd->setCursor(_posx, _posy);
  
    // Just for testing
    _lcd->print(" ");
    _lcd->write(1);
    _lcd->write(2);
    _lcd->write(3);
    _lcd->write(4);
    _lcd->write(5);
    _lcd->write(6);
    _lcd->write(7);
    _lcd->write(8);
}

