# pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>

using namespace std;

void tasksCourses(string &existSemester, string &year, string &existCourse, string &year_semester); // choose tasks
void courseAndEdit(string &existSemester, string &year, string &existCourse, string &year_semester); // view all courses and edit
void courseDetails(string &existSemester, string &year, string &existCourse, string &year_semester); // view the details of course such as students and infomation
void informationCourse(string &existSemester, string &year, string &existCourse, string &year_semester); // view the information of this course
void editCourse(string &existSemester, string &year, string &existCourse, string &year_semester); // edit course
void updateCourse(string &existSemester, string &year, string &existCourse, string &year_semester); // update course
void deleteCourse(string &existSemester, string &year, string &existCourse, string &year_semester);      // delete a course