#include "courses.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include <iomanip>
struct ScoreBoardEntry {
    int No;
    string StudentID;
    string StudentName;
    string ClassID;
    float TotalMark;
    float FinalMark;
    float MidtermMark;
    float OtherMark;
};
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

void createNewScore(string& newLine,string line){
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
        if (line[i]==',') cnt++;
        if (cnt>=type+4 ) res = res + line[i];
    }
    newLine = res;
}
void prinOutList(string address){
        ifstream file(address);
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
void updateResult(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order){
    string classID;
    string id,line;
    int flag=0;
    string address = "0theTrugTEN23sad3";
    string tmpAddress ="0theTRUNGten12happi4";

    ifstream fin;
    ofstream fout;

    while (!fin.is_open() || flag != 1) {
        ifstream in;
        string nameclass[40];
        cout << "\nClass available: " << endl;
        string existClass = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" +"existClass.txt";   
        in.open(existClass);
        int cnt=1;
        while (getline(in, nameclass[cnt])){
            cout << cnt << ". " << nameclass[cnt] << endl;
            cnt++;
        }
        in.close();
        cout << "Your choice is : ";
        cin >> cnt;
        classID = nameclass[cnt];

        address = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + classID + "/scoreBoard.txt";

        fin.close();
        fin.open(address);

        cin.ignore(1000, '\n');
        
        if (fin.is_open()){
            tmpAddress = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/" + course + "/" + classID + "tmp.txt";
            fout.open(tmpAddress);
            prinOutList(address);
            cout << "Enter ID student : ";
            getline(cin,id);
            while (getline(fin, line)){
                if (findID(line) == id){
                    string newLine;
                    createNewScore(newLine, line);
                    fout << newLine << '\n';
                    flag=1;
                } else fout << line << '\n';
            }
            if (flag!=1){
                cout << "Can not find the ID\n";
                cout << "Please try again\n";
            } 
            fout.close();   
        } else{
            cout << "ERROR: Can not open this file\n";
            cout << "Please try again\n";
        }
    }
    fin.close();
    fin.open(tmpAddress);
    fout.open(address);
    while (getline(fin, line)){
        fout << line << '\n';
    }
    fin.close();
    fout.close();
    remove(tmpAddress.c_str());
    prinOutList(address);
    cout << "UPDATE SUCCESSFULLY";
    cout << "\nType any key to back : ";
    string ans;
    getline(cin, ans);
    courseDetails(existSemester, year, year_semester, course, order, semester);
}