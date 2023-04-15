#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include <iomanip>
#include "courses.h"
#include "../SchoolYears/schoolyears.h"
#include "../Semesters/semesters.h"
#include "../../Interface/interface.h"

using namespace std;
void addStudentToCourse(string &existSemester, string &semester, string &year,
string &year_semester, string &course, int &order){
    ifstream in;
    string nameclass[10];
    cout << "Class available: " << endl;
    string existClass = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" +"existClass.txt";
    in.open(existClass);
    int cnt=1;
    while (getline(in,nameclass[cnt])){
        cout << cnt << ". " << nameclass[cnt] << endl;
        cnt++;
    }
    in.close();
    cout << "Please choose class: ";
    cin >> cnt;
    
    ofstream out;
    string listOfStudent = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + nameclass[cnt] + "/" + "listOfStudent.txt";
    out.open(listOfStudent, ios::app);
    string studentID;
    cout << "Enter Student ID: ";
    cin >> studentID;
    out << studentID << endl;
    out.close();
    cin.ignore(1000, '\n');
    cout << "\nType any key to back: ";
    string t;
    getline(cin, t);
    courseDetails(existSemester, year, year_semester, course, order, semester);
}
