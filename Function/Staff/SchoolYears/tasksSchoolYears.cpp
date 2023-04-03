#include "../staff.h"

// void tasksSchoolYears() {
//     string existSemester, year;
//     ifstream in;
//     in.open(taskOfSchoolYears);
//     string s;
//     cout << '\n';
//     while (getline(in , s)) {
//         cout << s << '\n';
//     }
//     in.close();
//     cout << "Your choose is : ";
//     int ans;
//     cin >> ans;
//     if (ans == 1) viewSchoolYears();
//     else if (ans == 2) editSchoolYears();
//     else if (ans == 3) chooseSchoolYears(existSemester, year);
//     // else if (ans == 4) quay lai giao dien chinh
// }

void tasksSchoolYears(){
    createTitle("SCHOOLYEARS");
    cout << "\n1. Schoolyears and Edit";
    cout << "\n2. Back";
    cout << "\nYour choice is : ";
    int choose;
    cin >> choose;

    if (choose == 1){
        //open file named "existSchoolYear.txt"
        ifstream in;
        in.open(existSchoolYearPath);

        //get number of SchoolYear in this file
        int numberOfSchoolYear = 0;
        string s;
        while (getline(in, s)) numberOfSchoolYear++;
        in.close();

        cout << "\n";

        string* arr = new string[numberOfSchoolYear];
        in.open(existSchoolYearPath);
        int i = 0;
        while (getline(in, s)){
            arr[i] = s;
            i++;
        }
        in.close();

        //print out to terminal
        cout << " * Choose schoolyears and view its semester :\n";
        for (i = 0 ; i < numberOfSchoolYear ; i++) cout << i + 1 << ". " << arr[i] << "\n";

        cout << "\n * Tasks :";
        cout << "\n" << ++i << ". Edit";
        cout << "\n" << ++i << ". Back";
        cout << "\nYour choice is : ";
        
        int choose;
        cin >> choose;
        if (choose == numberOfSchoolYear + 2){
            tasksSchoolYears();
        }
        else if (choose == numberOfSchoolYear + 1) editSchoolYears(); 
        else if (choose <= numberOfSchoolYear && choose >= 1){
            string year = arr[choose - 1];
            delete[] arr;
            string existSemester = "DataSet/SchoolYear/" + year + "/existSemester.txt";
            tasksSemesters(existSemester, year);
        }
    }
}