#include <iostream>
#include <fstream>
#include <string>
#include "courses.h"
#include "../SchoolYears/schoolyears.h"
#include "../Semesters/semesters.h"
#include "../../Interface/interface.h"
using namespace std;
void viewClassAndStudentInThatClass(string &existSemester, string &year, string &year_semester, string &semester){
    cout << "Enter the year-student you want to view class: " << endl;
    cout << "Enter '1stYear' if you want to view class of first year student" << endl;
    cout << "Enter '2ndYear' if you want to view class of second year student" << endl;
    cout << "Enter '3rdYear' if you want to view class of third year student" << endl;
    cout << "Enter '4thYear' if you want to view class of fourth year student" << endl;
    cout << "Your choose: ";
    cin >> year_semester;
    string fileClass="DataSet/SchoolYear/"+year+"/"+semester+"/"+year_semester+"/"+"listOfClass.txt";
    ifstream fin;
    fin.open(fileClass);
    if(!fin.is_open()){
        cout << "Can't open file" << endl;
        return;
    }
    string line;
    cout << "List of class: " << endl;
    while(getline(fin,line)){
        cout << line << endl;
    }
    fin.close();


    cout << "View list of Student in class------- " << endl;
    cout << "Enter class: " << endl;
    string nameClass;
    cin >> nameClass;
    ifstream file;
    string filename = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/Students in classes/" + nameClass + ".txt";
    file.open(filename);
    while (!file.is_open()){
        cout << "The class you type doesn't exist" << endl;
        cout << "Please type again: " << endl;
        cin >> nameClass;
        string filename = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/Students in classes/" + nameClass + ".txt";
        file.open(filename);
    }
    cout << endl;
    cout << "List of student in class " << nameClass << ": " << endl << endl;
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
        cout << nameClass;
        cout << "|\n";
        count++;
        profile_file.close();
    }
    file.close();
    cout << "+----+------------+------------------+-------+\n";
    cout << endl;
    fin.close();
}