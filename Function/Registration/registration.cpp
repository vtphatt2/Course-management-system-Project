#include <iostream>
#include <fstream>
#include <cstring>
#include "registration.h"
#include "../Staff/SchoolYears/schoolyears.h"
#include "../Staff/Semesters/semesters.h"
using namespace std;

string typeOFUser;

const string accountFile = "DataSet/accountUser.txt";

void login(string &idUser, bool &logingIn){
    cout << "WELCOME TO MOODLE...! PLEASE LOGIN !" << endl << endl;

    string user, pass;

    labelLogin :
        cout << "Username : "; //user types here
        getline(cin, user);
        cout << "Password : ";
        getline(cin, pass);

        ifstream in; 
        in.open(accountFile); //read data from accountFile
        string checkUser;
        bool findUser = false;
        while (!findUser && in >> checkUser){ //check if username exists or not
            if (checkUser == user) findUser = true;
        }
        
        if (!findUser){
            cout << "Your username does not exist" << endl ;
            char choose;
            cout << "Try again (type any key and enter) or quit (type 'q' and enter) : ";
            cin >> choose;
            if (choose == 'q'){
                return ;
            }
            else{
                in.close();
                goto labelLogin;
            }
        }
        else{
            string checkPass; //check if password is right or wrong
            in >> checkPass >> typeOFUser >> idUser;
            while (checkPass != pass){
                cout << "Your password is not correct. Try again : ";
                cin >> pass;
            }
            logingIn = true;
            in.close();
            cout << "\nLOGIN SUCCESSFULLY !" << endl;
        }  
}

const string taskStudent = "Function/Registration/taskOfStudent.txt";
const string taskStaff = "Function/Registration/taskOfStaff.txt";

void task(string idUser, bool &logingIn){
    ifstream in;
    string s;
    cout << "\nHere is some tasks that you can do :\n";
    if (typeOFUser == "student"){
        in.open(taskStudent);
        while (getline(in, s)) cout << s << endl;
    }
    else if (typeOFUser == "staff"){
        in.open(taskStaff);
        while (getline(in, s)) cout << s << endl;
    }

    int choose;
    cout << "Your choose is : ";
    cin >> choose;
    if (choose == 4) logOut(logingIn);
    else if (choose == 3) tasksSchoolYears();
    else if (choose == 2) changePass(idUser);
}

void logOut(bool &logingIn){
    logingIn = false;
    cout << "\nGOOD BYE ! SEE YOU NEXT TIME !";
}