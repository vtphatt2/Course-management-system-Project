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

void editCourse(string &existSemester, string &year, string &year_semester, string &semester) {
    createTitle("EDIT");
    cout << '\n';
    cout << "* Tasks : " << '\n';
    cout << "1. Add a course" << '\n';
    cout << "2. Delete a course" << '\n';
    cout << "3. Back" << '\n';

    cout << "Your choice is : ";
    int ans;
    cin >> ans;
    if (ans == 1) addCourse(existSemester, year, year_semester, semester);
    if (ans == 2) deleteCourse(existSemester, year, year_semester, semester);
    else courseAndEdit(existSemester, year, year_semester, semester);
}