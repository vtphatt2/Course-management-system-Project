#include <iostream>
#include "student.h"

void chooseSemester(string id, string &year) {
    string existSemester = "DataSet/SchoolYear/" + year + "/existSemester.txt";
    //open file named "existSemester.txt"
    ifstream in;
    in.open(existSemester);

    //get number of Semester in this file
    int numberOfSemester = 0;
    string s;
    while (getline(in, s)) ++numberOfSemester;
    in.close();

    cout << "\n";

    string* arr = new string[numberOfSemester];
    in.open(existSemester);
    int i = 0;
    while (!in.eof()) {
        // take the semesters
        in >> s;
        arr[i] = s;
        ++i;
        getline(in, s);
    }
    in.close();

    //print out to terminal
    cout << " * Choose semester and view its course :\n";
    for (i = 0; i < numberOfSemester; ++i) cout << i + 1 << ". " << arr[i] << "\n";

    cout << "\n * Tasks :";
    cout << "\n" << ++i << ". Back";
    cout << "\nYour choice is : ";
    
    int choose;
    cin >> choose;
    if (choose == numberOfSemester + 1) {
        delete[] arr;
        chooseSchoolYear(id);
    }
    else if (choose <= numberOfSemester && choose >= 1) {
        string semester = arr[choose-1];
        delete[] arr;
        tasksStudents(id, year, semester);
    }
}