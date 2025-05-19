#include <stdio.h>
#include <string>
#include <iostream>
#include <user.h>
#pragma once
using namespace std;

class Manager : public User
{
private:
    /* data */
public:
    Manager(/* args */);
    ~Manager();
    void findUser() override;
};

Manager::Manager(/* args */)
{
}

Manager::~Manager()
{
}
