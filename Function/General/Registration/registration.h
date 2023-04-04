#pragma once
#include <iostream>
#include <ncurses.h>
const std::string accountFile = "DataSet/accountUser.txt";
const std::string taskStudent = "Function/General/Registration/taskOfStudent.txt";
const std::string taskStaff = "Function/General/Registration/taskOfStaff.txt";
const std::string taskLogout = "Function/General/Registration/taskLogout.txt";

void login(std::string &idUser, bool &logingIn); //login to Moodle
void task(std::string &idUser, bool &logingIn); //to show all the task that user can do
void logOut(std::string &idUser, bool &logingIn); //to log out
void changePass(std::string idUser); //to change password
void createTitle(std::string s); //clear the terminal and create Title