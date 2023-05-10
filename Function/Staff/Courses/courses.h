# pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include <iomanip>
#include <string.h>
#include <cstdio>
using namespace std;

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
struct studentNode{
    string idCourse;
    float score;
    int numCredits;
    studentNode* next;
};

void tasksCourses(string &existSemester, string &year, string &year_semester, string &semester); // choose tasks
void courseAndEdit(string &existSemester, string &year, string &year_semester, string &semester); // view all courses and edit
void courseDetails(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester); // view the details of course such as students and infomation
void informationCourse(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester); // view the information of this coursevoid editCourse(string &existSemester, string &year, string &year_semester, string &semester); // edit course
void updateCourse(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // update course
void deleteCourse(string &existSemester, string &year, string &year_semester, string &semester);      // delete a course
void viewScoreBoardInCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order); // view score board of a course
void changeID(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // Change the ID
void changeClassName(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // Change the class name
void changeCourseName(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // Change the course name
void changeDay(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change day
void changeNumCredits(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change number of credits
void changeSession(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change session
void changeTeacher(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change teacher
void changeMaximumStudents(string &existSemester, string &year, string &year_semester, string &semester, int &order, string &course); // change maximum of students
void addStudentToCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order); // add student to course
void removeStudentFromCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order); // remove student from course
void updateResult(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order); //Function to update result
void viewListOfStudentsInCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order); // Function to view list of student in a course
void viewClassAndStudentInThatClass(string &existSemester, string &year, string &year_semester, string &semester);
void tasksStudentToCourse(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order); // tasks add or remove a student
void getTotalMark(string year, string semester, string yearStudy, string course); // To create or adjust file total.txt
void make_a_new_folder_course(string &existSemester, string &year, string &year_semester, string &semester, string &courseID, string* classes, int &n);
void addCourse(string &existSemester, string &year, string &year_semester, string &semester);
void editCourse(string &existSemester, string &year, string &year_semester, string &semester);
void uploadCSV(string &existSemester, string &year, string &semester,string &year_semester, string &course, int &order); //To upload file CSV contain list of students enrolled in the courses
void printScoreBoard(string &year, string &year_semester, string &semester,string nameClass);
void publicResult(string &existSemester, string &year, string &year_semester, string &semester, string &course, int &order); //To public result of a course


//Support Function
string findID(string s);
void createNewScore(string& newLine,string line);
void display(string no, string id, string name, string Class);
bool checkAvailableStudent(string &studentID);
string totalMark(string line);
int getNumberOfStudent(string year, string nameClass);
studentNode* allCourse(string id, string &year, string &semester);
void numberOfCredits(string course, string &year, string &year_semester, string &semester,int &num);
float getStudentScore(string course, string &year, string &year_semester, string &semester,string id);
void storeLinkedList_1Student(string &year, string &year_semester, string &semester, studentNode* head,string id);
void display(studentNode* head);
