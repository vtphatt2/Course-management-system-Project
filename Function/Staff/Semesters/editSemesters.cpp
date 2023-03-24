#include "../staff.h"

void editSemesters(string &existSemester, string &year) {
    cout << '\n';
    cout << "1. Create a new semester" << '\n';
    cout << "2. Delete a semester" << '\n';
    cout << "3. Back" << '\n';
    cout << "Your choose is: ";
    int n;
    cin >> n;
    if (n == 1) staff_create_a_new_semester(existSemester, year); // create a new semester
    else if (n == 2) staff_delete_a_semester(existSemester, year); // delete a semester
    else if (n == 3) tasksSemesters(existSemester, year); // turn back to the previous screen
}

void make_a_new_folder_semester(string s, string &existSemester, string &year) {
    const char* innerFolder = "DataSet/SchoolYear/";
    mkdir(innerFolder, 0777);
    string cmd = "mkdir -p ";
    cmd += innerFolder;
    cmd += year + "/";
    cmd += s;
    system(cmd.c_str());
    string innerFile = innerFolder + year + "/" + s + "/existCourse.txt";
    ofstream myFile(innerFile); // make a file named existCourse.txt in default semester
}

void staff_create_a_new_semester(string &existSemester, string &year) {
    ofstream out;
    out.close();
    while (true) {  // bug k input vao file existSemester duoc
        out.open(existSemester, ios_base::app);
        cout << '\n';
        cout << "Input a new semester: ";
        string s;
        cin >> s;
        out << '\n';
        out << s;
        make_a_new_folder_semester(s, existSemester, year);
        out.close();
        
        const char* innerFolder = "DataSet/SchoolYear/";
        string innerFile = innerFolder + year + "/" + s + "/existCourse.txt";
        out.open(innerFile);
        cout << "Input start day: ";
        string start_day;
        cin >> start_day;
        out << start_day << '\n';
        cout << "Input end day: ";
        string end_day;
        cin >> end_day;
        out << end_day << '\n';
        out.close();

        string ans;
        do {
            cout << "Type 'q' to quit or 'n' to continue input a new semester: ";
            cin >> ans;
        } while (ans != "q" && ans != "n");
        if (ans == "q") break;
    }
    editSemesters(existSemester, year); // turn back to the previous screen
}

void staff_delete_a_semester(string &existSemester, string &year) {
    // meow meow
}