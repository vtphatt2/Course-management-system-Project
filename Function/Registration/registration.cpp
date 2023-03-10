#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const string accountFile = "DataSet/accountUser.txt";

void login(string idUser){
    cout << "WELCOME TO MOODLE...! PLEASE LOGIN !" << endl << endl;

    string user, pass;

    labelLogin :
        cout << "Username : "; //user types here
        cin >> user;
        cout << "Password : ";
        cin >> pass;

        ifstream in; 
        in.open(accountFile); //read data from accountFile
        string checkUser;
        bool findUser = false;
        while (!findUser && in >> checkUser){ //check if username exists or not
            if (checkUser == user) findUser = true;
        }
        
        if (!findUser){
            cout << "Your username does not exist" << endl ;
            char choose;
            cout << "Try again (type any key and enter) or quit (type 'q' and enter) : ";
            cin >> choose;
            if (choose == 'q'){
                return ;
            }
            else{
                in.close();
                goto labelLogin;
            }
        }
        else{
            string checkPass; //check if password is right or wrong
            in >> checkPass;
            in.close();
            while (checkPass != pass){
                cout << "Your password is not correct. Try again : ";
                cin >> pass;
            }
            cout << "\nLOGIN SUCCESSFULLY !" << endl;
        }  
}

