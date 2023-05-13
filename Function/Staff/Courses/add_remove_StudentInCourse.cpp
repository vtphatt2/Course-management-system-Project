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

void tasksStudentToCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order) {
    createTitle("STUDENTS");

    cout << "\n* Tasks : ";
    cout << "\n1. Upload CSV file (Students enrolled course)";
    cout << "\n2. View list of students in a course";
    cout << "\n3. Add a student to the course";
    cout << "\n4. Remove a student from the course";
    cout << "\n5. Import/Export the scoreboard of a course";
    cout << "\n6. Back";
    cout << "\nYour choice is : ";
    int choice;
    cin >> choice;
    if (choice == 1) uploadCSV(existSemester, year, semester, year_semester, course, order);
    else if (choice == 2) viewListOfStudentsInCourse(existSemester, year, year_semester, semester, course, order);
    else if (choice == 3) addStudentToCourse(existSemester, year, year_semester, semester, course, order);
    else if (choice == 4) removeStudentFromCourse(existSemester, year, year_semester, semester, course, order);
    else if (choice == 5) tasksCSVFile(existSemester, year, year_semester, semester, course, order);
    else courseDetails(existSemester, year, year_semester, course, order, semester);
}
bool checkAvailableStudent(string &studentID){
    ifstream in;
    string folder="DataSet/InfoStudent/" + studentID;
    in.open(folder);
    if (in.fail()){
        cout << "Student ID is not available in the system. Please try again." << endl;
        return false;
    }
    in.close();
    return true;
}

void addStudentToCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    ifstream in;
    string nameclass[10];
    cout << "\nYou must make sure that the student has been registered in the system before adding to the course.";
    cout << "\nClass available : " << endl;
    string existClass = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" +"existClass.txt";
    in.open(existClass);
    int cnt=1;
    while (getline(in,nameclass[cnt])){
        cout << cnt << ". " << nameclass[cnt] << endl;
        cnt++;
    }
    in.close();
    cout << "Your choice is : ";
    cin >> cnt;
    
    ofstream out;
    string listOfStudent = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + nameclass[cnt] + "/" + "listOfStudent.txt";
    out.open(listOfStudent, ios::app);
    string studentID;
    cout << "Enter Student ID : ";
    cin >> studentID;
    if (checkAvailableStudent(studentID)){
    string listCoure="DataSet/InfoStudent/" + studentID + "/" + "courses.txt";
    string tmp="DataSet/InfoStudent/" + studentID + "/" + "tmp.txt";
    ofstream tempCourse;
    ifstream course_txt;
    course_txt.open(listCoure);
    tempCourse.open(tmp);
    string line;
    while (getline(course_txt, line)){
        tempCourse << line << endl;
        if (line == course){
            cout << "Student has already registered for this course. Please try again." << endl;
            tempCourse.close();
            course_txt.close();
            remove(tmp.c_str());
            out.close();
            cin.ignore(1000, '\n');
            cout << "\nType any key to back : ";
            string t;
            getline(cin, t);
            tasksStudentToCourse(existSemester, year, year_semester, semester, course, order);
            return;
        }
        if (line==semester) tempCourse << course << endl;
    }
    remove(listCoure.c_str());
    rename(tmp.c_str(), listCoure.c_str());
    tempCourse.close();
    course_txt.close();
    out << endl << studentID;
    cout << "Add Successfully !" << endl;
    }
    out.close();


    cin.ignore(1000, '\n');
    cout << "\nType any key to back : ";
    string t;
    getline(cin, t);
    tasksStudentToCourse(existSemester, year, year_semester, semester, course, order);

}
void removeStudentFromCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    ifstream in;
    string nameclass[10];
    cout << "Class available : " << endl;
    string existClass = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" +"existClass.txt";
    in.open(existClass);
    int cnt=1;
    while (getline(in,nameclass[cnt])){
        cout << cnt << ". " << nameclass[cnt] << endl;
        cnt++;
    }
    in.close();
    cout << "Your choice is : ";
    cin >> cnt;
    
    string listOfStudent = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + nameclass[cnt] + "/" + "listOfStudent.txt";
    string studentID;
    cout << "Enter Student ID to remove : ";
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
    if (index==0) cout << "NOT FOUND STUDENT ID !" << endl;
    else{
        cout << "Remove Successfully !";
        for (int j=index; j<i; j++){
            listStudent[j] = listStudent[j+1];
        }
        i--;
        ofstream out;
        out.open(listOfStudent);
        for (int j=1; j<i; j++){
            if (j == i - 1) out << listStudent[j];
            else out << listStudent[j] << endl;
        }
        cout << listStudent[i];
        out.close();
        // remove course in courses.txt
        string listCoure="DataSet/InfoStudent/" + studentID + "/" + "courses.txt";
        string tmp="DataSet/InfoStudent/" + studentID + "/" + "tmp.txt";
        ofstream tempCourse;
        ifstream course_txt;
        course_txt.open(listCoure);
        tempCourse.open(tmp);
        string line;
        while (getline(course_txt, line)){
            if (line != course) tempCourse << line << endl;
        }
        remove(listCoure.c_str());
        rename(tmp.c_str(), listCoure.c_str());
        tempCourse.close();
        course_txt.close();
    }
    
    cin.ignore(1000, '\n');
    cout << '\n';
    cout << "\nType any key to back : ";
    string t;
    getline(cin, t);
    tasksStudentToCourse(existSemester, year, year_semester, semester, course, order);
}
