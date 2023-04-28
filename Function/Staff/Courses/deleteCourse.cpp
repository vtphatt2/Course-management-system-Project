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
#include "../staff.h"

using namespace std;

void deleteCourse(string &existSemester, string &year, string &year_semester, string &semester) {
    string existCourse_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/existCourse.txt";
    const char* existCourse = existCourse_tmp.c_str();
    string courseInfo_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/courseInfo.txt";
    const char* courseInfo = courseInfo_tmp.c_str();

    ifstream in;
    in.open(existCourse);
    int numberOfCourse = 0;
    string s;
    while (getline(in, s)) ++numberOfCourse;
    in.close();

    string* arr = new string[numberOfCourse];
    int t = 0;
    in.open(existCourse);
    while (getline(in, s)) {
        // take the course
        arr[t++] = s;
    }
    in.close();

    string* tmp = new string[numberOfCourse];
    t = 0;
    in.open(existCourse);
    while (!in.eof()) {
        in >> s;
        tmp[t++] = s;
        getline(in, s);
    }
    in.close();

    cout << "\n* Choose Course that you want to remove : " << '\n';
    for (int i = 0; i < numberOfCourse; ++i) cout << i + 1 << ". " << arr[i] << '\n';
    cout << "\nYour choice is : ";
    int choice;
    cin >> choice;

    string folder_path = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + tmp[choice - 1];
    string command = "rm -rf \"" + folder_path + "\"";
    system(command.c_str());

    string test_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/test.txt";
    const char* test = test_tmp.c_str();

    ofstream testFile(test);
    if (choice == numberOfCourse) {
        for (int i = 0; i < numberOfCourse - 2; ++i) {
            testFile << arr[i] << '\n';
        }
        testFile << arr[numberOfCourse-2];
    }
    else {
        for (int i = 0; i < numberOfCourse - 1; ++i) {
            if (i == choice - 1) continue;
            testFile << arr[i] << '\n';
        }
    testFile << arr[numberOfCourse-1];
    }

    testFile.close();
    remove(existCourse);
    rename(test, existCourse);

    string testInfo_tmp = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/test.txt";
    const char* testInfo = testInfo_tmp.c_str();
    ofstream infoTest(testInfo);

    int numberOfInfo = 0;
    in.open(courseInfo);
    while (getline(in, s)) ++numberOfInfo;
    in.close();

    string choice_tmp = to_string(choice);
    in.open(courseInfo);
    while (getline(in, s)) {
        if (s == choice_tmp) {
            while (getline(in, s)) {
                if (s == to_string(choice + 1)) break;
            }
            if (choice != numberOfCourse) infoTest << choice << '\n';
            int n = choice + 2;
            while (getline(in, s)) {
                if (s == to_string(n)) {
                    infoTest << n - 1 << '\n';
                    ++n;
                }
                else infoTest << s << '\n';
            }
            break;
        }
        else {
            infoTest << s << '\n';
        }
    }

    infoTest.close();
    remove(courseInfo);
    rename(testInfo, courseInfo);

    delete[] arr;
    delete[] tmp;

    cout << "\nREMOVE SUCCESSFULLY !";
    cout << "\nType any key to back : ";
    string ans;
    cin >> ans;
    system("clear");
    tasksCourses(existSemester, year, year_semester, semester); // back to tasks function of Course
}