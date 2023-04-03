#include "../staff.h"

void editCourse(string &existSemester, string &year, string &existCourse, string &year_semester) {
    cout << '\n';
    cout << "1. Update course information" << '\n';
    cout << "2. Delete a course" << '\n';
    cout << "3. Back" << '\n';
    cout << "Your choose is: ";
    int choose;
    cin >> choose;
    //if (choose == 1) updateCourse(existSemester, year, existCourse, year_semester); // go to update course function
    //else if (choose == 2) deleteCourse(existSemester, year, existCourse, year_semester); // delete a course
    if (choose == 3) courseAndEdit(existSemester, year, existCourse, year_semester); // back to the previous screen
}
void updateCourse(string &existSemester, string &year, string &existCourse, string &year_semester);
void deleteCourse(string &existSemester, string &year, string &existCourse, string &year_semester);    