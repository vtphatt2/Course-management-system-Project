#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/stat.h>
#include "../../Interface/interface.h"
using namespace std;

void addStudentToMoodle();
void addWithCSVFile();
void importProfileToMoodle(string id, string fullname, string sex, string socialID, string DOB);

void typeAdding(){
    int choice;
    interfaceOption("Function/Staff/AddStudent/interface.txt", choice, "ADD STUDENT TO MOODLE");
    if (choice == 1) addStudentToMoodle();
    else if (choice == 2) addWithCSVFile();
    else return ;
}

void importProfileToMoodle(string id, string fullname, string sex, string socialID, string DOB){
    string path = "DataSet/InfoStudent/" + id;
    int check = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (check == -1){
        cout << "Error creating student's profile !";
        char a;
        a = cin.get();
        return ;
    }

    ofstream out;
    out.open(path + "/course.txt");
    out.close();
    out.open(path + "/profile.txt");
    out << id << "\n";
    out << fullname << "\n";
    out << sex << "\n";
    out << DOB << "\n";
    out << socialID;
    out.close();

    out.open("DataSet/accountUser.txt", ios_base::app);
    string user = "";
    for (int i = 0 ; i < fullname.length() ; i++){
        if (fullname[i] == ' ') continue ;
        else if ('A' <= fullname[i] && fullname[i] <= 'Z'){
            user += (char)(fullname[i] + 32);
        }
        else user += fullname[i];
    }
    out << "\n" << user << "\n";
    out << "12345" << "\n";  //default password
    out << "student" << "\n";
    out << id << "\n";
    out.close();
}

void addStudentToMoodle(){
    system("clear");

    string id, fullname, sex, socialID, DOB;

    cout << "New ID Student : ";
    cin >> id;

    cout << "Full name : ";
    cin.ignore();
    getline(cin, fullname);

    int choice;
    cout << "Sex (1. Male/ 2. Female) : ";
    cin >> choice;
    if (choice == 1) sex = "Male";
    else sex = "Female";

    cout << "Social ID : ";
    cin >> socialID;

    string day, month, year;
    cout << "Date of Birth\n";
    cout << "   + Day : ";
    cin >> day;
    cout << "   + Month : ";
    cin >> month;
    cout << "   + Year : ";
    cin >> year;
    DOB = day + "." + month + "." + year;

    importProfileToMoodle(id, fullname, sex, socialID, DOB);

    cout << "Add student to Moodle successfully !";
    
    char a;
    a = cin.get();
}

void addWithCSVFile(){
    system("clear");

    string pathFileName;
    cout << "Input path to csv file : "; 
    cin >> pathFileName; // InputCSV/listOfStudent.csv

    ifstream in;
    in.open(pathFileName);
    if (!in){
        cout << "Error finding this csc file !";
        cin.ignore();
        char a;
        a = cin.get();
        return ;
    }

    string line;
    getline(in, line); //ignore this line because it is title

    while (getline(in, line)){
        string id, fullname, sex, socialID, DOB;
        string day, month, year;
        int k = 0;

        for (int i = 0 ; i < line.length() ; i++){
            if (line[i] == ',') k++;
            else if (k == 0) id += line[i];
            else if (k == 1) fullname += line[i];
            else if (k == 2) sex += line[i];
            else if (k == 3) socialID += line[i];
            else if (k == 4) day += line[i];
            else if (k == 5) month += line[i];
            else if (k == 6) year += line[i]; 
        }
        DOB = day + "." + month + "." + year;

        importProfileToMoodle(id, fullname, sex, socialID, DOB);
    }
    cout << "Add students to Moodle successfully !";
    cin.ignore();
    char a;
    a = cin.get();
}