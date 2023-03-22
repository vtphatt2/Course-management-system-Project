#include "../staff.h"

void viewSemesters(string &existSemester, string &year) {
    ifstream in;
    in.open(existSemester);
    string s;
    cout << '\n';
    cout << "LIST OF SEMESTERS !\n";
    while (getline(in, s)) {
        cout << s << '\n';
    }
    char ans;
    do {
        cout << "Type 'b' to back: ";
        cin >> ans;
    } while (ans != 'b');
    cout << '\n';
    tasksSemesters(existSemester, year); // back to the previous screen
}