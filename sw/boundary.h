#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <string>
#include <iostream>
#include "entity.h"
#include "control.h"
using namespace std;

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
    Login *login;
    string id;
    string password;
    void writeOutput(ofstream &out_fp, User *user);
public:
    LoginUI(Login *login);
    ~LoginUI();
    void loginAccount(ifstream &in_fp, ofstream &out_fp);
};

class LogoutUI
{
private:
    Logout *logout;
    void writeOutput(ofstream &out_fp, User *user);
public:
    LogoutUI(Logout *logout);
    ~LogoutUI();
    void logoutAccount(ifstream &in_fp, ofstream &out_fp);
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
#endif