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
 * - FIXED    :  ▅█    (with setBounds(90, 100);)
 * - ABSOLUTE : ▆██▆▇
 * - DYNAMIC  : ▃▇█ ▅
 */
enum GraphMode {
    /**
     * Allow you to manually set the min and max values
     */
    FIXED,

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
        void setBounds(float min, float max);
        
    private:
        LiquidCrystal* _lcd; // LCD to print the graph
        int _posx; // Row on the screen of the first bar
        int _posy; // Line on the screen of the first bar
        int _length; // Length of the histogram in characters
        float* _data; // Numbers to plot

        GraphMode _mode; // Current mode of drawing (default : DYNAMIC)
        float _min; // Custom minimum value in fixed mode (default : 0)
        float _max; // Custom maximum value in fixed mode (default : 100)
        
        void _init();
};

#endif


