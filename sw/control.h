#pragma once

#include <string>
#include <iostream>
#include <list>

#include "boundary.h"
#include "entity.h"
using namespace std;

// 회원 가입
class SignIn
{
private:
    SigninUI *signInBoundary;
    UserDB *userDB;
    list<Member> memberList;

public:
    SignIn(UserDB *userDB);
    ~SignIn();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Member *addNewMember(string id, string password, string phoneNumber);
};

// 로그인
class Login
{
private:
    /* data */
public:
    Login(/* args */);
    ~Login();
};

// 로그아웃
class Logout
{
private:
    /* data */
public:
    Logout(/* args */);
    ~Logout();
};

// 자전거 등록
class RegisterBicycle
{
private:
    /* data */
public:
    RegisterBicycle(/* args */);
    ~RegisterBicycle();
};

// 자전거 대여
class RentBicycle
{
private:
    /* data */
public:
    RentBicycle(/* args */);
    ~RentBicycle();
};

// 대여 정보 확인
class CheckRentedInfo
{
private:
    /* data */
public:
    CheckRentedInfo(/* args */);
    ~CheckRentedInfo();
};
