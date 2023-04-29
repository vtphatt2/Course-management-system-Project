#include "courses.h"
string totalMark(string line){
    int l = line.length();
    int cnt=0;
    string id = "", mark = "";
    for (int i=0; i<l; i++){
        if (cnt==1 && line[i]!=',') id = id + line[i];
        if (cnt==4 && line[i]!=',') mark = mark +line[i];
        if (line[i]==',') cnt++;
    }
    string res = id + ' ' + mark;
    return res;
}
void getTotalMark(string year, string semester, string yearStudy, string course){
    string address = "DataSet/SchoolYear/" + year + '/' + semester + '/' + yearStudy + '/' + course;
    ifstream fin;
    ofstream fout;
    fout.open(address + "/totalMark.txt");
    string addressClass = address + "/existClass.txt";
    string addressScore;
    fin.open(addressClass);
    string Class,line;
    while (getline(fin,Class)){
        addressScore = address + "/" + Class + "/scoreBoard.txt";
        ifstream in;
        in.open(addressScore);
        getline(in,line);
        while (getline(in,line)) {
            fout << totalMark(line);
            fout << '\n';
        }
        in.close();
    }
    fin.close();
    fout.close();
}