#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

bool showYear(string &accessYear);
void showStudent(string accessYear, string chooseClass);
void addNewClass(string accessYear);
void addOneStudent(string accessClass);
void quickAddWithCSVFile(string accessClass);

void ViewClass(){
    string accessYear;
    if (!showYear(accessYear)) return ;     
    ifstream in(accessYear + "/existClass.txt"); 

    int line = 0;
    string s;
    while (getline(in, s)) line++;
    in.close();
    in.open(accessYear + "/existClass.txt");
    string* Class = new string[line];
    int i = 0;
    while (getline(in, s)){
        Class[i] = s;
        i++;
    }
    in.close();

    cout << "\n";

    cout << "  * Classes\n";

    for (int i = 0 ; i < line ; i++) cout << i + 1 << ". " << Class[i] << "\n";

    cout << "\n  * Task\n";

    cout << line + 1 << ". Add new class\n" ;
    cout << line + 2 << ". Back\n";

    int choice;
    cout << "Your choice is : ";
    cin >> choice;
    if (choice >= 1 && choice <= line){
        string chooseClass = Class[choice - 1];
        delete[] Class;
        showStudent(accessYear, chooseClass);
    }
    else if (choice == line + 1) addNewClass(accessYear);
}

bool showYear(string &accessYear){
    system("clear");

    ifstream in;
    in.open("DataSet/Class/year.txt");

    cout << "* Choose one year to access class\n";

    int line = 0;
    string s;
    while (getline(in, s)) line++;
    in.close();
    in.open("DataSet/Class/year.txt");
    string* year = new string[line];
    int i = 0;
    while (getline(in, s)){
        year[i] = s;
        i++;
    }
    in.close();

    for (int i = 0 ; i < line ; i++) cout << i + 1 << ". " << year[i] << "\n";
    cout << line + 1 << ". Back\n";

    cout << "Your choice is : ";
    int choice;
    cin >> choice;

    if (1 <= choice && choice <= line){
        accessYear = "DataSet/Class/" + year[choice - 1];
        delete[] year;
        return true;
    }
    delete[] year;
    return false;
}

void showStudent(string accessYear, string chooseClass){ 
    ifstream in(accessYear + "/" + chooseClass + ".txt"); 

    int line = 0;
    string s;
    while (getline(in, s)) line++;
    in.close();
    in.open(accessYear + "/" + chooseClass + ".txt");
    string* student = new string[line];
    int i = 0;
    while (getline(in, s)){
        student[i] = s;
        i++;
    }
    in.close();

    cout << "\n   " << chooseClass << " !!!\n";
    for (int i = 0 ; i < line ; i++) cout << student[i] << "\n";

    delete[] student;

    int choice;
    cout << "\n1. Add new student\n";
    cout << "2. Quick add new student with CSV file\n";
    cout << "3. Back\n";
    cout << "Your choice is : ";
    cin >> choice;

    if (choice == 1){
        string accessClass = accessYear + "/" + chooseClass + ".txt";
        addOneStudent(accessClass);
    }
    else if (choice == 2){
        string accessClass = accessYear + "/" + chooseClass + ".txt";
        quickAddWithCSVFile(accessClass);
    }
}

void addNewClass(string accessYear){
    string newClass;
    cout << "\nName of new class : ";
    cin >> newClass;
    ofstream out;
    out.open(accessYear + "/" + newClass + ".txt");
    out.close();
    out.open(accessYear + "/existClass.txt", ios::app);
    out << newClass + "\n";
    out.close();

    cout << "Create new class successfully !";

    char a;
    cin.ignore();
    a = cin.get();
}

void addOneStudent(string accessClass){
    ofstream out(accessClass, ios::app);
    string name;
    string id;
    bool cont = true;
    while (cont){
        cin.ignore(100, '\n');
        cout << "Full name of student : ";
        getline(cin, name);
        cout << "ID Student : ";
        getline(cin, id);
        string line = id + " - " + name + "\n";
        out << line;

        cout << "Add sucessfully ! Add more student (y /n) : ";
        char a;
        cin >> a;
        if (a != 'y'){
            cont = false;
            out.close();
        }
    }
}

void quickAddWithCSVFile(string accessClass){
    string path;
    cout << "Input path into file CSV : ";
    cin >> path; // InputCSV/addToClass.csv

    ifstream in(path);

    if (!in){
        cout << "Error finding path into file CSV";
        char a;
        cin.ignore();
        a = cin.get();
        return ;
    }

    ofstream out(accessClass, ios_base::app);
    string line;
    string name;
    string id;
    bool see = false;

    while (getline(in, line)){
        id = "";
        name = "";
        for (int i = 0 ; i < line.length() ; i++){
            if (line[i] == ',') see = true;
            else if (see) name += line[i];
            else id += line[i];
        }
        out << id + " - " + name + '\n';
        see = false;
    }

    in.close();
    out.close();
    
    cout << "Add list of students successfully !";
    char a;
    cin.ignore(100, '\n');
    a = cin.get();
}