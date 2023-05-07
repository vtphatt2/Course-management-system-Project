#include "courses.h"
void publicResult(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    string address = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/public.txt";
    ofstream fout;
    cout << "Public result: \n";
    cout << "  1.Yes\n";
    cout << "  2.No\n";
    int type=0;
    while (type!=1 && type!=2){
        cout << "Your choose (1/2) : ";
        cin >> type;
    }
    fout.open(address);
    if (type==1) fout << "Yes";
    else fout << "No";
    cout << "\nSUCCESS\n";
    fout.close();
}