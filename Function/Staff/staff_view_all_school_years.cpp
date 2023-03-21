#include "staff.h"

void staff_view_all_school_years() {
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
    staff_choose_tasks(); // back to the previous screen
}