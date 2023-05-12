#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "../Courses/courses.h"
#include "export.h"

using namespace std;

void createCSVFile(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    string existClassInCourse = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/existClass.txt";
    ifstream existClass(existClassInCourse);
    string classID;
    ofstream csvFile;
    csvFile.open("DataSet/listOfStudent.csv", ios::app);
    csvFile << year << endl;
    csvFile << semester << endl;
    csvFile << year_semester << endl;
    csvFile << course << endl;
    csvFile << "No,StudentID,StudentName,ClassID,Total Mark,Final Mark,Midterm Mark,Other Mark." << endl;
    int no=1;
    while (getline(existClass,classID)){
        string listOfStudent = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + classID + "/listOfStudent.txt";
        ifstream student(listOfStudent);
        string studentID;
        int n=0;
        while (getline(student,studentID)){
            n++;
        }
        student.close();
        student.open(listOfStudent);
        string ID[1000];
        for (int i=0;i<n;i++) getline(student,ID[i]);
        sort(ID,ID+n);
      
        for (int i=0;i<n;i++){
            string profile="DataSet/InfoStudent/" + ID[i] + "/profile.txt";
            ifstream studentInfo(profile);
            string studentName;
            getline(studentInfo,studentID);
            getline(studentInfo,studentName);
            csvFile << no++ << "," << studentID << "," << studentName << "," << classID << "," << "0" << "," << "0" << "," << "0" << "," << "0" << endl;
            studentInfo.close();
        }
        student.close();
    }
    csvFile.close();
    existClass.close();
} 
void menuCreateCSV(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    cout << "Confirm your choose:";
    cout << "Year : " << year << '\n';
    cout << " Semester : " << semester << '\n';
    cout << " YearStudy : " << year_semester << '\n';
    cout << " Course: " << course << endl;
    createCSVFile(existSemester, year, year_semester, semester, course, order);
    cout << "SUCCESSFULLY!" << '\n';
    cout << "Type any key to back" << endl;
    string t;
    cin >> t;
    tasksCSVFile(existSemester, year, year_semester, semester, course, order);
}