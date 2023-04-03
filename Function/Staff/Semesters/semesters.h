# pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>

using namespace std;

void tasksSemesters(string &existSemester, string &year);              // choose tasks
void semesterAndEdit(string &existSemester, string &year);             // view all semesters and edit
void editSemesters(string &existSemester, string &year);               // create or delete a new semester
void make_a_new_folder_semesters(string s, string &existSemester, string &year); // make new folder semester
void staff_create_a_new_semester(string &existSemester, string &year); // create a new semester
void staff_delete_a_semester(string &existSemester, string &year);     // delete a semester