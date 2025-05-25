#pragma once

#include <string>
#include <iostream>
using namespace std;

// 전방 선언
class SignIn;

class SigninUI 
{
private:
    SignIn *signIn;

public:
    SigninUI(SignIn *signIn);
    ~SigninUI();
    void signInAccount(string id, string password, string phoneNumber);
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