#include "staff.h"

void staff_edit() {
    cout << "1. Create a new school year" << '\n';
    cout << "2. Delete a school year" << '\n';
    cout << "Your choose is: ";
    int n;
    cin >> n;
    if (n == 1) staff_create_a_new_school_year();
    else if (n == 2) staff_delete_a_school_year();
}

void staff_create_a_new_school_year() {
    ofstream out;
    out.open(schoolYears, ios_base::app);
    while (true) {
        cout << "Input a new school year: ";
        string s;
        cin >> s;
        out << '\n';
        out << s;
        cout << "Type 'q' to quit or 'n' to continue input a new school year: ";
        string s;
        cin >> s;
        if (s == 'q') break;
    }
}

void staff_delete_a_school_year() {
    // meow meow
}