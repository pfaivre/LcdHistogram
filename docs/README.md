How to use it
=============

## Class LcdHistogram

---
```c++
LcdHistogram(LiquidCrystal* lcd, int posx, int posy, int length);
```
Creates a new histogram.  
Parameters:
* `lcd` - An instance of LiquidCrystal previously created
* `posx` - Row on the screen of the first bar
* `posy` - Line on the screen of the first bar
* `length` - Length of the histogram in characters

---
```c++
void push(float number);
```
Adds a number in the histogram.  
Parameter:
* `number` - A single data to add at the end

---
```c++
void plot();
```
Print the graph.

---
```c++
void setBounds(float min, float max);
```
Set the minimum and maximum values in FIXED drawing mode..  
Parameters:
* `min` - Each number below this value will be printed with an empty bar
* `max` - Each number above this value will be printed with a full bar

---
```c++
void setMode(GraphMode m);
```
Change the way the graph is being printed.  
Parameter:
* `m` - New mode


## Enum GraphMode

Defines the drawing behavior
For example, for the numbers {80, 95, 100, 70, 90}, it will print :
```
FIXED    :  ▅█    (with setBounds(90, 100);)
ABSOLUTE : ▆██▆▇
DYNAMIC  : ▃▇█ ▅
```

---
```c++
FIXED
```
Allow you to manually set the min and max values

---
```c++
ABSOLUTE
```
Draw each bar considering 0 as minimum value.

---
```c++
DYNAMIC
```
Get the chart more readable by adjusting the length of the bars according to the minimum value.

