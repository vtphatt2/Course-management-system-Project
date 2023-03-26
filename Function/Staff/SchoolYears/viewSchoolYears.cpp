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
    string ans;
    do {
        cout << "Type 'b' to back: ";
        cin >> ans;
    } while (ans != "b");
    tasksSchoolYears(); // back to the previous screen
}