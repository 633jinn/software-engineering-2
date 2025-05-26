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
    RegisterBicycle *registerBicycle;
    string bicycleId;
    string bicycleName;
    void writeOutput(ofstream &out_fp, Bicycle *bicycle);

public:
    RegisterBicycleUI(RegisterBicycle *registerBicycle);
    ~RegisterBicycleUI();
    void registerBicycleInfo(ifstream &in_fp, ofstream &out_fp);
};

class RentBicycleUI
{
private:
    RentBicycle *rentBicycle;
    string bicycleId;
    void writeOutput(ofstream &out_fp, Bicycle *bicycle);
public:
    RentBicycleUI(RentBicycle *rentBicycle);
    ~RentBicycleUI();
    void rentBicycleInfo(ifstream &in_fp, ofstream &out_fp);
};

class CheckRentedInfoUI
{
private:
    CheckRentedInfo *checkRentedInfo;

public:
    CheckRentedInfoUI(CheckRentedInfo *checkRentedInfo);
    ~CheckRentedInfoUI();
};
#endif