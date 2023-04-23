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
        string nameclass[10];
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
    cout << "UPDATE SUCCESSFULLY";

    cout << "\nType any key to back : ";
    string ans;
    getline(cin, ans);
    courseDetails(existSemester, year, year_semester, course, order, semester);
}