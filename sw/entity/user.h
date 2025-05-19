#include <string>
#include <iostream>
#pragma once
using namespace std;


class User
{
protected:
    string id;
    string password;
public:
    virtual void findUser() = 0;
};
