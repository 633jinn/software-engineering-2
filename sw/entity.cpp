#include "entity.h"
using namespace std;

// 회원
Member::Member(string id, string password, string phoneNumber)
{
    this->id = id;
    this->password = password;
    this->phoneNumber = phoneNumber;
    cout << "회원 생성" << endl;
}

Member::~Member()
{
}

void Member::findUser()
{
}

void Member::checkUserRentAvailability()
{
}

void Member::getBicycle()
{
}

void Member::getRentedBicycle()
{
}

string Member::getId()
{
    return id;
}

string Member::getPassword()
{
    return password;
}

string Member::getPhoneNumber()
{
    return phoneNumber;
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

void Manager::findUser()
{
}

// 데이터베이스
UserDB::UserDB()
{
    manager = new Manager("admin", "admin");
}
UserDB::~UserDB()
{
    delete manager;
    for (auto member : memberList)
    {
        delete member;
    }
}

void UserDB::addMember(Member *member)
{
    memberList.push_back(member);
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
bool Bicycle::findBicycle(string id)
{
    return this->id == id;
}

bool Bicycle::getBicycleDetails()
{
    return true;
}

string Bicycle::getId()
{
    return id;
}