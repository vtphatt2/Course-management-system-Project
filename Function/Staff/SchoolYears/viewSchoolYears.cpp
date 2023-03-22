#include "../staff.h"

void viewSchoolYears() {
    ifstream in;
    in.open(schoolYears);
    string s;
    cout << '\n';
    cout << "LIST OF SCHOOL YEARS !\n";
    while (getline(in, s)) {
        cout << s << '\n';
    }
    char ans;
    do {
        cout << "Type 'b' to back: ";
        cin >> ans;
    } while (ans != 'b');
    cout << '\n';
    tasksSchoolYears(); // back to the previous screen
}