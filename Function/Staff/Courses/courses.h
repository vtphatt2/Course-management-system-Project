# pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include <iomanip>
struct ScoreBoardEntry {
    int No;
    std::string StudentID;
    std::string StudentName;
    std::string ClassID;
    int TotalMark;
    int FinalMark;
    int MidtermMark;
    int OtherMark;
};
using namespace std;

void tasksCourses(string &existSemester, string &year, string &year_semester, string &semester); // choose tasks
void courseAndEdit(string &existSemester, string &year, string &year_semester, string &semester); // view all courses and edit
void courseDetails(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester); // view the details of course such as students and infomation
void informationCourse(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester); // view the information of this course
void editCourse(string &existSemester, string &year, string &year_semester, string &semester); // edit course
void updateCourse(string &existSemester, string &year, string &year_semester, string &semester); // update course
void viewScoreBoardInCourse(string &semester, string &year, string &year_semester, string &course); // view score board of a course