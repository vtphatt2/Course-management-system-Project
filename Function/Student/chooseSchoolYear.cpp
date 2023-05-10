#include <iostream>
#include "student.h"

void chooseSchoolYears(string id) {
    const string existSchoolYear = "DataSet/SchoolYear/existSchoolYear.txt";
    system("clear");

    ifstream in;
    in.open(existSchoolYear);

    //get number of SchoolYear in this file
    int numberOfSchoolYear = 0;
    string s;
    while (getline(in, s)) ++numberOfSchoolYear;
    in.close();

    string* arr = new string[numberOfSchoolYear];
    in.open(existSchoolYear);
    int i = 0;
    while (getline(in, s)) {
        arr[i] = s;
        ++i;
    }
    in.close();

    cout << "\n* Choose schoolyear and view its semester : " << '\n';
    for (int i = 0; i < numberOfSchoolYear; ++i) cout << i + 1 << ". " << arr[i] << '\n';
    cout << "* Tasks : ";
    cout << numberOfSchoolYear + 1 << ". Back" << '\n';

    cout << "\nYour choice is : ";
    int choice;
    cin >> choice;

    if (choice == numberOfSchoolYear + 1) {
        delete[] arr;
        // meow meow
    }
    else if (choice <= numberOfSchoolYear && choice >= 1) {
        string year = arr[choice - 1];
        delete[] arr;
        chooseSemester(id, year);
    }
}