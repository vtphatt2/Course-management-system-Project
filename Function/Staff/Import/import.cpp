#include "import.h"

void importScoreboard(string fileName, ScoreboardRow scoreboard) {
     ifstream file(fileName);
    string line;
    if (!file.is_open()) {
        cout << "Error: Could not open file " << fileName << endl;
        return false;
    }
    // Ignore first line (column headers)
    getline(file, line);

    while (getline(file, line)) {
        ScoreboardRow row;

        // Split line into columns
        stringstream ss(line);
        string item;

        getline(ss, item, ',');
        row.no = stoi(item);

        getline(ss, item, ',');
        row.studentID = stoi(item);

        getline(ss, row.studentName, ',');

        getline(ss, item, ',');
        row.totalMark = stod(item);

        getline(ss, item, ',');
        row.finalMark = stod(item);

        getline(ss, item, ',');
        row.midtermMark = stod(item);

        getline(ss, item, ',');
        row.otherMark = stod(item);

        scoreboard.push_back(row);
    }
    file.close();
}