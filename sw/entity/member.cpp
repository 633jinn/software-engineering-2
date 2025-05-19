#include "member.h"

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

void Member::checkUserRentAvailability()
{
}

void Member::getBicycle()
{
}

void Member::getRentedBicycle()
{
}

void Member::findUser()
{
}
