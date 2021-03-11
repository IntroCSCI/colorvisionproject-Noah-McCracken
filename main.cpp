//Noah McCracken
#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>

using namespace std;

const string CC = u8"\033[2J\033[1;1H";

int main()
{
  int numColor;
  string fileName, name, color;
  fstream reader;
  array<string, 10> colorPalette {"#000000","#FFFFFF",  "#E69F00", "#56B4E9", "#009E73", "#F0E442", "#0072B2", "#D55E00", "#CC79A7", "#007BFF"};
  
  // This part of the algorithm, that shuffls the order of colors in the color palette, and is adopted from
  //found at: https://www.cplusplus.com/reference/algorithm/shuffle/
  int num = chrono::system_clock::now().time_since_epoch().count();
  shuffle (colorPalette.begin(), colorPalette.end(), default_random_engine(num));
  
  cout << "Name of file to save color palette: \n";
  getline(cin, name);
  fileName = name + ".css"; //Save name as css file type

  cout << "Number of colors needed \n";
  cin >> numColor;
   
  //Write colors to file
  reader.open(fileName, ios::out);
  if (reader.is_open()) {
		cout << "File created successfully!\n";
    for (int i = 1; i <= numColor; i++){
      reader << colorPalette[i] << endl;
    } 
  }
	else {
		cout << "File not created!";
	}
  reader.close();

  //Output the colors in the file created
  reader.open(fileName, ios::in);
  if(reader.is_open()){  
    cout << CC; 
    cout << fileName << " containing " << numColor << " colors \n";
    while(reader.eof() != true){
      getline(reader, color);
      cout << color << endl;
    }
 } 
  
  
  return 0;
}
