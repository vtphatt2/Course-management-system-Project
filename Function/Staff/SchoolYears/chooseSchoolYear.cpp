#include "../staff.h"

void chooseSchoolYears(string &existSemester, string &year) {
    ifstream in;
    in.open(schoolYears);
    string s;
    while (getline(in , s)) {
        cout << s << '\n';
    }
    cout << "Which year you want to choose : ";
    cin >> year;
    existSemester = "DataSet/SchoolYear/" + year + "/existSemester.txt";
    tasksSemesters(existSemester, year);
}