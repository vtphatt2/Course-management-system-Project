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
    else if (n == 3) semesterAndEdit(existSemester, year); // turn back to the previous screen
}

void make_a_new_folder_semester(string s, string &existSemester, string &year) {
    const char* innerSemester = "DataSet/SchoolYear/";
    string semester = "DataSet/SchoolYear/" + year + "/" + s;

    mkdir(innerSemester, 0777);
    string cmd = "mkdir -p ";
    cmd += innerSemester + year + "/" + s;
    system(cmd.c_str()); // create a new Semester folder
    
    string cmd1 = cmd + "/1stYear";
    system(cmd1.c_str()); // create a new folder named 1st Year inside new Semester
    string innerCourse1 = semester + "/1stYear/existCourse.txt";
    ofstream myFile1(innerCourse1); // create a file named existCourse.txt inside folder 1st Year
    myFile1.close();

    string cmd2 = cmd + "/2ndYear";
    system(cmd2.c_str()); // create a new folder named 2nd Year inside new Semester
    string innerCourse2 = semester + "/2ndYear/existCourse.txt";
    ofstream myFile2(innerCourse2); // create a file named existCourse.txt inside folder 2rd Year
    myFile2.close();

    string cmd3 = cmd + "/3rdYear";
    system(cmd3.c_str()); // create a new folder named 3rd Year inside new Semester
    string innerCourse3 = semester + "/3rdYear/existCourse.txt";
    ofstream myFile3(innerCourse3); // create a file named existCourse.txt inside folder 3rd Year
    myFile3.close();

    string cmd4 = cmd + "/4stYear";
    system(cmd4.c_str()); // create a new folder named 4th Year inside new Semester
    string innerCourse4 = semester + "/4stYear/existCourse.txt";
    ofstream myFile4(innerCourse4); // create a file named existCourse.txt inside folder 4st Year
    myFile4.close();
}

void staff_create_a_new_semester(string &existSemester, string &year) {
    ofstream out;
    while (true) {  // bug k input vao file existSemester duoc
        out.open(existSemester, ios_base::app);
        cout << '\n';
        cout << "Input a new semester: ";
        string s;
        cin >> s;
        out << '\n';
        out << s;
        out.close();
        make_a_new_folder_semester(s, existSemester, year);
        
        out.open(existSemester, ios_base::app);
        cout << "Input start day: ";
        string start_day;
        cin >> start_day;
        out << " (" << start_day << " - ";
        cout << "Input end day: ";
        string end_day;
        cin >> end_day;
        out << end_day << ")";
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