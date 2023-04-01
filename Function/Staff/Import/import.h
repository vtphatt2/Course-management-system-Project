#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
void import(); // To read file CVS include scored of student (file CSV exported)
                // Then find each folder (dataset/schoolyear/semester/x_year/courses/class/scoreBoard.txt)
                // Create file scoreBoard.txt(with the address above) includes information about marks of student

string findClass(string s); //To find student's class base on the line in CSV file
                            // Ex: findClass(1,TranThanhTien,22125105,22CTT2,....) => return 22CTT2