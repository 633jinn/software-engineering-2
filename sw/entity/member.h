#include <stdio.h>
#include <string>
#include <iostream>
#include "user.h"
#pragma once
using namespace std;

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
};
