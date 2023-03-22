#include "../staff.h"

void tasksSchoolYears() {
    string existSemester, year;
    ifstream in;
    in.open(taskOfSchoolYears);
    string s;
    while (getline(in , s)) {
        cout << s << '\n';
    }
    cout << "Your choose is : ";
    int ans;
    cin >> ans;
    if (ans == 1) viewSchoolYears();
    else if (ans == 2) editSchoolYears();
    else if (ans == 3) chooseSchoolYears(existSemester, year);
    // else if (ans == 4) quay lai giao dien chinh
}