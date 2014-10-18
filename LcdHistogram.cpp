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
    _mode = DYNAMIC;

    _data = (float*)malloc(sizeof(float) * _length);
    for (int i=0 ; i<_length ; i++) {
        _data[i] = 0;
    }

    _init();
}

/**
 * Destroy the histogram and all the data added to it
 */
LcdHistogram::~LcdHistogram() {
    free(_data);
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
    // TODO: use a "current number index" to get rid of this loop

    // Shift all the previous numbers
    for (int i=0 ; i<_length-1 ; i++) {
        _data[i] = _data[i+1];
    }
    // Add the new one at the end
    _data[_length-1] = number;
}

/**
 * Print the histogram to the screen
 */
void LcdHistogram::plot() {
    float min = _data[0];
    float max = _data[0];
    int bar;

    // First loop to get the min and the max values
    for (int i=0 ; i<_length ; i++) {
        if (_data[i] < min) {
            min = _data[i];
        }
        else if (_data[i] > max) {
            max = _data[i];
        }
    }

    if (_mode == ABSOLUTE) {
        min = 0;
    }

    _lcd->setCursor(_posx, _posy);
    // Second loop to print them on the screen
    for (int i=0 ; i<_length ; i++) {
        // Determinates the perfect bar (0 to 8) to match the number
        bar = round(((_data[i] - min) / (max - min)) * 8);

        if (bar == 0)
            _lcd->print(" ");
        else
            _lcd->write(bar);
    }
}

/**
 * Change the way the graph is being printed
 * @see GraphMode
 */
void LcdHistogram::setMode(GraphMode m) {
    _mode = m;
}

