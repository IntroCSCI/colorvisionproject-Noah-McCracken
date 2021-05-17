Palette Generator using CSS Files

## Description

Provided a number of distinct colors needed (2 or more), create a palette of colors that avoid or minimize problematic color combinations

### v0.3 Updates

Added classes to orangize functions and variables. Added functions and logical system to eliminate red and green colors which are problematic to people who are color blind. Similifed code to make reading it easier.

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
4
Select color format: (Hex, RGB, HSL)
RGB
File created successfully!
Test01.css containing 4 colors
rgb(211, 186, 85)
rgb(211, 211, 211)
rgb(135, 206, 235)
rgb(206, 235, 135)
```

## C++ Guide

### Variables and Data Types

1. class color palette; Holds different color related functions.
2. srand(time(0)); Creates a time that allows the function "getHexColor" to generate mulitple different random numbers.
3. int numColor; A user defined integer value of desired numbers.
4. int count = 0; An integer value that tracks the number of colors being generated and checks if it is equal to numColor.
5. string color; Creates a place holder for the randomly generated color from the getHexColor function.
6. string fileName; User input to name of file to save colors to.
7. string format; User input to define the type of color format.
8. vector <string> possible; Creates a vector to hold possible colors.
9. array <string, 2> triColors; Creates a place holder for the two colors generated using the triadicColor function.

### Console Input and Output

Inputs
* numColor; A user defined integer value of desired numbers.
* fileName; User input to name of file to save colors to.

Outputs
* Generated number of colors that minimizes problematic colors for colorblindness.

### Decisions

The provided color file "htmlcolornames.txt" that has a list of all colors that have a defined names and the corresponding hex codes can be found in the file "hexcolornames.txt"

Most problematic colors are found in red and green resulting in a yellow color. Therefore, the randomly generated colors are checked if they are red or green dominant before placing it into the color placeholder. 

Triadic colors combinations are colors evenly spaced on the color wheel. Such as:

Red, Yellow, Blue 

Green, Purple, Orange

Blue, Red, Yellow

Adding blended, gray scale, and blue colors is a fairly safe start.
Triadic colors of red and green are safe, however they should not be added to the possible vector.
Triadic colors of blue are not a safe combination.

### Iteration

for(int i = 0; count <= numColor; i++){

generates random color, checks if blended, gray scale, or blue then adds to possible vector.

Else checks that color is not blended and get corresponding triadic colors. 

Checks for duplicate colors and deletes them.

Adds possible colors to color vector.

}

### File Input and Output

Inputs:

numColor;
  user input of desired number of colors
fileName;
  user input of name of file to save colors

Outputs:

void readFile(string );
  reads user input file and displays colors

### Arrays/Vectors

vector <string> colors;
  variable in color.h
vector <string> possible;
  vector of possible colors
array <string, 2> triColors;
  vector of corresponding triadic colors

### Functions
Created in color.h file

// Used in other functions
int red(string );
  returns the red value of the color
int blue(string );
  returns the blue value of the color
int green(string );
  returns the green value of the color

// Editing color vector
void add(string );
  adds the color to colors vector
void remove( );
  removes last color of colors vector  
int checkDups( );
  returns number of duplicate colors in vector
void writeFile(string );
  writes colors to user file
void readFile(string );
  reads user input file and displays colors

// Defining colors
void HexToRgb( );
  converts hex format to rgb format
void toHSL( );
  converts either hex or rgb to hsl format
string getHexColor( );
  returns a random hex value
array <string, 2> triadicColor(string );
  returns the corresponding triadic colors
string dominantColor(string );
  returns dominant color

### Classes

color.h to oranize the class
color.cpp to define functions
all functions are created in color.cpp
private:

vector <string> colors;
holds colors in a vector and later writes to file
int RED, BLUE, GREEN;
integer value of the corresponding colors
// Used in other functions
int red(string ); blue(string ); green(string );

public:

// All other functions
// Defining colors
void HexToRgb( ); toHSL( );
  converts color format
string getHexColor( );
  returns a random hex value
array <string, 2> triadicColor(string );
  returns the corresponding triadic colors
string dominantColor(string );
  returns dominant color