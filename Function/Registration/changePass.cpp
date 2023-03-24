#include <iostream>
#include <fstream>
using namespace std;

const string accountFile = "DataSet/accountUser.txt";

void changePass(std::string idUser){
    string oldPass, newPass, reCheckNewPass;
    cout << "\nYour current password : ";
    cin.ignore(100, '\n');
    getline(cin, oldPass);
    cout << "New password : ";
    getline(cin, newPass);
    cout << "Confirm new password : ";
    getline(cin, reCheckNewPass);

    if (newPass != reCheckNewPass){
        cout << "Your confirming password is not correct !";
        return ;
    }

    ifstream in;
    in.open(accountFile);
    string findID;
    int line = 0;
    while (getline(in, findID)){
        line++;
        if (findID == idUser){
            in.close();
            in.open(accountFile);
            ofstream out;
            out.open("DataSet/test.txt", ios::app);
            string s;
            for (int i = 1 ; i <= line - 3 ; i++){
                getline(in, s);
                out << s << "\n";
            }
            out << newPass;
            in >> s;
            while (getline(in, s)) out << s << "\n";
            in.close();
            out.close();
            remove("DataSet/accountUser.txt");
            rename("DataSet/test.txt", "DataSet/accountUser.txt");
            break;
        }
    }

    
}