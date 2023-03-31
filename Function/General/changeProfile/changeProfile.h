#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void changeProfile(string id); // This function to check whether the ID exist or not,
                                // if ID exist this function will find out the address of profile.txt
                                // else the function will inform and exit
                                // Then, this function ask user to choose information that need to change
                                // In order to change any information, you just need call function changeProfile
                                
// 3 function "change" below included ENTERING(from user) a new information that need to change
void changeName(string id, string address); //To change name in profile.txt
void changeSex(string id, string address); //To change sex(male/female) in profile.txt
void changeDOB(string id, string address); //To change date of birth in profile.txt

bool checkDay(int y, int m, int d); // To check whether the day exist or not (base on leap year, number of days in month,...)