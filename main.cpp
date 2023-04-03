#include <iostream>
#include <cstring>
#include "Function/function.h"

using namespace std;

int main(){
    bool logingIn = false;
    string idUser;
    login(idUser, logingIn);
    while (logingIn){
        createTitle("MENU");
        task(idUser, logingIn);
    }
    return 0;
}

// g++ main.cpp Function/**/*.cpp -lncurses -o main.exe && ./main.exe