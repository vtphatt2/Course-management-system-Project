#include "changeProfile.h"
bool checkDay(int y,int m,int d){
    if (m>12 || d>31) return 0;
    int leap=0;
    int mxm;
    if ((y%4==0 && y%100!=0) || y%400==0) leap=1;
    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) mxm=31;
    else if (m==2) {
        if (leap==1) mxm=29;
        else mxm=28;
    } else mxm=30; 
    if (d>mxm) return 0;
    return 1;
}
void changeProfile(string id){
    string address = "DataSet/InfoStudent/" +id+ "/profile.txt";
    ifstream fin(address); 
    if (!fin.is_open()){
        address = "DataSet/InfoStaff/"+ id + "/profile.txt";
        fin.close();
        fin.open(address);
        if (!fin.is_open()){
            cout << "Your ID does not exist! \n";
            return;
        }
    }
    fin.close();
    
    // Create MENU
    fin.open("taskOfChanges.txt");
    string s;
    while (getline(fin,s)) cout << s << '\n';
    fin.close();
    int type;
    cout << "Your choose is(input a number): ";
    cin >> type;
    cout << '\n';
    if (type==1) changeName(id,address);
    if (type==2) changeSex(id,address);
    if (type==3) changeDOB(id,address);
}
void changeName(string id, string address){
    ifstream fin;
    fin.open(address);
    string save[6];
    for (int i=1; i<=5; i++){
        getline(fin,save[i]);
    }
    fin.close();
    cout << "Enter a new name: \n";
    cin.ignore();
    string name;
    getline(cin,name);
    save[2]=name;
    ofstream fout;
    fout.open(address);
    for (int i=1; i<=5; i++){
        fout << save[i] << '\n';
    }
    fout.close();
}
void changeSex(string id, string address){
    ifstream fin;
    fin.open(address);
    string save[6];
    for (int i=1; i<=5; i++){
        getline(fin,save[i]);
    }
    fin.close();
    cout << "Enter your choose: \n";
    cout << "1. Male \n";
    cout << "2. Female \n";
    int x;
    cin >> x;
    while (x!=1 && x!=2){
        cout << "Please choose again (1 or 2): ";
        cin >> x;
    }
    if (x==1) save[3]="Male";
    if (x==2) save[3]="Female";
    ofstream fout;
    fout.open(address);
    for (int i=1; i<=5; i++){
        fout << save[i] << '\n';
    }
    fout.close();
}
void changeDOB(string id, string address){
    ifstream fin;
    fin.open(address);
    string save[6];
    for (int i=1; i<=5; i++){
        getline(fin,save[i]);
    }
    fin.close();
    int d,m,y;
    cout << "Enter date of birth: \n";
    cout << "Year: ";
    cin >> y;
    cout << "Month: ";
    cin >> m;
    cout << "Day: ";
    cin >> d;
    while (!checkDay(y,m,d)){
        cout << "The day does not exist \n";
        cout << "Year: ";
        cin >> y;
        cout << "Month: ";
        cin >> m;
        cout << "Day: ";
        cin >> d;
    }
    string day = to_string(d);
    string month = to_string(m);
    string year = to_string(y);
    if (d<10) day="0"+day;
    if (m<10) month="0"+month;
    cout << day << ' ' << month << ' ' << year;
    save[4]=day + "." + month + "." + year;
    ofstream fout;
    fout.open(address);
    for (int i=1; i<=5; i++){
        fout << save[i] << '\n';
    }
    fout.close();
}
