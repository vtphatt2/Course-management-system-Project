//View a list of 1 student's courses
#include "Header14.h"
void ViewClasses(string id){
    ifstream fin;
    ofstream fout;
    fin.open("DataSet/InfoStudent/"+ id + "/courses");
    string course;
    int n;
    fin >> n;
    fin.get();
    cout << "\t\t YOUR COURSES: \n";
    for (int i=1; i<=n; i++){
        getline(fin, course);
        cout << course << '\n';
    }
    cout << '\n';
    fin.close();
}
