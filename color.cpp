#include "color.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <cmath>

using std::cout;
using std::endl;
using std::array;
using std::string;
using std::to_string;

// Red, Blue, Green values used in other functions
  int color::red(string inputColor){
    // Data types
      size_t pos;
      string red;
      int RED;
      int dec[2];
    // Red value if RGB format
    if(inputColor[0] != '#'){
      pos = inputColor.find_first_of(",");
      red = inputColor.substr(4);
      red.erase(pos-4);
      RED = stoi(red);
    }
    // Red value if hex format
    else{
      inputColor.erase(0, 1);
      for(int i = 0; i < 2; i++){
        if(inputColor[i] <= '9'){
          dec[i] = inputColor[i]-48;
        }
        else{
          dec[i] = (inputColor[i])-55;
        }
      }
      RED = 16*dec[0] + dec[1];
    }
    return RED;
  }
  int color::blue(string inputColor){
    // Data types
      size_t begin;
      size_t end;
      string blue;
      int BLUE;
      int dec[4];
    // Blue value if RGB format
    if(inputColor[0] != '#'){
      begin = inputColor.find_first_of(" ");
      end = inputColor.find_last_of(",");
      blue = inputColor.substr(begin);
      blue.erase(end-begin);
      BLUE = stoi(blue);
    }
    // Blue value if hex format
    else{
      inputColor.erase(0, 1);
      for(int i = 2; i < 4; i++){
        if(inputColor[i] <= '9'){
          dec[i] = inputColor[i]-48;
        }
        else{
          dec[i] = (inputColor[i])-55;
        }
      }
      BLUE = 16*dec[2] + dec[3];
    }
    return BLUE;
  }
  int color::green(string inputColor){
    // Data types
      size_t begin;
      size_t end;
      string green;
      int GREEN;
      int dec[6];
    // Green value if RGB format
    if(inputColor[0] != '#'){
      begin = inputColor.find_last_of(" ");
      end = inputColor.find(")");
      green = inputColor.substr(begin);
      green.erase(end-begin);
      GREEN = stoi(green);
    }
    // Green value if hex format
    else{
      inputColor.erase(0, 1);
      for(int i = 4; i < 6; i++){
        if(inputColor[i] <= '9'){
          dec[i] = inputColor[i]-48;
        }
        else{
          dec[i] = (inputColor[i])-55;
        }
      }
      GREEN = 16*dec[4] + dec[5];
    }
    return GREEN;
  };
// Editing colors vector  
  void color::add(string inputColor){
    colors.push_back(inputColor);
  }
  void color::remove( ){
    colors.pop_back();
  }
  int color::checkDups( ){
    // Data types
      int j = 0;
      int count = 0;
    // Check and delete Dups
      for(int i = 0; i < colors.size(); i++){
        if(colors[i] == colors[j]){
          colors.erase(colors.begin()+i);
          count++;
          }
        }
      return count;
  }
  void color::writeFile(string file){
    // Data types
      std::fstream reader;
    // Write to file  
      reader.open(file, std::ios::out);
        if (reader.is_open()) {
          cout << "File created successfully!\n";
          for (int i = 1; i <= colors.size(); i++){
            reader << colors[i] << endl;
          } 
        }
        else{
          cout << "File not created!";
        }
        reader.close();
  }
  void color::readFile(string file){
    // Data types
      std::fstream reader;
      string line;
    // Read from file
      reader.open(file, std::ios::in);
        if(reader.is_open()){ 
          cout << file << " containing " << colors.size() << " colors" << endl;
          while(reader.eof() != true){
            getline(reader, line);
            cout << line << endl;
          }
        } 
  }
  void color::HexToRgb( ){
    // display results "rgb(xxx, xxx, xxx)"
    for(int i = 0; i < colors.size()+1; i++){
      colors[i] = "rgb(" + to_string(red(colors[i])) + ", " + to_string(blue(colors[i])) + ", " + to_string(green(colors[i])) + ")";
    }
  }
  void color::toHSL( ){
    // data types
      float RGB[3];
      string hsl;
      int H,S,L;
      float max, min;
    // display results "hsl(xxx, xxx%, xxx%)"
      for(int i = 0; i < colors.size()+1; i++){  
      // RGB values
        RGB[0] = red(colors[i]);
        RGB[1] = blue(colors[i]);
        RGB[2] = green(colors[i]);
      // Max and Min
        for(int i = 0; i < 3; i++){
          RGB[i] = RGB[i]/255;
        }
        max=RGB[0];
        min=RGB[0];
        for(int i = 0; i < 3; i++){
          if(max < RGB[i]){
            max = RGB[i];
          }
          else if(min > RGB[i]){
            min = RGB[i];
          }
        }
      // Luminace calculations
        L = round((100*(max + min))/2);
      // Saturation calculations
        if(max != min){
          if(L <= 50){
            S = round(100*(max-min)/(max+min));
          }
          else{
            S = round(100*(max-min)/(2-max-min));
          }
        }
        else{
          S = 0;
        }
      // Hue calculations  
        if(RGB[0] == max){
          H = round(60*(RGB[1]-RGB[0])/(max-min));
        }
        else if(RGB[1] == max){
          H = round(60*(2+(RGB[2]-RGB[0])/(max-min)));
        }
        else if(RGB[2] == max){
          H = round(60*(4+(RGB[0]-RGB[1])/(max-min)));
        }
        if(H < 0){
          H += 360;
        }
      colors[i] = "hsl(" + to_string(H) + ", " + to_string(S) + "%, " +to_string(L) + "%)";  
      }
  }
// Defining Colors
  string color::getHexColor( ){
    // Data types
      // srand(time(0)); if function is in loop then
      // place before loop to generate different randon numbers
      int location = rand() % 142;
      std::ifstream reader("hexcolornames.txt");
      string color;
    // Get color from hexcolornames text file
      for (int i = 1; i <= location; i++){
        getline(reader, color);
      }
    return color;
  }
  array <string,2> color::triadicColor(string inputColor){
    // Data types
      array <string,2> triColors;
      string R, G, B;
    // If RGB format
      if(inputColor[0] != '#'){
        triColors[0] = "rgb(" + to_string(green(inputColor)) + ", " + to_string(red(inputColor)) + ", " + to_string(blue(inputColor)) + ")";
        triColors[1] = "rgb(" + to_string(blue(inputColor)) + ", " + to_string(green(inputColor)) + ", " + to_string(red(inputColor)) + ")";
      }
    // If Hex format
      else{
        R = inputColor.substr(1,2);
        B = inputColor.substr(3,2);
        G = inputColor.substr(5,2);
        triColors[0] = "#" + B + G + R;
        triColors[1] = "#" + G + R + B;
      }
    return triColors;
  }
  string color::dominantColor(string inputColor){
    // Data Types
      array <int, 3> RGB;
      string dominant;
    // Determine dominantColor;
      RGB[0] = red(inputColor);
      RGB[1] = blue(inputColor);
      RGB[2] = green(inputColor);
      if(RGB[0] > RGB[1] && RGB[0] > RGB[2]){
        dominant = "Red";
      }
      else if(RGB[1] > RGB[0] && RGB[1] > RGB[2]){
        dominant = "Green";
      }
      else if(RGB[2] > RGB[1] && RGB[2] > RGB[0]){
        dominant = "Blue";
      } 
      else if(RGB[0] == RGB[1] == RGB[2]){
        dominant = "Gray Scale";
      }
      else{
        dominant = "Blended";
      }
      return dominant;
  }

