#include "export.h"
void createCSVFile(string &year, string &semester, string &yearStudy , string course){
    string existClassInCourse = "DataSet/SchoolYear/" + year + "/" + semester + "/" + yearStudy + "/" + course + "/existClass.txt";
    ifstream existClass(existClassInCourse);
    string classID;
    ofstream csvFile;
    csvFile.open("DataSet/listOfStudent.csv", ios::app);
    csvFile << year << endl;
    csvFile << semester << endl;
    csvFile << yearStudy << endl;
    csvFile << course << endl;
    csvFile << "No,StudentID,StudentName,ClassID,Total Mark,Final Mark,Midterm Mark,Other Mark." << endl;
    int no=1;
    while (getline(existClass,classID)){
        string listOfStudent = "DataSet/SchoolYear/" + year + "/" + semester + "/" + yearStudy + "/" + course + "/" + classID + "/listOfStudent.txt";
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
void menuCreateCSV(string &year, string &semester, string &yearStudy){
    string course;
    cout << "Enter course you want to EXPORT to CSV file: ";
    cin >> course;
    cout << "Confirm your choose:";
    cout << "Year: " << year << " Semester: " << semester << " YearStudy: " << yearStudy << " Course: " << course << endl;
    createCSVFile(year,semester,yearStudy,course);
    cout << "SUCCESSFULLY!";
}