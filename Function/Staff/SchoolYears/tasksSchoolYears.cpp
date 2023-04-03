#include "../staff.h"

void tasksSchoolYears(){
    createTitle("SCHOOLYEARS");
    cout << "\n1. Schoolyears and Edit";
    cout << "\n2. Back";
    cout << "\nYour choice is : ";
    int choose;
    cin >> choose;

    if (choose == 1) schoolYearAndEdit();
    // else back function
}

void schoolYearAndEdit() {
    //open file named "existSchoolYear.txt"
    ifstream in;
    in.open(existSchoolYear);

    //get number of SchoolYear in this file
    int numberOfSchoolYear = 0;
    string s;
    while (getline(in, s)) ++numberOfSchoolYear;
    in.close();

    cout << "\n";

    string* arr = new string[numberOfSchoolYear];
    in.open(existSchoolYear);
    int i = 0;
    while (getline(in, s)) {
        arr[i] = s;
        ++i;
    }
    in.close();

    //print out to terminal
    cout << " * Choose schoolyear and view its semesters :\n";
    for (i = 0; i < numberOfSchoolYear; ++i) cout << i + 1 << ". " << arr[i] << "\n";

    cout << "\n * Tasks :";
    cout << "\n" << ++i << ". Edit";
    cout << "\n" << ++i << ". Back";
    cout << "\nYour choice is : ";
    
    int choose;
    cin >> choose;
    if (choose == numberOfSchoolYear + 1) {
        delete[] arr;
        editSchoolYears(); // go to edit function
    }
    else if (choose == numberOfSchoolYear + 2) {
        delete[] arr;
        tasksSchoolYears(); // back to tasks function of School Year
    }
    else if (choose <= numberOfSchoolYear && choose >= 1) {
        string year = arr[choose - 1];
        delete[] arr;
        string existSemester = "DataSet/SchoolYear/" + year + "/existSemester.txt";
        tasksSemesters(existSemester, year); // go to tasks function of Semester
    }
}