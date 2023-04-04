#include "../staff.h"

void editCourse(string &existSemester, string &year, string &year_semester, string &semester) {
    createTitle("EDIT");
    cout << "\n1. Update course information";
    cout << "\n2. Delete a course";
    cout << "\n3. Back";
    cout << "\nYour choose is: ";
    int choose;
    cin >> choose;
    //if (choose == 1) updateCourse(existSemester, year, existCourse, year_semester, semester); // go to update course function
    //else if (choose == 2) deleteCourse(existSemester, year, existCourse, year_semester, semester); // delete a course
    //if (choose == 3) courseAndEdit(existSemester, year, existCourse, year_semester, semester); // back to the previous screen
}
void updateCourse(string &existSemester, string &year, string &year_semester, string &semester);
void deleteCourse(string &existSemester, string &year, string &year_semester, string &semester);    