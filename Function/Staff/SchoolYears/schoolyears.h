# pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>

using namespace std;

const string schoolYears = "DataSet/SchoolYear/existSchoolYear.txt";

void tasksSchoolYears();                // choose tasks
void viewSchoolYears();                 // view all school years
void editSchoolYears();                 // create or delete a new school year
void make_a_new_folder_school_year(string s);   // make new folder school year
void staff_create_a_new_school_year();  // create a new school year
void staff_delete_a_school_year();      // delete a school year
void chooseSchoolYears(string &existSemester, string &year);   // set the default of school year