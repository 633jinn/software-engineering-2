#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>

using namespace std;
class BicycleCollection;
class User
{
protected:
    string id;
    string password;

public:
    virtual ~User() {} // 가상 소멸자 추가
    string getId() { return id; }
    string getPassword() { return password; }
    bool isValid(string id, string password)
    {
        if (id == this->id && password == this->password)
            return true;
        return false;
    }
};

class Manager : public User
{
private:
    /* data */
public:
    Manager(string id, string password);
    ~Manager();
};

class Member : public User
{
private:
    string phoneNumber;
    BicycleCollection *bicycleCollection;

public:
    Member(string id, string password, string phoneNumber);
    ~Member();
    string getPhoneNumber();
    BicycleCollection *getBicycleCollection();
};

class Bicycle
{
private:
    string id;
    string name;

public:
    Bicycle(string id, string name);
    ~Bicycle();
    string getId();
    string getName();
};

class BicycleCollection
{
private:
    list<Bicycle *> rentedBicycle;

public:
    BicycleCollection();
    ~BicycleCollection();
    void addRentedBicycle(Bicycle *bicycle);
    list<Bicycle *> getRentedList();
};

class Database
{
private:
    static Manager *manager;
    static list<Member *> memberList;
    static list<Bicycle *> bicycleList;

public:
    static Member *addMember(string id, string password, string phoneNumber);
    static User *findUser(string id, string password);
    static Bicycle *addBicycle(string bicycleId, string bicycleName);
    static Bicycle *findBicycle(string bicycleId);

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