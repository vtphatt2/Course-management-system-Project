#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ClassNode {
    string className;
    ClassNode* next;
};
void readClassesFromFile(string fileName);
void viewCourses(string id); //View a list of 1 student's courses