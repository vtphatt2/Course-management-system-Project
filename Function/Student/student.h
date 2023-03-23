#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ClassNode {
    string className;
    ClassNode* next;
};
void readClassesFromFile(string fileName);