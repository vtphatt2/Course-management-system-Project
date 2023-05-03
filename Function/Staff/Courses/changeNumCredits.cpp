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

void changeNumCredits(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course) {

    string courseInfo_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/courseInfo.txt";
    const char* courseInfo = courseInfo_tmp.c_str();
    string test_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/test.txt";
    const char* test = test_tmp.c_str();

    ifstream in(courseInfo);
    ofstream testFile(test);

    string choice = to_string(order);
    string nextChoice = to_string(order + 1);
    string s;
    createTitle("CHANGE NUMBER OF CREDITS");

    cout << '\n';
    while (!in.eof()) {
        getline(in, s);
        if (s == choice) {
            while (getline(in, s)) {
                if (s == "e") {
                    while (getline(in, s)) {
                        if (s == nextChoice || s == "f") break;
                        cout << "Old " << s << '\n';
                    }
                    break;
                }
                
            }
        }
    }

    in.close();
    in.open(courseInfo);

    cout << "\nNew Number of Credits : ";
    string number;
    cin.ignore(1000, '\n');
    getline(cin, number);

    while (!in.eof()) {
        getline(in, s);
        if (s == choice) {
            testFile << s << '\n';
            while (getline(in, s)) {
                if (s == "e") {
                    testFile << s << '\n';
                    while (getline(in, s)) {
                        if (s == nextChoice || s == "f") break;
                        testFile << "Number of credits : " << number << '\n';
                    }
                    break;
                }
                testFile << s << '\n';
            }
        }
        testFile << s << '\n';
    }

    in.close();
    testFile.close();

    std::remove(courseInfo);
    std::rename(test, courseInfo);

    informationCourse(existSemester, year, year_semester, course, order, semester);
}
