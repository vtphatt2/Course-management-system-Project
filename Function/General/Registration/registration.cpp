#include <iostream>
#include <fstream>
#include <cstring>
#include "registration.h"
#include "../../Staff/SchoolYears/schoolyears.h"
#include "../../Staff/Semesters/semesters.h"
#include "../viewProfile/viewProfile.h"
#include "../../Interface/interface.h"
using namespace std;

string typeOFUser;

void createTitle(string s){
    system("clear");
    int n = s.length();
    int i;
    for (i = 1 ; i <= n + 2 ; i++) cout << "=";
    cout << "\n " + s + "\n";
    for (i = 1 ; i <= n + 2 ; i++) cout << "=";
}

void login(string &idUser, bool &logingIn){
    createTitle("WELCOME TO MOODLE...! PLEASE LOGIN !");

    cout << "\n\n";
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
                cin.ignore(100, '\n');
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

void task(string &idUser, bool &logingIn){
    int choice;
    
    if (typeOFUser == "student"){
        interfaceOption(taskStudent, choice, "MENU");
    }
    else if (typeOFUser == "staff"){
        interfaceOption(taskStaff, choice, "MENU");
    }

    if (choice == 4) logOut(idUser, logingIn);
    else if (choice == 3) tasksSchoolYears();
    else if (choice == 2){
        cin.ignore(100, '\n');
        changePass(idUser);
    }
    else if (choice == 1) viewProfile(idUser);
}

void logOut(string &idUser, bool &logingIn){
    logingIn = false;
    int choice;
    interfaceOption(taskLogout, choice, "LOG OUT");
    if (choice == 1) {
        cin.ignore();
        login(idUser, logingIn);
    }
    else if (choice == 3) logingIn = true;
    else cout << "\nGOOD BYE ! SEE YOU NEXT TIME !";
}