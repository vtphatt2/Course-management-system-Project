#include "../staff.h"

void tasksCourses(string &existSemester, string &year, string &existCourse, string &year_semester) {
    createTitle("COURSES");
    cout << "\n1. Courses and Edit";
    cout << "\n2. Back";
    cout << "\nYour choice is : ";
    int choose;
    cin >> choose;
    if (choose == 1) courseAndEdit(existSemester, year, existCourse, year_semester);
    else semesterAndEdit(existSemester, year);
}

void courseAndEdit(string &existSemester, string &year, string &existCourse, string &year_semester) {
    //open file named "existCourse.txt"
    ifstream in;
    in.open(existCourse);

    //get number of courses in this file
    int numberOfCourse = 0;
    string s;
    while (getline(in, s)) ++numberOfCourse;
    in.close();

    cout << "\n";

    string* arr = new string[numberOfCourse];
    in.open(existCourse);
    int i = 0;
    while (getline(in, s)) {
        arr[i] = s;
        ++i;
    }
    in.close();

    //print out to terminal
    cout << " * Choose course and view its details :\n";
    for (i = 0; i < numberOfCourse; ++i) cout << i + 1 << ". " << arr[i] << "\n";

    cout << "\n * Tasks :";
    cout << "\n" << ++i << ". Edit";
    cout << "\n" << ++i << ". Back";
    cout << "\nYour choice is : ";
    
    int choose;
    cin >> choose;
    if (choose == numberOfCourse + 1) {
        delete[] arr;
        editCourse(existSemester, year, existCourse, year_semester); // go to edit function
    }
    else if (choose == numberOfCourse + 2) {
        delete[] arr;
        tasksCourses(existSemester, year, existCourse, year_semester); // back to tasks function of Course
    }
    else if (choose <= numberOfCourse && choose >= 1) {
        string course = arr[choose - 1];
        delete[] arr;
        courseDetails(existSemester, year, existCourse, year_semester);
    }
}

void courseDetails(string &existSemester, string &year, string &existCourse, string &year_semester) {
    createTitle("COURSES");
    cout << "\n1. Information";
    cout << "\n2. Students";
    cout << "\n3. Back";
    cout << "\nYour choice is : ";
    int choose;
    cin >> choose;
    if (choose == 1) informationCourse(existSemester, year, existCourse, year_semester);
    // more functions
}

void informationCourse(string &existSemester, string &year, string &existCourse, string &year_semester) {
    // meow meow
}