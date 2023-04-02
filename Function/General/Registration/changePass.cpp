#include <iostream>
#include <fstream>
using namespace std;

const string accountFile = "DataSet/accountUser.txt";

void changePass(string idUser){
    string oldPass, newPass, reCheckNewPass;
    cout << "\nYour current password : ";
    getline(cin, oldPass);
    cout << "New password : ";
    getline(cin, newPass);
    cout << "Confirm new password : ";
    getline(cin, reCheckNewPass);

    if (newPass != reCheckNewPass){
        cout << "Your confirming password is not correct ! Try again !";
        changePass(idUser);
        return ;
    }

    ifstream in;
    in.open(accountFile);
    string findID;
    int line = 0;
    while (getline(in, findID)){
        line++;
        if (findID == idUser){
            int k = 5;
            while (k >= 1){
                if (in.get() == 10) k--;
                if (k >= 1) in.seekg(-2, ios_base :: cur);
            }
            string curPass;
            // cin.ignore(100, '\n');
            getline(in, curPass);
            if (curPass != oldPass){
                cout << "Your current password is not corret. Try again !";
                changePass(idUser);
                return ;
            }

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
            cout << "\nCHANGE PASSWORD SUCCESSFULLY !";

            //just type enter to go to the next screen
            char a;
            a = cin.get();
            break;
        }
    }
}