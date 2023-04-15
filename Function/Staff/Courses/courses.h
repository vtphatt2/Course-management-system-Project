# pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include <iomanip>

using namespace std;

struct ScoreBoardEntry {
    int No;
    string StudentID;
    string StudentName;
    string ClassID;
    int TotalMark;
    int FinalMark;
    int MidtermMark;
    int OtherMark;
};

void tasksCourses(string &existSemester, string &year, string &year_semester, string &semester); // choose tasks
void courseAndEdit(string &existSemester, string &year, string &year_semester, string &semester); // view all courses and edit
void courseDetails(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester); // view the details of course such as students and infomation
void informationCourse(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester); // view the information of this coursevoid editCourse(string &existSemester, string &year, string &year_semester, string &semester); // edit course
void updateCourse(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // update course
void deleteCourse(string &existSemester, string &year, string &year_semester, string &semester);      // delete a course
void viewScoreBoardInCourse(string &existSemester, string &semester, string &year, string &year_semester, string &course, int &order); // view score board of a course
void changeID(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // Change the ID
void changeClassName(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // Change the class name
void changeCourseName(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // Change the course name
void changeDay(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change day
void changeNumCredits(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change number of credits
void changeSession(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change session
void changeTeacher(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change teacher
void changeMaximumStudents(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change maximum of students
void addStudentToCourse(string &existSemester, string &semester, string &year,string &year_semester, string &course, int &order); // add student to course