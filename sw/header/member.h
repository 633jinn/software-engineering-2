#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "forward.h"
#include "user.h"
#include "bicycleCollection.h"

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

#endif