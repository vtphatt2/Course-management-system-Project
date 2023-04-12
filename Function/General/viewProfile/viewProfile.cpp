#include "viewProfile.h"
#include "../Registration/registration.h"
#include "../../Interface/interface.h"
#include "ncurses.h"

UserProfile* readUserProfile(const string& filePath) {
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        return nullptr;
    }

    UserProfile* userProfile = new UserProfile;

    getline(inFile, userProfile->ID);
    getline(inFile, userProfile->fullName);
    getline(inFile, userProfile->sex);
    getline(inFile, userProfile->dayOfBirth);
    getline(inFile, userProfile->socialID);

    inFile.close();
    return userProfile;
}

void displayUserProfile(UserProfile* userProfile, string idUser){
    initscr();
    keypad(stdscr, true);
    echo();

    int choice = 1;
    while (true){
        clear();
        for (int i = 1 ; i <= 9 ; i++) printw("=");
        printw("\n PROFILE\n");
        for (int i = 1 ; i <= 9 ; i++) printw("=");

        printw(("\nID: " + userProfile->ID + "\n").c_str());
        printw(("Full Name: " + userProfile->fullName + "\n").c_str());
        printw(("Sex: " + userProfile->sex + "\n").c_str());
        printw(("Day of Birth: " + userProfile->dayOfBirth + "\n").c_str());
        printw(("Social ID: " + userProfile->socialID + "\n").c_str());

        start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);

        if (choice == 1){
			attron(COLOR_PAIR(1));
            printw("\n1. Edit");
			attroff(COLOR_PAIR(1));
            printw("\n2. Back");
        }
        else{
            printw("\n1. Edit");
			attron(COLOR_PAIR(1));
            printw("\n2. Back");
			attroff(COLOR_PAIR(1));
        }

        int key = getch();
        switch (key){
            case KEY_UP :
                if (choice == 1) choice = 2;
                else choice = 1;
                break;
            case KEY_DOWN :
                if (choice == 1) choice = 2;
                else choice = 1;
                break;
            case 10 :
                break;
        }
        if (key == 10) break;

        refresh();
    }
    endwin();

    if (choice == 1){
        createTitle("CHANGE THE PROFILE");
        changeProfile(idUser);
    }
    else{
        cin.ignore();
    }
}

// Function to get the user profile based on the ID
void viewProfile(const string& idUser) {
    string basePath = "DataSet/";

    string infoStudentPath = basePath + "infoStudent/" + idUser + "/profile.txt";
    UserProfile* studentProfile = readUserProfile(infoStudentPath);
    if (studentProfile != nullptr) {
        displayUserProfile(studentProfile, idUser);
        delete studentProfile;
        return;
    }

    string infoStaffPath = basePath + "infoStaff/" + idUser + "/profile.txt";
    UserProfile* staffProfile = readUserProfile(infoStaffPath);
    if (staffProfile != nullptr) {
        displayUserProfile(staffProfile, idUser);
        delete staffProfile;
        return;
    }

    cout << "Error: User profile not found!" << endl;
}
