#include "student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "../General/Registration/registration.h"

void tasksStudents(string id, string &year, string &semester) {
    createTitle("TASKS");
    cout << '\n';
    cout << "1. View Courses" << '\n';
    cout << "2. View Score Board" << '\n';
    cout << "3. Back" << '\n';

    cout << "Your choice is : ";
    int choice;
    cin >> choice;
    if (choice == 1) viewCourses(id, year, semester);
    else if (choice == 2) viewMyScore(id, year, semester);
    else chooseSemester(id, year);
}