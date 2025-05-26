#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>
#include <iostream>
using namespace std;

class User
{
protected:
    string id;
    string password;

public:
    virtual void findUser() = 0;
    string getId() { return id; }
    string getPassword() { return password; }
    bool isValid(string id, string password)
    {
        if (id == this->id && password == this->password)
            return true;
        return false;
    }
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

class Database
{
private:
    static Manager *manager;
    static list<Member *> memberList;
    static list<Bicycle *> bicycleList;

public:
    static void addMember(Member *member);
    static void addBicycle(Bicycle *bicycle);
    static User *findUser(string id, string password);

    // 정적 멤버 변수 초기화를 위한 friend 함수
    friend void initializeDatabase();
};

// Database 초기화 함수 선언
void initializeDatabase();

class Session
{
private:
    static User *loginUser;

public:
    static void setLoginUser(User *user);
    static User *getLoginUser();
    static void logoutUser();
};

#endif