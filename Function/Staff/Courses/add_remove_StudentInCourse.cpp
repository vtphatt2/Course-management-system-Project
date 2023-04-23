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

void tasksStudentToCourse(string &existSemester, string &semester, string &year,
string &year_semester, string &course, int &order) {
    createTitle("STUDENTS");

    cout << "\n* Tasks : ";
    cout << "\n1. Add a student to the course";
    cout << "\n2. Remove a student from the course";
    cout << "\n3. Back";
    cout << "\nYour choice is : ";
    int choice;
    cin >> choice;
    if (choice == 1) addStudentToCourse(existSemester, semester, year, year_semester, course, order);
    else if (choice == 2) removeStudentFromCourse(existSemester, semester, year, year_semester, course, order);
    else courseDetails(existSemester, year, year_semester, course, order, semester);
}

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
void removeStudentFromCourse(string &existSemester, string &semester, string &year,
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
    
    string listOfStudent = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + nameclass[cnt] + "/" + "listOfStudent.txt";
    string studentID;
    cout << "Enter Student ID to Remove: ";
    cin >> studentID;
    int i=1;
    string listStudent[100];
    ifstream list;
    list.open(listOfStudent);
    // read until end of file
    while (!list.eof()){
        getline(list, listStudent[i]);
        i++;
    }
    list.close();
    int index=0;
    for (int j=1; j<= i; j++){
        if (listStudent[j] == studentID){
            index=j;
            break;
        }
    }
    for (int j=index; j<i; j++){
        listStudent[j] = listStudent[j+1];
    }
    ofstream out;
    out.open(listOfStudent);
    for (int j=1; j<=i; j++){
        out << listStudent[j] << endl;
    }
    out.close();

    cin.ignore(1000, '\n');
    cout << "\nType any key to back: ";
    string t;
    getline(cin, t);
    courseDetails(existSemester, year, year_semester, course, order, semester);
}
