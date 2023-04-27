#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/stat.h>
using namespace std;

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


    cout << "Add student to Moodle successfully !";
    char a;
    a = cin.get();
}