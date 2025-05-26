#ifndef CONTROL_H
#define CONTROL_H

#include "forward.h"
#include "boundary.h"
#include "entity.h"
using namespace std;

// 회원 가입
class SignIn
{
private:
    SigninUI *signInUI;

public:
    SignIn();
    ~SignIn();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Member *addNewMember(string id, string password, string phoneNumber);
};

// 로그인
class Login
{
private:
    LoginUI *loginUI;

public:
    Login();
    ~Login();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    User *login(string id, string password);
};

// 로그아웃
class Logout
{
private:
    LogoutUI *logoutUI;
public:
    Logout();
    ~Logout();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    User *logout();
};

// 자전거 등록
class RegisterBicycle
{
private:
    RegisterBicycleUI *registerBicycleUI;
public:
    RegisterBicycle();
    ~RegisterBicycle();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Bicycle *registerBicycle(string bicycleId, string bicycleName);
};

// 자전거 대여
class RentBicycle
{
private:
    RentBicycleUI *rentBicycleUI;
public:
    RentBicycle();
    ~RentBicycle();
};

// 대여 정보 확인
class CheckRentedInfo
{
private:
    CheckRentedInfoUI *checkRentedInfoUI;
public:
    CheckRentedInfo();
    ~CheckRentedInfo();
};
#endif