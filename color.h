#ifndef COLOR_H 
#define COLOR_H
#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::array;

class color{
  private:
    vector <string> colors;
    int RED, BLUE, GREEN;
    // Red, Blue, Green values used in other functions
      int red(string );
      int blue(string );
      int green(string );

  public:
    // Editing colors vector 
      void add(string );
      void remove( );
      int checkDups( );
      void writeFile(string );
      void readFile(string );
    // Defining Colors
      void HexToRgb( ); 
      void toHSL( );
      string getHexColor( );
      array <string,2> triadicColor(string );
      string dominantColor(string );
     
};

#endif  