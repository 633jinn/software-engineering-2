#pragma once

#include <string>
#include <iostream>
#include "entity.h"
#include "control.h"
using namespace std;

// 전방 선언
class SignIn;

class SigninUI
{
private:
    SignIn *signIn;
    string id;
    string password;
    string phoneNumber;
    void writeOutput(ofstream &out_fp, Member *member);

public:
    SigninUI(SignIn *signIn);
    ~SigninUI();
    void signInAccount(ifstream &in_fp, ofstream &out_fp);
};

class LoginUI
{
private:
    /* data */
public:
    LoginUI(/* args */);
    ~LoginUI();
};

class LogoutUI
{
private:
    /* data */
public:
    LogoutUI(/* args */);
    ~LogoutUI();
};

class RegisterBicycleUI
{
private:
    /* data */
public:
    RegisterBicycleUI(/* args */);
    ~RegisterBicycleUI();
};

class CheckRentedInfoUI
{
private:
    /* data */
public:
    CheckRentedInfoUI(/* args */);
    ~CheckRentedInfoUI();
};