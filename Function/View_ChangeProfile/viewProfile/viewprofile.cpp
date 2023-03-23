#include "viewProfile.h" // Add direction if needed
UserProfile* readProfile(const string& userId) {
    string folder = userId + "/profile.txt";
    ifstream file(folder);
    if (!file.is_open()) {
        cout << "Error: Cannot open profile file." << endl;
        return nullptr;
    }

    UserProfile* profile = new UserProfile;
    getline(file, profile->id);
    getline(file, profile->fullName);
    getline(file, profile->sex);
    getline(file, profile->dateOfBirth);
    getline(file, profile->phoneNumber);

    file.close();
    return profile;
}

void displayProfile(UserProfile* profile) {
    if (profile != nullptr) {
        cout << "ID user: " << profile->id << endl;
        cout << "Full name: " << profile->fullName << endl;
        cout << "Sex: " << profile->sex << endl;
        cout << "Date of birth: " << profile->dateOfBirth << endl;
        cout << "Phone number: " << profile->phoneNumber << endl;
    }
}

void viewProfile(const string& userId) {
    UserProfile* profile = readProfile(userId);

    if (profile != nullptr) {
        displayProfile(profile);
        delete profile;
    }

    cout << "Press 1 to go back to the View Profile menu, 2 to exit: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        // Call the function that displays the View Profile menu
        // For example: viewProfileMenu();
    } else {
        cout << "Exiting..." << endl;
    }
}