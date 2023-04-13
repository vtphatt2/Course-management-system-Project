#include <iostream>
#include <cstring>
#include <fstream>
#include "import.h"

using namespace std;

string findClass(string s){
    string res = "";
    int l = s.length();
    int cnt=0;
    for (int i=0; i<l; i++){
        if (cnt == 3 && s[i] != ',') res = res + s[i];
        if (s[i] == ',') cnt++;
    }
    return res;
}
void import(){
    string fileCSV = "DataSet/listOfStudent.csv";
    ifstream fin(fileCSV);
    if (!fin.is_open()){
        cout << "Error: Can not open file CSV \n";
        return;
    }
    string s;
    string address = "DataSet/SchoolYear/";
    for (int i=1; i<=4; i++){
        getline(fin,s);
        address = address + s + "/";
    }
    string title;
    getline(fin, title);
    string line;
    string currentClass="-1";
    string curAddress;
    string Class;
    ofstream fout;
    while (getline(fin,line)){
        Class = findClass(line);
        if (Class != currentClass){
            fout.close();
            currentClass = Class;
            curAddress = address + Class + "/scoreBoard.txt";
            fout.open(curAddress);
            fout << title << '\n';
        }
        fout << line << '\n';
    }
    fin.close();
    fout.close();
}