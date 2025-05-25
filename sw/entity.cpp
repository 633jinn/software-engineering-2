#include <iostream>
#include <string>
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
    if (id == this->getId())
    {
        return true;
    }
    return false;
}

bool Bicycle::getBicycleDetails()
{
    return false;
}

string Bicycle::getId()
{
    return this->id;
}
