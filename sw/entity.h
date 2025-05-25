#pragma once

#include <string>
#include <list>
using namespace std;

class User
{
protected:
    string id;
    string password;

public:
    virtual void findUser() = 0;
};

class Member : public User
{
private:
    string phoneNumber;
    string bicycleId;

public:
    Member(string id, string password, string phoneNumber);
    ~Member();
    void findUser() override;
    void checkUserRentAvailability();
    void getBicycle();
    void getRentedBicycle();
    string getId();
    string getPassword();
    string getPhoneNumber();
};

class Manager : public User
{
private:
    /* data */
public:
    Manager(string id, string password);
    ~Manager();
    void findUser() override;
};

class Bicycle
{
private:
    string id;
    string name;
    string getId();

public:
    Bicycle(string id, string name);
    ~Bicycle();
    bool findBicycle(string id);
    bool getBicycleDetails();
};

class UserDB
{
private:
    Manager* manager;
    list<Member *> memberList;

public:
    UserDB();
    ~UserDB();
    void addMember(Member *member);
};