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

void viewScoreBoardInCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    ifstream in;
    string existClass = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" +"existClass.txt";
    in.open(existClass);
    string s;

    createTitle("SCORE BOARD");
    cout << '\n';
    // Print header row
    std::cout << std::left << std::setw(5) << "No"
              << std::setw(12) << "Student ID"
              << std::setw(20) << "Student Name"
              << std::setw(10) << "Class ID"
              << std::setw(12) << "Total Mark"
              << std::setw(12) << "Final Mark"
              << std::setw(14) << "Midterm Mark"
              << std::setw(12) << "Other Mark" << std::endl;

    std::cout << std::string(85, '-') << std::endl;
    while (getline(in,s)){
        string scoreboard = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + s + "/" + "scoreBoard.txt";
        ifstream file(scoreboard);
        string header_line;
        getline(file, header_line); // Read and ignore header line

        std::string line;
        while (std::getline(file, line)) {
            ScoreBoardEntry entry;

            size_t prev_pos = 0, pos;
            pos = line.find(',', prev_pos);
            entry.No = std::stoi(line.substr(prev_pos, pos - prev_pos));
            prev_pos = pos + 1;

            pos = line.find(',', prev_pos);
            entry.StudentID = line.substr(prev_pos, pos - prev_pos);
            prev_pos = pos + 1;

            pos = line.find(',', prev_pos);
            entry.StudentName = line.substr(prev_pos, pos - prev_pos);
            prev_pos = pos + 1;

            pos = line.find(',', prev_pos);
            entry.ClassID = line.substr(prev_pos, pos - prev_pos);
            prev_pos = pos + 1;

            pos = line.find(',', prev_pos);
            entry.TotalMark = std::stoi(line.substr(prev_pos, pos - prev_pos));
            prev_pos = pos + 1;

            pos = line.find(',', prev_pos);
            entry.FinalMark = std::stoi(line.substr(prev_pos, pos - prev_pos));
            prev_pos = pos + 1;

            pos = line.find(',', prev_pos);
            entry.MidtermMark = std::stoi(line.substr(prev_pos, pos - prev_pos));
            prev_pos = pos + 1;

            entry.OtherMark = std::stoi(line.substr(prev_pos));

            std::cout << std::left << std::setw(5) << entry.No
                  << std::setw(12) << entry.StudentID
                  << std::setw(20) << entry.StudentName
                  << std::setw(10) << entry.ClassID
                  << std::setw(12) << entry.TotalMark
                  << std::setw(12) << entry.FinalMark
                  << std::setw(14) << entry.MidtermMark
                  << std::setw(12) << entry.OtherMark << std::endl;
        }

    file.close();
    }
    in.close();
    cin.ignore(1000, '\n');
    cout << "\n* Tasks : ";
    cout << "\n1. Update a student's result";
    cout << "\n2. Back";
    cout << "\nYour choice is : ";
    int t;
    cin >> t;
    courseDetails(existSemester, year, year_semester, course, order, semester);
}