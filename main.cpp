#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

// Functions
  array <int,3> splitColor(string color){
      // Data types
        array <int,3> values;
        color.erase(color.begin() + 0, color.begin() + 4);
        color.pop_back();
        size_t pos = 0;
        string token;
        int k = 0;
      // Delete values until string is formated "xxx, xxx, xxx"
        while ((pos = color.find(", ")) != string::npos){
        token = color.substr(0, pos);
        values[k] = stoi(token);
        color.erase(0, pos + 2);
        k++; 
      }
      values[2] = stoi(color);
      return values;
  }
  string HexToColorName(string & color){
    // Data Types
      string line1, line2, display;
      int counter = 0;
      bool match;
      string colorNames = "htmlcolornames.txt";
      string hexNames ="hexcolornames.txt";
      fstream reader;
      char big[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
      char little[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    // Convert to all capital letters
      for(int i = 0; i < color.size(); i++){
        for(int j = 0; j < 6; j++){
          if(color[i] == little[j]){
          replace(color.begin(), color.end(), color[i], big[j]);
          }
        }
      }
    // Check if hexcode has a match in the file
      reader.open(hexNames, ios::in);
        if(reader.is_open()){  
          while(reader.eof() != true){
            getline(reader,line1);
            counter ++;
            if(line1 == color){ 
              match = true;
              break;
            } 
            else{
              match = false;
            }
          }
        }
      reader.close();
    // If there is a match find the corresponding color name   
      if(match == true){
        reader.open(colorNames, ios::in);
          if(reader.is_open()){
            for(int i = 0; i < counter; i++){
            getline(reader, line2);
            display = line2;
            }
          }
          reader.close();
      }
    // If no match display error message 
      else{
        display = "Does not have a vaid color name";
      }
    // Display the match or the error message
      color = display;  
      return color;
  }
  string HexToRgb(string & color){
    // Input Hex Color (either 3 or 6 digits) and returns the RGB color
    // Data types
      string rgb;
      int k = 0;
      int rgbArray[3] ={0, 0, 0};
      int size = color.size();
      int colorArray[size];
      int hex[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
      char big[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
      char little[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    // Convert Hex to Dec  
      for(int i = 1; i < size +1; i++){
        for(int j = 0; j < 16; j++){
          if(color[i] == big[j] || color[i] == little[j]){
            colorArray[i] = hex[j];
          }
        }
      }
    // Convert hex to color depending on the size of the color string
      if(size == 7){ 
        for(int i = 1; i < size +1; i+=2){
          rgbArray[k] = colorArray[i]*16 +colorArray[i+1];
          k++;
        }
      }
      else{
        for(int i = 1; i < size +1; i++){
          rgbArray[k] = colorArray[i]*16 +colorArray[i];
          k++;
        }
      }
    // display results "rgb(xxx, xxx, xxx)"
      rgb = "rgb(" + to_string(rgbArray[0]) + ", " + to_string(rgbArray[1]) + ", " + to_string(rgbArray[2]) + ")";
      return color = rgb;
  }
  string dominantColor(string color){
    // Data Types
      array <int, 3> RGB;
      string dominant;
    // Split up RGB values and Compare
    if(color[0] == '#'){
      HexToRgb(color);
    }
    RGB = splitColor(color);
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
  array <string,2> triadicColor(string color){
    // Data types
        array <string, 2> triColors;
        char temp[2];
    // Convert to triadic colors
      for(int i = 0; i < 2; i++){
        color.copy(temp, 2, 1);
        color.erase(1, 2);
        color.append(temp);
        triColors[i] = color;
      }
    return triColors;
  }
  string getColor(int location){
    // Data types
      ifstream hexNames("hexcolornames.txt");
      string color;

    for (int i = 1; i <= location; i++){
      getline(hexNames, color);
    }
    return color;
  }

int main(){
  // Data Types
    int numColor, count = 0, i = 0, j = 0;
    string fileName, name, line, format;
    fstream reader;
    srand(time(0)); 
    vector<int> randNum;
    vector <string> color;
    vector <string> colorGen;
    array <string, 2> triColors; 
  // User input file name and number of colors
    cout << "Name of file to save color palette: \n";
    getline(cin, name);
    fileName = name + ".css"; //Save name as css file type
    cout << "Number of colors needed \n";
    cin >> numColor;
  // Generate random numbers
    do{
      randNum.push_back (rand() % 142);
      color.push_back(getColor(randNum[i]));
      if(dominantColor(color[i]) != "Red" && dominantColor(color[i]) != "Green"){
        // Check for red and green
        colorGen.push_back(color[i]);
        count++;
        if(dominantColor(color[i]) != "Blended" && dominantColor(color[i]) != "Gray Scale"){
          // Triadic colors
          triColors = triadicColor(color[i]);
          colorGen.push_back(triColors[0]);
          colorGen.push_back(triColors[1]);
          count+=2;
        }
        // Check for duplicate colors
        for(int i = 0; i < colorGen.size(); i++){
          if(colorGen[i] == colorGen[j]){
            colorGen.erase(colorGen.begin()+i);
            count--;
          }
        }
      }
      i++;
    }while(count <= numColor);
 
  // Delete extra colors if needed
    int diff = count - numColor;
    if(diff > 0){
      for(int i = 0; i < diff; i++){
        colorGen.pop_back();
      }
    }
  // Format colors
    cout << "Select color format: (Hex, RGB, Name)" << endl;
    cin >> format;
    if(format == "RGB"){
      for(int i = 0; i < colorGen.size()+1; i++){
        HexToRgb(colorGen[i]);
      }
    }
    else if(format == "Name"){
      for(int i = 0; i < colorGen.size()+1; i++){
        HexToColorName(colorGen[i]);
      }
    }

  // Write colors to file
    reader.open(fileName, ios::out);
    if (reader.is_open()) {
		  cout << "File created successfully!\n";
      for (int i = 1; i <= numColor; i++){
        reader << colorGen[i] << endl;
      } 
    }
	  else{
		  cout << "File not created!";
	  }
    reader.close();

  // Output the colors in the file created
    reader.open(fileName, ios::in);
    if(reader.is_open()){   
      cout << fileName << " containing " << colorGen.size() << " colors" << endl;
      while(reader.eof() != true){
        getline(reader, line);
        cout << line << endl;
      }
    }     
return 0;
}