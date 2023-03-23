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

UserProfile* readProfile(const string& userId);
void displayProfile(UserProfile* profile);
void viewProfile(const string& userId);