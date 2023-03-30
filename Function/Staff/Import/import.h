#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
struct ScoreboardRow {
    int no;
    string studentID;
    string studentName;
    double totalMark;
    double finalMark;
    double midtermMark;
    double otherMark;
};
void importScoreboard(string fileName, ScoreboardRow scoreboard); // Initial Function about Import (not complete)