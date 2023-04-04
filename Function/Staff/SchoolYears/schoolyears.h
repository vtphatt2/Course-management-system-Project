# pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include "../../General/Registration/registration.h"

using namespace std;

const string schoolYears = "DataSet/SchoolYear/existSchoolYear.txt";
const string path_TasksSchoolYears = "Function/Staff/SchoolYears/tasksSchoolYear.txt";

void tasksSchoolYears();                // choose tasks
void schoolYearAndEdit();               // view all school year and edit
void editSchoolYears();                 // create or delete a new school year
void make_a_new_folder_school_year(string s);   // make new folder school year
void staff_create_a_new_school_year();  // create a new school year
void staff_delete_a_school_year();      // delete a school year