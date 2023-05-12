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
#include "../staff.h"
#include "../Export/export.h"
#include "../Import/import.h"

void tasksCSVFile(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order) {
    createTitle("CSV File");
    cout << '\n';
    cout << "1. Import" << '\n';
    cout << "2. Export" << '\n';
    cout << "3. Back" << '\n';

    cout << "Your choice is : ";
    int choice;
    cin >> choice;
    if (choice == 1) import(existSemester, year, year_semester, semester, course, order);
    else if (choice == 2) menuCreateCSV(existSemester, year, year_semester, semester, course, order);
    else tasksStudentToCourse(existSemester, year, year_semester, semester, course, order);
}