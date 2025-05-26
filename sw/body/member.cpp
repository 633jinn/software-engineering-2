#include "../header/member.h"

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