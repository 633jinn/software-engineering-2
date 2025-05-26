#include "entity.h"
using namespace std;

// 회원
Member::Member(string id, string password, string phoneNumber)
{
    this->id = id;
    this->password = password;
    this->phoneNumber = phoneNumber;
    this->bicycleCollection = new BicycleCollection();
}

Member::~Member()
{
    delete bicycleCollection;
}

string Member::getPhoneNumber()
{
    return phoneNumber;
}

BicycleCollection *Member::getBicycleCollection()
{
    return bicycleCollection;
}

// 관리자
Manager::Manager(string id, string password)
{
    this->id = id;
    this->password = password;
}

Manager::~Manager()
{
}

Database::Database()
{
    manager = new Manager("admin", "admin");
}

Database::~Database()
{
    delete manager;
}

// 데이터베이스
Member *Database::addMember(string id, string password, string phoneNumber)
{
    Member *member = new Member(id, password, phoneNumber);
    memberList.push_back(member);
    return member;
}

Bicycle *Database::addBicycle(string bicycleId, string bicycleName)
{
    Bicycle *bicycle = new Bicycle(bicycleId, bicycleName);
    bicycleList.push_back(bicycle);
    return bicycle;
}

Bicycle *Database::findBicycle(string bicycleId)
{
    for (auto bicycle : bicycleList)
    {
        if (bicycle && bicycle->getId() == bicycleId)
            return bicycle;
    }
    return nullptr;
}

User *Database::findUser(string id, string password)
{
    if (manager && manager->isValid(id, password))
        return manager;
    for (auto member : memberList)
    {
        if (member && member->isValid(id, password))
            return member;
    }
    return nullptr;
}

// 자전거
Bicycle::Bicycle(string id, string name)
{
    this->id = id;
    this->name = name;
}

Bicycle::~Bicycle()
{
}

string Bicycle::getId()
{
    return id;
}

string Bicycle::getName()
{
    return name;
}

Session::Session()
{
    loginUser = nullptr;
}

Session::~Session()
{
}

void Session::setLoginUser(User *user)
{
    loginUser = user;
}

User *Session::getLoginUser()
{
    return loginUser;
}

void Session::logoutUser()
{
    loginUser = nullptr;
}

BicycleCollection::BicycleCollection()
{
}

BicycleCollection::~BicycleCollection()
{
}

void BicycleCollection::addRentedBicycle(Bicycle *bicycle)
{
    rentedBicycle.push_front(bicycle);
}

list<Bicycle *> BicycleCollection::getRentedList()
{
    list<Bicycle *> rentedBicycleList;
    for (auto bicycle : rentedBicycle)
    {
        rentedBicycleList.push_back(bicycle);
    }
    return rentedBicycleList;
}
