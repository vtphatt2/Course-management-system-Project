#include "../staff.h"

void tasksSemesters(string &existSemester, string &year) {
    ifstream in;
    in.open(taskOfSemesters);
    string s;
    cout << '\n' << year << " !!!" << '\n';
    while (getline(in , s)) {
        cout << s << '\n';
    }
    cout << "Your choose is : ";
    int ans;
    cin >> ans;
    if (ans == 1) viewSemesters(existSemester, year);
    else if (ans == 2) editSemesters(existSemester, year);
    //else if (ans == 3) 
    else if (ans == 4) tasksSchoolYears();
}