#include "staff.h"

const string taskOfSchoolYears = "Function/Task/taskOfSchoolYears.txt";

void staff_choose_tasks() {
    ifstream in;
    in.open(taskOfSchoolYears);
    string s;
    while (getline(in , s)) {
        cout << s << '\n';
    }
    cout << "Your choose is : ";
    int ans;
    cin >> ans;
    if (ans == 1) staff_view_all_school_years();
    else if (ans == 2) staff_edit();
    //else if (ans == 3) 
    // else if (ans == 4) do sth
}