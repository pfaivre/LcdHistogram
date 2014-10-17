LcdHistogram
============

Still in developpement...

A simple LCD histogram library for Arduino inspired by [spark](https://github.com/holman/spark).

This library allows you to plot a set of data as a histogram on a LCD screen.

For example, to draw the following data set, {1, 12, 3, 9, 10, 8, 0, 5}, it will show something like `▁█▂▆▇▅ ▄`.

## How to use it

LcdHistogram is a class allowing to print a graph on the screen. The following methods are available to use it:

	LcdHistogram(LiquiCrystal* lcd, int posx, int posy, int length);
Creates a new histogram.
Parameters:
* `lcd` - An instance of LiquiCrystal previously created
* `posx` - Row on the screen of the first bar
* `posy` - Line on the screen of the first bar
* `length` - Length of the histogram in characters

	push(float number);
Add a number in the histogram.
Parameter:
* `number` - A single data to add at the end

	plot();
Print the graph.

Example:
	#include <LiquidCrystal.h>
	#include <LcdHistogram.h>

	void setup() {
		LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
	    lcd.begin(16, 2);
	    
	    // Create a new histogram
	    LcdHistogram lhg(&lcd, 0, 0, 8);
	    
	    // Add some data
	    lhg.push(1);
	    lhg.push(12);
	    lhg.push(3);
	    lhg.push(9);
	    lhg.push(10);
	    lhg.push(8);
	    lhg.push(0);
	    lhg.push(5);

	    // And display it
	    lhg.plot();
	}

	void loop() {
	}


## License
Copyright 2014 Pierre Faivre. This is free software, and may be redistributed under the terms specified in the LICENSE file.
