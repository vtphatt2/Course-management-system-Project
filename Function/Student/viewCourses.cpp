#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void viewCourses(string id){
    string address = "DataSet/InfoStudent/" + id + "/courses.txt";
    ifstream fin(address); 
    if (!fin.is_open()){
        cout << "ID does not exist! \n";
        return;
    }
    string course;
    cout << "\t\t YOUR COURSES: \n";
    while (getline(fin,course)) cout << course << '\n';
    cout << '\n';
    fin.close();
    cout << "\nType any key to back :";
    string ans;
    cin >> ans;
    
}