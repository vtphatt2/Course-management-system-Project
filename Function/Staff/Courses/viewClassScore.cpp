#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "courses.h"
#include "../SchoolYears/schoolyears.h"
#include "../Semesters/semesters.h"
#include "../../Interface/interface.h"
using namespace std;
int getNumberOfStudent(string year, string nameClass){
    string path="DataSet/Class/"+year+"/"+nameClass+".txt";
    ifstream fin;
    fin.open(path);
    if(!fin.is_open()){
        cout<<"Can't open file"<<endl;
        return 0;
    }
    string line;
    int count=0;
    while(getline(fin,line)){
        count++;
    }
    fin.close();
    return count;
}
studentNode* allCourse(string id, string &year, string &semester){
    string allCourse="DataSet/InfoStudent/"+id+"/courses.txt";
    ifstream fin;
    fin.open(allCourse);
    if(!fin.is_open()){
        cout<<"Can't open file"<<endl;
        return NULL;
    }
    string line1;
    studentNode* head=NULL;
    while (getline(fin,line1)){
        if (line1==year)
            {
                while (getline(fin,line1)){
                    if (line1==semester){
                        head = new studentNode;
                        getline(fin,line1);
                        head->idCourse = line1;
                        head->next = NULL;
                        studentNode* cur = head;
                        while (getline(fin,line1)){
                            if (line1=="") break;
                            cur->next = new studentNode;
                            cur = cur->next;
                            cur->idCourse = line1;
                            cur->next = NULL;
                        }
                        break;
                    }
                } 
            }
        break;
    }
    fin.close();
    return head;
}
void numberOfCredits(string course, string &year, string &year_semester, string &semester,int &num){
    string path="DataSet/SchoolYear/"+year+"/"+semester+"/"+year_semester+"/courseInfo.txt";
    ifstream fin;
    fin.open(path);
    if(!fin.is_open()){
        cout<<"Can't open file"<<endl;
        return;
    }
    string line;
    string flag= "Course ID: " + course;
    while (getline(fin,line)){
        if (line==flag){
            while (getline(fin,line)){
                if (line=="e"){
                    getline(fin,line);
                    num = 0;
                    size_t pos = line.find(":");  // find the position of the colon
                    if (pos != string::npos) {  // check if the colon is found
                        string substring = line.substr(pos + 2);  // extract the substring after the colon and the space
                        num = stoi(substring);  // convert the substring to an integer
                    }
                    break;
                }
                
            }
            break;
        }
    }
    fin.close();
}
float getStudentScore(string course, string &year, string &year_semester, string &semester,string id){
    getTotalMark(year,semester,year_semester,course);
    string path="DataSet/SchoolYear/"+year+"/"+semester+"/"+year_semester+"/"+course+"/totalMark.txt";
    ifstream fin;
    fin.open(path);
    if(!fin.is_open()){
        cout<<"Can't open file"<<endl;
        return 0;
    }
    string line;
    float mark=0;
    while (getline(fin,line)){
        if (line.substr(0,8)==id){
            size_t pos = line.find(" ");  // find the position of the colon
            if (pos != string::npos) {  // check if the colon is found
                string substring = line.substr(pos + 1);  // extract the substring after the colon and the space
                mark = stof(substring);  // convert the substring to an integer
            }
            break;
        }
    }
    fin.close();
    return mark;
}
void storeLinkedList_1Student(string &year, string &year_semester, string &semester, studentNode* head,string id){
    studentNode* cur=head;
    while (cur){
        int n=0;
        numberOfCredits(cur->idCourse,year,year_semester,semester,n);
        cur->numCredits = n;
        cur->score = getStudentScore(cur->idCourse,year,year_semester,semester,id);
        cur = cur->next;
    }
}
void display(studentNode* head){
        studentNode* cur = head;
        while (cur!=NULL){
            cout<<cur->idCourse<<endl;
            cout<<cur->numCredits<<endl;
            cout<<cur->score<<endl;
            cout << endl;
            cur = cur->next;
        }
}
void printScoreBoard(string &year, string &year_semester, string &semester,string nameClass){
    string path="DataSet/Class/"+year+"/"+ nameClass +".txt";
    ifstream fin;
    fin.open(path);
    if(!fin.is_open()){
        cout<<"Can't open file"<<endl;
        return;
    }
    string line;
    // print header of the board

    while (getline(fin,line)){
        string nameStudent="DataSet/InfoStudent/"+line+"/profile.txt";
        ifstream fin1;
        fin1.open(nameStudent);
        if(!fin1.is_open()){
            cout<<"Can't open file"<<endl;
            return;
        }
        string studentName;
        getline(fin1,studentName);
        getline(fin1,studentName);
        fin1.close();
        studentNode* head = allCourse(line,year,semester);
        storeLinkedList_1Student(year,year_semester,semester,head,line);
        ofstream fout;
        string address = "DataSet/SchoolYear/" + year + '/' + semester + '/' + year_semester + '/' + "/gpaScore.txt";
        fout.open(address,ios::app);
        cout << studentName << " " << line << endl;
        studentNode* cur = head;
        while (cur){
            cout<<cur->idCourse<<" " << cur->score << endl;
            cur = cur->next;
        }
        float sum=0;
        cur=head;
        int totalCredits=0;
        while (cur){
            sum+=cur->score*cur->numCredits;
            totalCredits+=cur->numCredits;
            cur = cur->next;
        }
        sum=sum/totalCredits;
        cout << "GPA: " << sum << endl;
        fout << line << endl << sum << endl;
    }
    fin.close();
}