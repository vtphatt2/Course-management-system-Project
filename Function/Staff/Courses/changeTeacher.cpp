#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include <iomanip>
#include "courses.h"
#include "../SchoolYears/schoolyears.h"
#include "../Semesters/semesters.h"
#include "../../Interface/interface.h"

using namespace std;


void changeTeacher(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course) {

    string courseInfo_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/courseInfo.txt";
    const char* courseInfo = courseInfo_tmp.c_str();
    string test_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/test.txt";
    const char* test = test_tmp.c_str();

    ifstream in(courseInfo);
    ofstream testFile(test);

    string choice = to_string(order);
    string nextChoice = to_string(order + 1);
    string s;
    createTitle("CHANGE TEACHER");
    cout << '\n';
    int n = 0;
    while (!in.eof()) {
        getline(in, s);
        if (s == choice) {
            while (getline(in, s)) {
                if (s == "d") {
                    while (getline(in, s)) {
                        if (s == nextChoice || s == "e") break;
                        ++n;
                    }
                    break;
                }
                
            }
        }
    }

    in.close();
    in.open(courseInfo);

    string* arr = new string[n];
    int t = 0;
    while (!in.eof()) {
        getline(in, s);
        if (s == choice) {
            while (getline(in, s)) {
                if (s == "d") {
                    while (getline(in, s)) {
                        if (s == nextChoice || s == "e") break;
                        arr[t++] = s;
                        cout << t << ". " << s << '\n';
                    }
                    break;
                }
                
            }
        }
    }

    in.close();
    in.open(courseInfo);

    cout << "\nWhich teacher do you want to change ?";
    int ans;
    cout << "\nYour choice is : ";
    cin >> ans;
    cin.ignore(1000, '\n');
    cout << "\nNew teacher : ";
    string name;
    getline(cin, name);
    arr[ans-1] = "Teacher : " + name;
    t = 0;
    while (!in.eof()) {
        getline(in, s);
        if (s == choice) {
            testFile << s << '\n';
            while (getline(in, s)) {
                if (s == "d") {
                    testFile << s << '\n';
                    while (getline(in, s)) {
                        if (s == nextChoice || s == "e") break;
                        testFile << arr[t++] << '\n';
                    }
                    break;
                }
                testFile << s << '\n';
            }
        }
        testFile << s << '\n';
    }

    delete[] arr;

    in.close();
    testFile.close();

    std::remove(courseInfo);
    std::rename(test, courseInfo);

    informationCourse(existSemester, year, year_semester, course, order, semester);
}