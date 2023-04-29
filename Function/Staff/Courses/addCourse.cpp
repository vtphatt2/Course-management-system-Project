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

void make_a_new_folder_course(string &existSemester, string &year, string &year_semester, string &semester, string &courseID, string* classes, int &n) {
    string course_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + courseID;
    const char* course = course_tmp.c_str();
    mkdir(course, 0777);
    string cmd = "mkdir -p ";
    cmd += course;
    system(cmd.c_str()); // create a folder course ID
    
    string existClass = course_tmp + "/existClass.txt";
    ofstream out(existClass); //create a file named existClass
    out.close();

    for (int i = 0; i < n; ++i) {
        string classCourse_tmp = course_tmp + "/" + classes[i];
        const char* classCourse = classCourse_tmp.c_str();
        mkdir(classCourse, 0777);
        string cmd1 = "mkdir -p ";
        cmd1 += classCourse;
        system(cmd1.c_str()); // create a folder class

        ofstream myFile;    // input the class into existClass.txt
        myFile.open(existClass, ios_base::app);
        myFile << '\n' << classes[i];
        myFile.close();

        string listOfStudent = classCourse_tmp + "/listOfStudent.txt";
        ofstream createNew(listOfStudent);

        string scoreBoard = classCourse_tmp + "/scoreBoard.txt";
        ofstream createNew1(scoreBoard);
    }
}

void addCourse(string &existSemester, string &year, string &year_semester, string &semester) {
    ofstream out;
    string existCourse_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/existCourse.txt";
    const char* existCourse = existCourse_tmp.c_str();
    string courseInfo_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/courseInfo.txt";
    const char* courseInfo = courseInfo_tmp.c_str();
    cout << '\n';

    while (true) {
        cout << "Input Course ID : ";
        string courseID;
        cin >> courseID;

        cout << "Input Course Name : ";
        string courseName;
        cin.ignore(1000, '\n');
        getline(cin, courseName);

        cout << "How many classes you want : ";
        int n;
        cin >> n;
        string* classes = new string[n];
        for (int i = 0; i < n; ++i) {
            cout << "Input Class Name : ";
            cin >> classes[i];
        }

        cout << "How many teachers you want : ";
        int k;
        cin >> k;
        string* teachers = new string[k];
        for (int i = 0; i < k; ++i) {
            cout << "Input Teacher : ";
            cin.ignore(1000, '\n');
            getline(cin, teachers[i]);
        }

        cout << "Input Number of credit : ";
        string numOfCredit;
        cin >> numOfCredit;

        cout << "Input Maximum number of students in the course : ";
        string maxStudents;
        cin >> maxStudents;

        cout << "Input Day : ";
        string day;
        cin >> day;

        cout << "Which session you want ?" << '\n';
        cout << "1. S1 (7:30)" << '\n';
        cout << "2. S2 (9:30)" << '\n';
        cout << "3. S3 (13:30)" << '\n';
        cout << "4. S4 (15:30)" << '\n';
        cout << "Your choice is : ";
        int choice;
        cin >> choice;
        string session;
        if (choice == 1) session = "S1 (7:30)";
        else if (choice == 2) session = "S2 (9:30)";
        else if (choice == 3) session = "S3 (13:30)";
        else session = "S4 (15:30)";

        out.open(existCourse, ios_base::app);
        out << courseID << " - " << courseName << '\n';
        out.close();

        ifstream in;
        in.open(existCourse);
        int course = 0;
        string course_tmp;
        while (getline(in, course_tmp)) ++course;
        in.close();

        out.open(courseInfo, ios_base::app);
        out << course + 1 << '\n';
        out << "a" << '\n';
        out << "Course ID : " << courseID << '\n';
        out << "b" << '\n';
        out << "Course Name : " << courseName << '\n';
        out << "c" << '\n';
        out << "Class Name : ";
        for (int i = 0; i < n; ++i) out << classes[i] << " ";
        out << '\n';
        out << "d" << '\n';
        for (int i = 0; i < k; ++i) out << "Teacher : " << teachers[i] << '\n';
        out << "e" << '\n';
        out << "Number of credits : " << numOfCredit << '\n';
        out << "f" << '\n';
        out << "Maximum number of students in the course : " << maxStudents << '\n';
        out << "g" << '\n';
        out << "Day : " << day << '\n';
        out << "h" << '\n';
        out << "Session : " << session << '\n';
        out.close();

        make_a_new_folder_course(existSemester, year, year_semester, semester, courseID, classes, n);

        delete[] teachers;
        delete[] classes;

        string ans;
        do {
            cout << "Type 'q' to quit or 'n' to continue input a new course : ";
            cin >> ans;
        } while (ans != "q" && ans != "n");
        if (ans == "q") break;
    }
    tasksCourses(existSemester, year, year_semester, semester); // back to tasks function of Course
}