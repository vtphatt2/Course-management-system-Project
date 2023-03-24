#include "../staff.h"

void editSchoolYears() {
    cout << '\n';
    cout << "1. Create a new school year" << '\n';
    cout << "2. Delete a school year" << '\n';
    cout << "3. Back" << '\n';
    cout << "Your choose is: ";
    int n;
    cin >> n;
    if (n == 1) staff_create_a_new_school_year(); // create a new school year
    else if (n == 2) staff_delete_a_school_year(); // delete a school year
    else if (n == 3)  tasksSchoolYears();
}

void make_a_new_folder_school_year(string s) {
    const char* innerFolder = "DataSet/SchoolYear/";
    mkdir(innerFolder, 0777);
    string cmd = "mkdir -p ";
    cmd += innerFolder;
    cmd += s;
    system(cmd.c_str());
}

void staff_create_a_new_school_year() {
    ofstream out;
    out.open(schoolYears, ios_base::app);
    cout << '\n';
    while (true) {
        cout << "Input a new school year: ";
        string s;
        cin >> s;
        out << '\n';
        out << s;
        make_a_new_folder_school_year(s);
        cout << "Type 'q' to quit or 'n' to continue input a new school year: ";
        char ans;
        cin >> ans;
        if (ans == 'q') break;
    }

    editSchoolYears(); // turn back to the previous screen
}

void staff_delete_a_school_year() {
    // meow meow
}