#include "courses.h"

void publicResult(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    string address = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/public.txt";
    ofstream fout;
    cout << "\nPublic result: \n";
    cout << "  1. Yes\n";
    cout << "  2. No\n";
    int type=0;
    while (type!=1 && type!=2){
        cout << "Your choice is : ";
        cin >> type;
    }
    fout.open(address);
    if (type==1) fout << "Yes";
    else fout << "No";
    cout << "\nSUCCESS !!!\n";
    fout.close();
    cout << "Type any key to back : ";
    string ans;
    cin >> ans;
    courseDetails(existSemester, year, year_semester, course, order, semester);
}