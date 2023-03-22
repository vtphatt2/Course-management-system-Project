#include <iostream>
#include <cstring>
#include "Function/function.h"

using namespace std;

int main(){
    bool logingIn = false;
    string idUser;
    login(idUser, logingIn);
    while (logingIn){
        task(logingIn);
    }
    return 0;
}