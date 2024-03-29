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

void tasksCourses(string &existSemester, string &year, string &year_semester, string &semester) {
    createTitle("COURSES");
    cout << "\n1. Courses and Edit";
   cout << "\n2. View Classes";
    cout << "\n3. Back";
    cout << "\nYour choice is : ";
    int choose;
    cin >> choose;
    if (choose == 1) courseAndEdit(existSemester, year, year_semester, semester);
    if (choose == 2) viewClassAndStudentInThatClass(existSemester, year, year_semester, semester);
    else semesterAndEdit(existSemester, year);
}

void courseAndEdit(string &existSemester, string &year, string &year_semester, string &semester) {
    string existCourse = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/existCourse.txt";

    //open file named "existCourse.txt"
    ifstream in;
    in.open(existCourse);

    //get number of courses in this file
    int numberOfCourse = 0;
    string s, t;
    while (getline(in, s)) ++numberOfCourse;
    in.close();

    cout << "\n";

    string* arr = new string[numberOfCourse];
    string* tmp = new string[numberOfCourse];
    in.open(existCourse);
    int i = 0;
    while (i < numberOfCourse) {
        // take the courses ID
        in >> s;
        arr[i] = s;
        ++i;
        getline(in, s);
    }
    in.close();

    in.open(existCourse);
    int n = 0;
    while (n < numberOfCourse) {
        // print out all courses
        getline(in, t);
        tmp[n] = t;
        ++n;
    }
    in.close();

    //print out to terminal
    cout << " * Choose course and view its details :\n";
    for (i = 0; i < numberOfCourse; ++i) cout << i + 1 << ". " << tmp[i] << "\n";

    cout << "\n * Tasks :";
    cout << "\n" << ++i << ". Edit";
    cout << "\n" << ++i << ". Back";
    cout << "\nYour choice is : ";
    
    int choose;
    cin >> choose;

    string course = arr[choose - 1];
    delete[] tmp;
    delete[] arr;

    if (choose == numberOfCourse + 2) {
        tasksCourses(existSemester, year, year_semester, semester); // back to tasks function of Course
    }

    else if (choose == numberOfCourse + 1) {
        editCourse(existSemester, year, year_semester, semester);
    }
    
    else if (choose <= numberOfCourse && choose >= 1) {
        int order = choose;
        courseDetails(existSemester, year, year_semester, course, order, semester);
    }
}

void courseDetails(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester) {
    createTitle(course);
    cout << "\n1. Information";
    cout << "\n2. Students";
    cout << "\n3. View score board in a course";
    cout << "\n4. Update a student's result";
    cout << "\n5. Public result";
    cout << "\n6. Back";
    cout << "\nYour choice is : ";
    int choice;
    cin >> choice;
    if (choice == 1) informationCourse(existSemester, year, year_semester, course, order, semester); // see the details of a course
    else if (choice == 2) tasksStudentToCourse(existSemester, year, year_semester, semester, course, order); // add or remove a student
    else if (choice == 3) viewScoreBoardInCourse(existSemester, year, year_semester, semester, course, order); // view score board
    else if (choice == 4) updateResult(existSemester, year, year_semester, semester, course, order); // update result
    else if (choice == 5) publicResult(existSemester, year, year_semester, semester, course, order); // public result
    else courseAndEdit(existSemester, year, year_semester, semester); // back
}