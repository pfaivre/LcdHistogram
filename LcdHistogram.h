/**
 * LcdHistogram
 *
 * LcdHistogram.h
 * Pierre Faivre - oct. 2014
 */

#ifndef LcdHistogram_h
#define LcdHistogram_h

#include <LiquidCrystal.h>

class LcdHistogram {
    public:
        LcdHistogram(LiquidCrystal* lcd, int posx, int posy, int length);
        ~LcdHistogram();
        
        void push(float number);
        void plot();
        
    private:
        LiquidCrystal* _lcd; // LCD to print the graph
        int _posx; // Row on the screen of the first bar
        int _posy; // Line on the screen of the first bar
        int _length; // Length of the histogram in characters
        float* _data; // Numbers to plot
        
        void _init();
};

#endif


