#include "../staff.h"
#include "ncurses.h"

void tasksSchoolYears(){
    int choice;
    interfaceOption(path_TasksSchoolYears, choice, "SCHOOLYEARS");

    if (choice == 1) schoolYearAndEdit();
    // else back function
}

void schoolYearAndEdit(){
    system("clear");

    //open file named "existSchoolYear.txt"
    ifstream in;
    in.open(existSchoolYear);

    //get number of SchoolYear in this file
    int numberOfSchoolYear = 0;
    string s;
    while (getline(in, s)) ++numberOfSchoolYear;
    in.close();

    string* arr = new string[numberOfSchoolYear];
    in.open(existSchoolYear);
    int i = 0;
    while (getline(in, s)) {
        arr[i] = s;
        ++i;
    }
    in.close();

    int choice = 1;

    //create interface option
    initscr();
	keypad(stdscr, TRUE); 
	noecho();

    while (true){
        clear();

        for (i = 0 ; i <= numberOfSchoolYear + 3 ; i++){
            if (i == 0) printw(" * Choose schoolyear and view its semesters :\n");
            else if (i == numberOfSchoolYear + 1) printw("\n * Task : \n");
            else if (i >= 1 && i <= numberOfSchoolYear){
                if (i == choice){
                    start_color();
                    init_pair(1, COLOR_RED, COLOR_BLACK);
                    attron(COLOR_PAIR(1));
                    printw((to_string(i) + ". " + arr[i - 1] + "\n").c_str());
                    attroff(COLOR_PAIR(1));
                }
                else printw((to_string(i) + ". " + arr[i - 1] + "\n").c_str());
            }
            else if (i == numberOfSchoolYear + 2){
                if (choice == numberOfSchoolYear + 1){
                    start_color();
                    init_pair(1, COLOR_RED, COLOR_BLACK);
                    attron(COLOR_PAIR(1));
                    printw((to_string(numberOfSchoolYear + 1) + ". Edit" + "\n").c_str());
                    attroff(COLOR_PAIR(1));
                }
                else printw((to_string(numberOfSchoolYear + 1) + ". Edit" + "\n").c_str());
            }
            else{
                if (choice == numberOfSchoolYear + 2){
                    start_color();
                    init_pair(1, COLOR_RED, COLOR_BLACK);
                    attron(COLOR_PAIR(1));
                    printw((to_string(numberOfSchoolYear + 2) + ". Back" + "\n").c_str());
                    attroff(COLOR_PAIR(1));
                }
                else printw((to_string(numberOfSchoolYear + 2) + ". Back" + "\n").c_str());
            }
        }

        int key = getch();
        switch(key){
            case KEY_DOWN :
                if (choice == numberOfSchoolYear + 2) choice = 1;
                else choice++;
                break;
            case KEY_UP :
                if (choice == 1) choice = numberOfSchoolYear + 2;
                else choice--;
                break;
            case 10 :
                break ;
        }
        if (key == 10) break;
        refresh();
    }
    endwin();

    if (choice == numberOfSchoolYear + 1) {
        delete[] arr;
        editSchoolYears(); // go to edit function
    }
    else if (choice == numberOfSchoolYear + 2) {
        delete[] arr;
        tasksSchoolYears(); // back to tasks function of School Year
    }
    else if (choice <= numberOfSchoolYear && choice >= 1) {
        string year = arr[choice - 1];
        delete[] arr;
        string existSemester = "DataSet/SchoolYear/" + year + "/existSemester.txt";
        tasksSemesters(existSemester, year); // go to tasks function of Semester
    }
}