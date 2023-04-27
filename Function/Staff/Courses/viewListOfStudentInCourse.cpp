#include "courses.h"
#include <algorithm>

void display(string no, string id, string name, string Class){
    cout << "   | " << no ;
    for (int i=1; i<=5-no.length(); i++) cout << ' ';
    cout << "| " << id;
    for (int i=1; i<=11-id.length(); i++) cout << ' ';
    cout << "| " << name;
    for (int i=1; i<=32-name.length(); i++ ) cout << ' ';
    cout << "| " << Class;
    for (int i=1; i<=10-Class.length(); i++) cout << ' ';
    cout << "|";
    cout << '\n';
}

void viewListOfStudentsInCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    cout << "   \t\t\tLIST OF STUDENT" << "\n";
    cout << "    ";
    for (int i=0; i<65; i++) cout << '_';
    cout << '\n';
    display(" ","STUDENT ID", "     FULL NAME","CLASS");
    string existClass = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" +"existClass.txt";

    string* classes;
    string tmp;
    ifstream fin;
    fin.open(existClass);
    int numClass=0;
    while (getline(fin,tmp)) numClass++;
    fin.close();
    classes = new string [numClass];
    fin.open(existClass);
    for (int i=0; i<numClass; i++) getline(fin,classes[i]);
    fin.close();
    sort(classes, classes + numClass);
    string listFile;
    int no=0;
    for (int i=0; i<numClass; i++){
        listFile="DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + classes[i] + "/listOfStudent.txt";
        string* students;
        fin.open(listFile);
        int numStudent=0;
        while (getline(fin,tmp)) numStudent++;
        fin.close();
        students = new string[numStudent];
        fin.open(listFile);
        for (int i=0; i<numStudent; i++) getline(fin,students[i]); 
        fin.close();
        sort(students, students + numStudent);
        for (int j=0; j<numStudent; j++){
            string infoFile = "DataSet/InfoStudent/" + students[j] + "/profile.txt";
            fin.open(infoFile);
            string name;
            getline(fin,name);
            getline(fin,name);
            fin.close();
            no++;
            display(to_string(no), students[j], name, classes[i]);
        }
        delete [] students;
    }
    cout << "   ";
    for (int i=0; i<67; i++) cout << '=';
    delete [] classes;

    string ans;
    cout << '\n';
    cout << "\nType any key to back : ";
    cin >> ans;
    tasksStudentToCourse(existSemester, year, year_semester, semester, course, order);
}