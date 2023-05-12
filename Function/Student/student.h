#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void viewCourses(string id, string &year, string &semester); //View a list of 1 student's courses
void chooseSchoolYear(string id); // choose schoolyear
void chooseSemester(string id, string &year); // choose semester
void viewMyScore(string id, string &year, string &semester); // view student's score 
void tasksStudents(string id, string &year, string &semester); // tasks student