#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include "forward.h"
#include <string>
#include <fstream>
using namespace std;

class LoginUI
{
private:
    Login *login;
    string id;
    string password;
    void readInput(ifstream &in_fp);
    void writeOutput(ofstream &out_fp, User *user);

public:
    LoginUI(Login *login);
    ~LoginUI();
    void loginAccount(ifstream &in_fp, ofstream &out_fp);
};

#endif