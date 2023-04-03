#include "../staff.h"

void tasksSemesters(string &existSemester, string &year) {
    createTitle("SEMESTERS");
    cout << "\n1. Semesters and Edit";
    cout << "\n2. Back";
    cout << "\nYour choice is : ";
    int choose;
    cin >> choose;

    if (choose == 1) semesterAndEdit(existSemester, year);
    else schoolYearAndEdit();
}

void semesterAndEdit(string &existSemester, string &year) {
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
    while (getline(in, s)) {
        arr[i] = s;
        ++i;
    }
    in.close();

    //print out to terminal
    cout << " * Choose semester and view its years :\n";
    for (i = 0; i < numberOfSemester; ++i) cout << i + 1 << ". " << arr[i] << "\n";

    cout << "\n * Tasks :";
    cout << "\n" << ++i << ". Edit";
    cout << "\n" << ++i << ". Back";
    cout << "\nYour choice is : ";
    
    int choose;
    cin >> choose;
    if (choose == numberOfSemester + 1) {
        delete[] arr;
        editSemesters(existSemester, year); // go to edit function
    }
    else if (choose == numberOfSemester + 2) {
        delete[] arr;
        tasksSemesters(existSemester, year); // back to tasks function of Semesters
    }
    else if (choose <= numberOfSemester && choose >= 1) {
        delete[] arr;
        string semester;
        if (choose == 1) semester = "SemesterI";
        else if (choose == 2) semester = "SemesterII";
        else semester = "SemesterIII";

        cout << "\nChoose the year and view its courses :";
        cout << "\n1. 1st Year";
        cout << "\n2. 2nd Year";
        cout << "\n3. 3rd Year";
        cout << "\n4. 4th Year";
        cout << '\n';

        cout << "Your choice is: ";
        int choice;
        cin >> choice;

        string year_semester;
        if (choice == 1) year_semester = "1stYear";
        else if (choice == 2) year_semester = "2ndYear";
        else if (choice == 3) year_semester = "3rdYear";
        else if (choice == 4) year_semester = "4thYear";

        string existCourse = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/existCourse.txt";
        tasksCourses(existSemester, year, existCourse, year_semester); // go to tasks function of Courses
    }
}