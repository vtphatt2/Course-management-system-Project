#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void viewCourses(string id, string &year, string &semester){
    string address = "DataSet/InfoStudent/" + id + "/courses.txt";
    string s;
    ifstream fin;
    fin.open(address);
    int flag=0;
    while (getline(fin,s)){
        if (flag==2){
            cout << s << '\n';
            if (s=="") flag=0; 
        }
        if (s==year) flag=1;
        if (flag==1 && s==semester) flag=2;
    }
    fin.close();
}