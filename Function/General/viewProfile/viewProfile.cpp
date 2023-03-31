#include "viewProfile.h"
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

// Function to display user profile
void displayUserProfile(UserProfile* userProfile) {
    if (userProfile == nullptr) {
        cout << "Error: User profile not found!" << endl;
        return;
    }

    cout << "\nID: " << userProfile->ID << endl;
    cout << "Full Name: " << userProfile->fullName << endl;
    cout << "Sex: " << userProfile->sex << endl;
    cout << "Day of Birth: " << userProfile->dayOfBirth << endl;
    cout << "Social ID: " << userProfile->socialID << endl;
}

// Ask user whether they want to change Profile or not
void askToChangeProfile(string idUser){
    int choose;
    cout << "\n1. Edit";
    cout << "\n2. Back";
    cout << "\nYour choose is : ";
    cin >> choose;
    if (choose == 1) changeProfile(idUser);
}

// Function to get the user profile based on the ID
void viewProfile(const string& idUser) {
    string basePath = "DataSet/";

    string infoStudentPath = basePath + "infoStudent/" + idUser + "/profile.txt";
    UserProfile* studentProfile = readUserProfile(infoStudentPath);
    if (studentProfile != nullptr) {
        displayUserProfile(studentProfile);
        delete studentProfile;
        askToChangeProfile(idUser);
        return;
    }

    string infoStaffPath = basePath + "infoStaff/" + idUser + "/profile.txt";
    UserProfile* staffProfile = readUserProfile(infoStaffPath);
    if (staffProfile != nullptr) {
        displayUserProfile(staffProfile);
        delete staffProfile;
        askToChangeProfile(idUser);
        return;
    }

    cout << "Error: User profile not found!" << endl;
}
