#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct UserProfile {
    string id;
    string fullName;
    string sex;
    string dateOfBirth;
    string phoneNumber;
};

UserProfile* readProfile(const string& userId); // Create a pointer to the profile
void displayProfile(UserProfile* profile); // Display the profile
void viewProfile(const string& userId); // Menu after view profile