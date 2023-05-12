#include "student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "../General/Registration/registration.h"

string findIDStudent(string s){
    string res = "";
    int l = s.length();
    int cnt=0;
    for (int i=0; i<l; i++){
        if (cnt == 1 && s[i] != ',') res = res + s[i];
        if (s[i] == ',') cnt++;
    }
    return res;
};

void printScore(string s){
    string total="", fin="", mid="", other="";
    int l = s.length();
    int cnt=0;
    for (int i=0; i<l; i++){
        if (cnt==4 && s[i] !=',') total = total + s[i];
        if (cnt==5 && s[i] !=',') fin = fin + s[i];
        if (cnt==6 && s[i] !=',') mid = mid + s[i];
        if (cnt==7 && s[i] !=',') other = other + s[i];
        if (s[i] == ',') cnt++;
    }
    cout << "Midterm Mark : " << mid << '\n';
    cout << "Final Mark : " << fin << '\n';
    cout << "Other Mark : " << other << '\n';
    cout << "Total Marl : " << total << '\n';
}

void viewScore(string id, string& year, string& semester, string course){
    string address = "DataSet/SchoolYear/" + year + "/" + semester + "/";
    string addressTmp;
    ifstream fin;
    for (int i=1; i<=4; i++){
        if (i==1) addressTmp = address + "1stYear/" + course;
        if (i==2) addressTmp = address + "2ndYear/"+ course;
        if (i==3) addressTmp = address + "3rdYear/" + course;
        if (i==4) addressTmp = address + "4thYear/" + course;
        fin.open(addressTmp + "/existClass.txt");
        if (!fin.is_open()) continue;
        ifstream in;
        in.open(addressTmp + "/public.txt");
        string pub;
        if (in.is_open()){
            in >> pub;
            if (pub == "No") {
                cout << "NON-PUBLIC\n";
                continue;
            }
        }
        in.close();
        string Class;
        int flag=0;
        while (getline(fin,Class)){
            string addressClass = addressTmp + "/" + Class + "/scoreBoard.txt";
            ifstream fin2;
            fin2.open(addressClass);
            string line;
            getline(fin2,line);
            while (getline(fin2,line)){
                if (findIDStudent(line) == id) {
                    createTitle(course);
                    cout << '\n';
                    printScore(line);
                    flag=1; 
                    break;
                }
            }
            fin2.close();
            if (flag==1) break;
        }
        fin.close();
    }
    string ans;
    cout << "\nType any key to back : ";
    cin >> ans;
    viewMyScore(id, year, semester);
}

void printGPA(string id, string year, string semester){
    string address = "DataSet/SchoolYear/" + year + "/" + semester + "/";
    string addressTmp;
    for (int i=1; i<=4; i++){
        if (i==1) addressTmp = address + "1stYear/gpaScore.txt";
        if (i==2) addressTmp = address + "2ndYear/gpaScore.txt";
        if (i==3) addressTmp = address + "3rdYear/gpaScore.txt";
        if (i==4) addressTmp = address + "4thYear/gpaScore.txt";
        ifstream fin;
        fin.open(addressTmp);
        string str;
        while (getline(fin,str)){
            if (str == id){
                getline(fin,str);
                cout << "Your GPA : " << str << "\n\n";
                return;
            }
        }
    }
}

void viewMyScore(string id, string &year, string &semester){
    string addressCourse = "DataSet/InfoStudent/" + id + "/courses.txt";
    string s;
    ifstream fin;
    fin.open(addressCourse);
    if (!fin.is_open()) cout << "Not exist\n";
    string* courses;
    int flag=0,cnt=0;
    while (getline(fin,s)){
        if (flag==2){
            if (s=="") {
                flag=0;
                continue;
            }
            cnt++;
        }
        if (s==year) flag=1;
        if (flag==1 && s==semester) flag=2;   
    }
    fin.close();
    courses = new string[cnt+1];
    fin.open(addressCourse);   
    flag=0,cnt=0;
    while (getline(fin,s)){
        if (flag==2){
            if (s=="") {
                flag=0;
                continue;
            } 
            cnt++;
            courses[cnt] = s;
        }
        if (s==year) flag=1;
        if (flag==1 && s==semester) flag=2;
    }
    fin.close();
    int type = -1;
    createTitle("YOUR COURSES");
    cout << '\n';
    for (int i=1; i<=cnt; i++) cout << " "<< i << ". " << courses[i] << '\n';
    printGPA(id, year, semester);
    cout << ' ' << cnt + 1 << '.' << " Back" << '\n';
    while (type<=0 || type>cnt + 1) {
        cout << "Your choose is : ";
        cin >> type;
    }
    string studentCourse = courses[type];
    delete[] courses;
    if (type == cnt + 1) tasksStudents(id, year, semester);
    else viewScore(id, year, semester, studentCourse);
}