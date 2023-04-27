#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "courses.h"
#include "../SchoolYears/schoolyears.h"
#include "../Semesters/semesters.h"
#include "../../Interface/interface.h"

using namespace std;

void viewClassAndStudentInThatClass(string &existSemester, string &year, string &year_semester, string &semester){
    string allCourse="DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + "existCourse.txt";
    ifstream fin;
    fin.open(allCourse);
    if(!fin.is_open()){
        cout << "Can't open file" << endl;
        return;
    }
    string nameCourse;
    createTitle("LIST OF CLASSESS");
    cout << '\n';
    while(getline(fin,nameCourse)) {
        istringstream ss(nameCourse);
        string onlyName;
        ss >> onlyName;
        string allClass="DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + onlyName + "/" + "existClass.txt";
        ifstream fin1;
        fin1.open(allClass);
        if(!fin1.is_open()){
            cout << "Can't open file" << endl;
            return;
        }
        string *nameClass = new string [10];
        int i=0;
        while (!fin1.eof()){
            fin1 >> nameClass[i];
            i++;
        }
        fin1.close();

        cout << "* " << onlyName << '\n';
        for (int j = 0; j <= i-1; j++) {
            cout << "   + " << nameClass[j] << '\n';
        }

        delete[] nameClass;
    }
    fin.close();


    cout << "\nView list of students in a class : ";
    cout << "\nEnter Course: ";
    cin >> nameCourse;
    cout << "Enter class: ";
    string name_class;
    cin >> name_class;
    ifstream file;
    string filename = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + nameCourse + "/" + name_class + "/listOfStudent.txt";
    file.open(filename);
    while (!file.is_open()){
        cout << "The class you type doesn't exist" << endl;
        cout << "Please type again: " << endl;
        cout << "Enter class: ";
        cin >> name_class;
        cout << "Enter course: ";
        cin >> nameCourse;
        filename =  "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + nameCourse + "/" + name_class + "/listOfStudent.txt";
        file.open(filename);
    }
    cout << endl;
    createTitle("STUDENTS IN " + name_class + " IN " + nameCourse);
    cout << '\n';
    // print header of the board.
    cout << "+----+------------+------------------+-------+\n";
    cout << "| No | Student ID |      Name        | Class |\n";
    cout << "+----+------------+------------------+-------+\n";
    string id;
    int count = 1;
    while (file >> id) {
        string profile_filename = "DataSet/InfoStudent/" + id + "/profile.txt";
        ifstream profile_file(profile_filename);
        string idStudent,name, gender, dob, phone;
        getline(profile_file, idStudent);
        getline(profile_file, name);
        getline(profile_file, gender);
        getline(profile_file, dob);
        getline(profile_file, phone);
        cout << "| ";
        cout.width(2);
        cout << count;
        cout << " | ";
        cout.width(10);
        cout << id;
        cout << " | ";
        cout.width(16);
        cout << name;
        cout << " | ";
        cout.width(5);
        cout << name_class;
        cout << "|\n";
        count++;
        profile_file.close();
    }
    file.close();
    cout << "+----+------------+------------------+-------+\n";
    cout << endl;
    fin.close();

    cout << "* Type any key to back : ";
    string ans;
    cin >> ans;
    tasksCourses(existSemester, year, year_semester, semester);
}