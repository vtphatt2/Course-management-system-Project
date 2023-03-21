# pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include "../Staff/staff.h"

using namespace std;

const string schoolYears = "DataSet/SchoolYear/existSchoolYear.txt";

void staff_choose_tasks(); // choose tasks
void staff_view_all_school_years(); // view all school years
void staff_edit(); // create or delete a new school year
void make_a_new_folder_school_year(); // make new folder school year
void staff_create_a_new_school_year(); // create a new school year
void staff_delete_a_school_year(); // delete a school year