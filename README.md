Palette Generator using CSS Files

## Description

Provided a number of distinct colors needed (2 or more), create a palette of colors that avoid or minimize problematic color combinations

### v0.2 Updates

Added functions and logical system to eliminate red and green colors

### v1.0 Updates

*Coming soon*


## Developer

Noah McCracken

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Name of file to save color palette: 
Test01
Number of colors needed 
5
File created successfully!
//Clear Console
Test01.css containing 5 colors 
#.....
#.....
#.....
#.....
#.....
```

## C++ Guide

### Variables and Data Types

1. int numColor //User input of desired number of colors
2. string name //User input of desired name of file to save color palette
3. string fileName //Converts name into a CSS file
4. count //tracks number of colors generated
5. random color generator
6. string colorGen writes to file

### Console Input and Output

Inputs
* numColor //User input of desired number of colors
* name //User input of desired name of file to save color palette

Outputs
* user defined number of colors that are safe for color blind vision

### Decisions

write to file
if (reader.is_open()) {
  run loop to select user defined number of colors
}
else{
  display "File not created!
}

read from file
if (reader.is_open()) {
  loop to read each color from file
}

### Iteration

A for loop is used to select a user defined number of colors and writes colors to file
The for loop will continue to until the counter is equal to user defined number

for (int i = 1; i <= numColor; i++){
  reader << colorPalette[i] << endl;
}


A while loop is used to read and display colors from file
The while loop will continue to until it has read every line of the file 

while(reader.eof() != true){
  getline(reader, color);
  cout << color << endl;
}

### File Input and Output

Write a user select number of colors to file
for (int i = 1; i <= numColor; i++){
  reader << colorPalette[i] << endl;
}

Reads file and displays colors in file
while(reader.eof() != true){
  getline(reader, color);
  cout << color << endl;
}

### Arrays/Vectors

*Coming in version 0.2*

### Functions

array <int,3> splitColor(string color)
  splits RGB into Red, Green, and Blue values
  used in other functions
string HexToColorName(string & color)
  converts hex to color names or displays error messages
string HexToRgb(string & color)
  converts hex to RGB format
string dominantColor(string color)
  displays dominant color: Red, Green, Blue, Blended, Gray Scale
array <string,2> triadicColor(string color)
  takes hex color and creates triadic colors, unless the color is blended or greyscale
string getColor(int location)
  extract random color from hex names in file, displays color in hex format

### Classes

*Coming in version 1.0*
