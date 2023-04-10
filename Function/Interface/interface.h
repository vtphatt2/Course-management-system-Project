#include <iostream>
#include <cstring>
using namespace std;

void createTitle(string s);
void interfaceOption(string path, int &choice, string Title);

void inputArt(string s[]); // Input Text(WELCOME TO MOODLE) from text file
void setColor(); // Just to set Color
void drawLogin();  // To print out WELCOME TO MOODLE and Please Login => Call drawLogin() when the program start