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

void informationCourse(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester) {
    ifstream in;
    string courseInfo = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/courseInfo.txt";
    in.open(courseInfo);

    string choice = to_string(order);
    string nextChoice = to_string(order + 1);
    string s;

    while (!in.eof()) {
        getline(in, s);
        if (s == choice) {
            createTitle("INFORMATION");
            cout << '\n';
            while (getline(in, s)) {
                if (s == nextChoice) break;
                if (s >= "a" && s <= "z") getline(in, s);
                if (s == nextChoice) break;
                cout << s << '\n';
            }
            break;
        }
    }

    cout << "\n* Tasks : ";
    cout << "\n1. Update course information";
    cout << "\n2. Back";
    cout << "\nYour choice is: ";
    int ans;
    cin >> ans;
    if (ans == 1) updateCourse(existSemester, year, year_semester, semester, order, course);
    else courseDetails(existSemester, year, year_semester, course, order, semester);
}

void updateCourse(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course) {
    cout << "\nWhich information you want to change ?";
    cout << "\n1. Course ID";
    cout << "\n2. Course Name";
    cout << "\n3. Class name";
    cout << "\n4. Teacher";
    cout << "\n5. Number of credits";
    cout << "\n6. Maximum students";
    cout << "\n7. Day";
    cout << "\n8. Session";
    cout << "\n9. Back";

    cout << "\nYour choice is: ";
    int choose;
    cin >> choose;

    if (choose == 1) changeID(existSemester, year, year_semester, semester, order, course);
    else if (choose == 2) changeCourseName(existSemester, year, year_semester, semester, order, course);
    else if (choose == 3) changeClassName(existSemester, year, year_semester, semester, order, course);
    else if (choose == 4) changeTeacher(existSemester, year, year_semester, semester, order, course);
    else if (choose == 5) changeNumCredits(existSemester, year, year_semester, semester, order, course);
    else if (choose == 6) changeMaximumStudents(existSemester, year, year_semester, semester, order, course);
    else if (choose == 7) changeDay(existSemester, year, year_semester, semester, order, course);
    else if (choose == 8) changeSession(existSemester, year, year_semester, semester, order, course);
    else courseDetails(existSemester, year, year_semester, course, order, semester);
}