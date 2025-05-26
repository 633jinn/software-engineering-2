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
    Manager *manager;
    list<Member *> memberList;
    list<Bicycle *> bicycleList;

public:
    Database();
    ~Database();
    Member *addMember(string id, string password, string phoneNumber);
    User *findUser(string id, string password);
    Bicycle *addBicycle(string bicycleId, string bicycleName);
    Bicycle *findBicycle(string bicycleId);
};

class Session
{
private:
    User *loginUser;

public:
    Session();
    ~Session();
    void setLoginUser(User *user);
    User *getLoginUser();
    void logoutUser();
};

#endif