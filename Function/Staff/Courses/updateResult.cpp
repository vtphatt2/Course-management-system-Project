#include "courses.h"

string findID(string s){
    string res = "";
    int l = s.length();
    int cnt=0;
    for (int i=0; i<l; i++){
        if (cnt == 1 && s[i] != ',') res = res + s[i];
        if (s[i] == ',') cnt++;
    }
    return res;
}
void updateScore(string& newLine,string line){
    string res = "";
    //Total Mark,Final Mark,Midterm Mark,Other Mark
    cout << "Please choose one of options: \n";
    cout << "1. Change total mark\n";
    cout << "2. Change final mark\n";
    cout << "3. Change midterm mark\n";
    cout << "4. Change other mark\n";
    cout << "Your choose: ";
    int type;
    string newScore;
    cin >> type;
    cout << "New score: ";
    cin >> newScore;

    int i=0;
    int cnt=0;
    while (cnt < type +3){
        res = res + line[i];
        if (line[i] == ',') cnt++;
        i++;
    }
    res = res + newScore;
    cnt = 0;
    int l = line.length();
    for (int i=0; i<l; i++){
        if (cnt >= type+4 && line[i] != ',') res = res + line[i];
        if (line[i] == ',') cnt++;
    }
    newScore = res;
}
void updateResult(string &year, string &semester, string &yearStudy){
    cout << "Input information about course and class to update result \n";
    cout << "COURSE: ";
    string course, classID;
    getline(cin, course);
    cout << "CLASS: ";
    getline(cin, classID);
    string address = "DataSet/SchoolYear/" + year + "/" + semester + "/" + yearStudy + "/" + course + "/" + classID + "/scoreBoard.txt";
    ifstream fin(address);
    while (!fin.is_open()){
        cout << "ERROR: Can not open this file!\n";
        cout << "Please try again!\n";
        cout << "COURSE: ";
        getline(cin, course);
        cout << "CLASS: ";
        getline(cin, classID);
        string address = "DataSet/SchoolYear/" + year + "/" + semester + "/" + yearStudy + "/" + course + "/" + classID + "/scoreBoard.txt";     
    }
    ofstream fout;
    string tmpAddress = "DataSet/SchoolYear/" + year + "/" + semester + "/" + yearStudy + "/" + course + "/" + classID + "tmp.txt";
    fout.open(tmpAddress);
    string line;
    string id;
    cout << "Enter ID student: \n";
    getline(cin,id);
    int flag=0;
    while (getline(fin, line)){
        if (findID(line) == id){
            string newLine;
            updateScore(newLine, line);
            fout << newLine << '\n';
        } else fout << line << '\n';
    }
    fin.close();
    fout.close();
    fin.open(tmpAddress);
    fout.open(address);
    while (getline(fin, line)){
        fout << line << '\n';
    }
    fin.close();
    fout.close();
    remove(tmpAddress.c_str());
    cout << "UPDATE SUCCESSFULLY";
}