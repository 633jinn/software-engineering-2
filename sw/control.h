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
    Database *database;

public:
    SignIn(Database *database);
    ~SignIn();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Member *addNewMember(string id, string password, string phoneNumber);
};

// 로그인
class Login
{
private:
    LoginUI *loginUI;
    Database *database; 
    Session *session;
public:
    Login(Database *database, Session *session);
    ~Login();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    User *login(string id, string password);
};

// 로그아웃
class Logout
{
private:
    LogoutUI *logoutUI;
    Database *database;
    Session *session;
public:
    Logout(Database *database, Session *session);
    ~Logout();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    User *logout();
};

// 자전거 등록
class RegisterBicycle
{
private:
    RegisterBicycleUI *registerBicycleUI;
    Database *database; 
public:
    RegisterBicycle(Database *database);
    ~RegisterBicycle();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Bicycle *registerBicycle(string bicycleId, string bicycleName);
};

// 자전거 대여
class RentBicycle
{
private:
    RentBicycleUI *rentBicycleUI;
    Database *database;
    Session *session;
public:
    RentBicycle(Database *database, Session *session);
    ~RentBicycle();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Bicycle *rentBicycle(string bicycleId);
};

// 대여 정보 확인
class CheckRentedBicycle
{
private:
    CheckRentedBicycleUI *checkRentedBicycleUI;
    Database *database;
    Session *session;   
public:
    CheckRentedBicycle(Database *database, Session *session);
    ~CheckRentedBicycle();
    void startInterface(ofstream &out_fp);
    list<Bicycle *> checkRentedList();
};

class ExitProgram
{
private:
    ExitProgramUI *exitProgramUI;
    Database *database;
public:
    ExitProgram(Database *database);
    ~ExitProgram();
    void startInterface(ofstream &out_fp);
};
#endif