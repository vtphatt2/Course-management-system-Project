#include "student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "../General/Registration/registration.h"
void printName(string s, string address){
    string addressTmp;
    ifstream fin;
    s = "Course ID: " + s;
    for (int i=1; i<=4; i++){
        if (i==1) addressTmp = address + "1stYear/courseInfo.txt";
        if (i==2) addressTmp = address + "2ndYear/courseInfo.txt";
        if (i==3) addressTmp = address + "3rdYear/courseInfo.txt";
        if (i==4) addressTmp = address + "4thYear/courseInfo.txt";
        fin.open(addressTmp);
        string str;
        while (getline(fin,str)){
            if (str == s){
                getline(fin,str);
                getline(fin,str);
                cout << str << '\n';
                return;
            }
        }
        fin.close();
    }
    cout << "Course Name: Could not find data\n";
}
void viewCourses(string id, string &year, string &semester){
    createTitle("MY COURSES");
    cout << '\n';
    string addressCourses = "DataSet/SchoolYear/" + year + "/" + semester + "/";
    string address = "DataSet/InfoStudent/" + id + "/courses.txt";
    string s;
    ifstream fin;
    fin.open(address);
    int flag=0,cnt=0;
    while (getline(fin,s)){
        if (flag==2){
            if (s=="") {
                flag=0;
                continue;
            } 
            cnt++;
            cout << cnt << ". " << s << '\n';
            printName(s,addressCourses);
            cout << '\n';
        }
        if (s==year) flag=1;
        if (flag==1 && s==semester) flag = 2;
    }
    fin.close();

    cout << "Type any key to back : ";
    string ans;
    cin >> ans;
    system("clear");
    chooseSemester(id, year);
}