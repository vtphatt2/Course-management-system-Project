#include "../staff.h"

void editSchoolYears() {
    cout << '\n';
    cout << "1. Create a new school year" << '\n';
    cout << "2. Delete a school year" << '\n';
    cout << "3. Back" << '\n';
    cout << "Your choose is: ";
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
        cout << "Input a new school year: ";
        string s;
        cin >> s;
        out << '\n';
        out << s;
        out.close();
        make_a_new_folder_school_year(s);
        string ans;
        do {
            cout << "Type 'q' to quit or 'n' to continue input a new semester: ";
            cin >> ans;
        } while (ans != "q" && ans != "n");
        if (ans == "q") break;
    }
    editSchoolYears(); // turn back to the previous screen
}

void staff_delete_a_school_year() {
    // meow meow
}