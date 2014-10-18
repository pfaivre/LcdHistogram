/**
 * LcdHistogram
 *
 * LcdHistogram.h
 * Pierre Faivre - oct. 2014
 */

#ifndef LcdHistogram_h
#define LcdHistogram_h

#include <LiquidCrystal.h>

/**
 * Defines the drawing behavior
 * For example, for the numbers {80, 95, 100, 70, 90}, it will print :
 * - ABSOLUTE : ▆██▆▇
 * - DYNAMIC  : ▃▇█ ▅
 */
enum GraphMode {
    /**
     * Draw each bar considering 0 as minimum value
     */
    ABSOLUTE,

    /**
     * Get the chart more readable by adjusting the length of the bars according to the minimum value
     */
    DYNAMIC
};

class LcdHistogram {
    public:
        LcdHistogram(LiquidCrystal* lcd, int posx, int posy, int length);
        ~LcdHistogram();
        
        void push(float number);
        void plot();
        void setMode(GraphMode m);
        
    private:
        LiquidCrystal* _lcd; // LCD to print the graph
        int _posx; // Row on the screen of the first bar
        int _posy; // Line on the screen of the first bar
        int _length; // Length of the histogram in characters
        float* _data; // Numbers to plot
        GraphMode _mode;
        
        void _init();
};

#endif


