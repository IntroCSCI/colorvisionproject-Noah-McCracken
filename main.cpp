#include "color.h"
#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

int main(){
  // Data Types
    color palette;
    srand(time(0));
    int numColor, count = 0;
    string color, fileName, format;
    vector <string> possible;
    array <string, 2> triColors; 
  // User input file name and number of colors
    cout << "Name of file to save color palette: \n";
    getline(cin, fileName);
    fileName.append(".css"); //Save name as css file type
    cout << "Number of colors needed \n";
    cin >> numColor;
  // Generate random numbers
    for(int i = 0; count <= numColor; i++){
      color = palette.getHexColor();
      possible.push_back(color);
      // Check for Blended, Gray Scale, and Blue --> add to possible vecter
      if(palette.dominantColor(possible[i]) == "Blended" || palette.dominantColor(possible[i]) == "Gray Scale" || palette.dominantColor(possible[i]) == "Blue"){
        palette.add(possible[i]);
        count++;
      }
      // Check for red and green and NOT Blended --> Triadic Colors
      else{
        // Triadic colors
        if(palette.dominantColor(possible[i]) != "Blended"){
        triColors = palette.triadicColor(possible[i]);
        palette.add(triColors[0]);
        palette.add(triColors[1]);
        count+=2;
        }
        
      }
        // Check for duplicate colors
        count -= palette.checkDups();
      }
  // Delete extra colors if needed
    int diff = count - numColor;
    if(diff > 0){
      for(int i = 0; i < diff; i++){
        palette.remove();
      }
    }
  // Format colors
    cout << "Select color format: (Hex, RGB, HSL)" << endl;
    cin >> format;
    if(format == "RGB" || format == "rgb"){
      palette.HexToRgb();
    }
    else if(format == "HSL" || format == "hsl"){
      palette.toHSL();
    }  
  // Write colors to file
    palette.writeFile(fileName);
  // Output the colors in the file created
    palette.readFile(fileName); 
return 0;
}
