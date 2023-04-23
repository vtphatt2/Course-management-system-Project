#include "courses.h"
#include <algorithm>
void viewListOfStudentsInCourse(string &existSemester, string &year, string &semester,string &year_semester, string &course, int &order){
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
}