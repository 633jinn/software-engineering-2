#ifndef MANAGER_H
#define MANAGER_H

#include "user.h"

class Manager : public User
{
public:
    Manager(string id, string password);
    ~Manager();
};

#endif