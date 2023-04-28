#include <iostream>
#include <cstdlib>
#include "../staff.h"

void editSchoolYears() {
    createTitle("EDIT");
    cout << '\n';
    cout << "* Tasks : " << '\n';
    cout << "1. Create a new school year" << '\n';
    cout << "2. Delete a school year" << '\n';
    cout << "3. Back" << '\n';
    cout << "Your choose is : ";
    int choose;
    cin >> choose;
    if (choose == 1) staff_create_a_new_school_year(); // create a new school year
    else if (choose == 2) staff_delete_a_school_year(); // delete a school year
    else if (choose == 3)  schoolYearAndEdit(); // back to the previous screen
}

void make_a_new_folder_school_year(string s) {
    const char* schoolYear = "DataSet/SchoolYear/";
    mkdir(schoolYear, 0777);
    string cmd = "mkdir -p ";
    cmd += schoolYear;
    cmd += s;
    system(cmd.c_str()); // create a new folder School Year
    string innerSemester = schoolYear + s + "/existSemester.txt";
    ofstream myFile(innerSemester); // make a file named existSemester.txt in school year
}

void staff_create_a_new_school_year() {
    ofstream out;
    cout << '\n';
    while (true) {
        out.open(schoolYears, ios_base::app);
        cout << "Input a new school year : ";
        string s;
        cin >> s;
        out << '\n';
        out << s;
        out.close();
        make_a_new_folder_school_year(s);
        string ans;
        do {
            cout << "Type 'q' to quit or 'n' to continue input a new semester : ";
            cin >> ans;
        } while (ans != "q" && ans != "n");
        if (ans == "q") break;
    }
    editSchoolYears(); // turn back to the previous screen
}

void staff_delete_a_school_year() {
    string existSchoolYear_tmp = "DataSet/SchoolYear/existSchoolYear.txt";
    const char* existSchoolYear = existSchoolYear_tmp.c_str();
    string s;
    
    ifstream in;
    in.open(existSchoolYear);
    int numberOfSchoolYear = 0;
    while (getline(in, s)) ++numberOfSchoolYear;
    in.close();

    string* arr = new string[numberOfSchoolYear];
    int t = 0;
    in.open(existSchoolYear);
    while (getline(in, s)) {
        // take the school year
        arr[t++] = s;
    }
    in.close();

    cout << "\n* Choose School Year that you want to remove :" << '\n';
    for (int i = 0; i < numberOfSchoolYear; ++i) cout << i + 1 << ". " << arr[i] << '\n';
    
    cout << "\nYour choice is : ";
    int choice;
    cin >> choice;

    string folder_path = "DataSet/SchoolYear/" + arr[choice-1];
    string command = "rm -rf \"" + folder_path + "\"";
    system(command.c_str());

    string test_tmp = "DataSet/SchoolYear/test.txt";
    const char* test = test_tmp.c_str();
    ofstream testFile(test);

    if (choice == numberOfSchoolYear) {
        for (int i = 0; i < numberOfSchoolYear - 2; ++i) {
            testFile << arr[i] << '\n';
        }
        testFile << arr[numberOfSchoolYear-2];
    }
    else {
        for (int i = 0; i < numberOfSchoolYear - 1; ++i) {
            if (i == choice - 1) continue;
            testFile << arr[i] << '\n';
        }
    testFile << arr[numberOfSchoolYear-1];
    }

    testFile.close();
    remove(existSchoolYear);
    rename(test, existSchoolYear);

    delete[] arr;

    cout << "\nREMOVE SUCCESSFULLY !";
    cout << "\nType any key to back : ";
    string ans;
    cin >> ans;
    schoolYearAndEdit();
}