#ifndef SIGNUP_UI_H
#define SIGNUP_UI_H

#include <string>
#include <fstream>
#include "../forward.h"
#include "../control/signupControl.h"
using namespace std;

class SignUpUI
{
private:
    SignUp *signUp;
    string id;
    string password;
    string phoneNumber;
    void writeOutput(ofstream &out_fp, Member *member);

public:
    SignUpUI(SignUp *signup);
    ~SignUpUI();
    void signUpAccount(ifstream &in_fp, ofstream &out_fp);
};

#endif