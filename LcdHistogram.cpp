/**
 * LcdHistogram
 *
 * LcdHistogram.cpp
 * Pierre Faivre - oct. 2014 - dec. 2016
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
LcdHistogram::LcdHistogram(LiquidCrystal* lcd, byte posx, byte posy, byte length) {
    _lcd = lcd;
    _posx = posx;
    _posy = posy;
    _length = length;
    _mode = DYNAMIC;
    _min = 0;
    _max = 100;

    _data = (float*)malloc(sizeof(float) * _length);
    for (byte i=0 ; i<_length ; i++) {
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
    byte character[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11111
    };
    
    _lcd->createChar(1, character);

    for (byte i=0 ; i<7 ; i++) {
        character[6 - i] = 0b11111;
        _lcd->createChar(i + 2, character);
    }
}

/**
 * Add a value
 * @param number
 */
void LcdHistogram::push(float number) {
    // TODO: use a "current number index" to get rid of this loop

    // Shift all the previous numbers
    for (byte i=0 ; i<_length-1 ; i++) {
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
    byte bar;

    if (_mode == FIXED) {
        min = _min;
        max = _max;
    }
    else {
        // First loop to get the min and the max values
        for (byte i=0 ; i<_length ; i++) {
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
    }

    _lcd->setCursor(_posx, _posy);

    // Second loop to print them on the screen
    for (byte i=0 ; i<_length ; i++) {
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

/**
 * Set the minimum and maximum values in FIXED drawing mode.
 */
void LcdHistogram::setBounds(float min, float max) {
    if (min > max) {
        float tmp = min;
        min = max;
        max= tmp;
    }

    _min = min;
    _max = max;
}

