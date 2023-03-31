#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct UserProfile {
    string ID;
    string fullName;
    string sex;
    string dayOfBirth;
    string socialID;
};

UserProfile* readUserProfile(const string& filePath);

// Function to display user profile
void displayUserProfile(UserProfile* userProfile);
// Function to get the user profile based on the ID
void viewProfile(const string& idUser);

// In main.cpp just use the function "viewProfile"
// Example usage: 
/*
int main(){
    string IDuser;
    cout << "Enter your user ID: ";
    cin >> IDuser;
    viewProfile(IDuser);
    return 0;
}
*/