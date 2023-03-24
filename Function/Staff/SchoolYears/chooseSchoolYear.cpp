#include "../staff.h"

void chooseSchoolYears(string &existSemester, string &year) {
    ifstream in;
    in.open(schoolYears);
    string s;
    cout << '\n';
    while (getline(in, s)) {
        cout << s << '\n';
    }
    in.close();
    in.open(schoolYears);
    cout << "Which year you want to choose : ";
    cin >> year;
    while (getline(in, s)) {
        if (s == year) break;
    }
    in.close();
    in.open(schoolYears);
    while (year != s) {
        cout << '\n';
        cout << "There are not any year you want!\n";
        cout << "Please choose again: ";
        cin >> year;
        while (getline(in, s)) if (s == year) break;
        in.close();
        in.open(schoolYears);
    }
    existSemester = "DataSet/SchoolYear/" + year + "/existSemester.txt";
    tasksSemesters(existSemester, year);
}