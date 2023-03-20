#include "staff.h"

void staff_view_all_school_years() {
    ifstream in;
    in.open(schoolYears);
    string s;
    while (getline(s)) {
        cout << s << '\n';
    }
    cout << "Type 'b' to back: ";
    string s;
    cin >> s;
}