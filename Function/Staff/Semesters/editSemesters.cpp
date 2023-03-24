#include "../staff.h"

void editSemesters(string &existSemester, string &year) {
    cout << '\n';
    cout << "1. Create a new semester" << '\n';
    cout << "2. Delete a semester" << '\n';
    cout << "3. Back" << '\n';
    cout << "Your choose is: ";
    int n;
    cin >> n;
    if (n == 1) staff_create_a_new_semester(existSemester, year); // create a new semester
    else if (n == 2) staff_delete_a_semester(existSemester, year); // delete a semester
    else if (n == 3) tasksSemesters(existSemester, year); // turn back to the previous screen
}

void make_a_new_folder_semester(string s, string &existSemester, string &year) {
    const char* innerFolder = "DataSet/SchoolYear/";
    mkdir(innerFolder, 0777);
    string cmd = "mkdir -p ";
    cmd += innerFolder;
    cmd += year + "/";
    cmd += s;
    system(cmd.c_str());
}

void staff_create_a_new_semester(string &existSemester, string &year) {
    ofstream out;
    out.open(existSemester, ios_base::app);
    while (true) {
        cout << "Input a new semester: ";
        string s;
        cin >> s;
        out << '\n';
        out << s;
        make_a_new_folder_semester(s, existSemester, year);
        cout << "Type 'q' to quit or 'n' to continue input a new semester: ";
        string ans;
        cin >> ans;
        if (ans == "q") break;
    }
    editSemesters(existSemester, year); // turn back to the previous screen
}

void staff_delete_a_semester(string &existSemester, string &year) {
    // meow meow
}