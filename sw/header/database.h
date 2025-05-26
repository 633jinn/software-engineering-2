#ifndef DATABASE_H
#define DATABASE_H

#include <list>
#include "user.h"
#include "manager.h"
#include "bicycle.h"
#include "member.h"
#include "forward.h"
using namespace std;

class Database
{
private:
    Manager *manager;
    list<Member *> memberList;
    list<Bicycle *> bicycleList;

public:
    Database();
    ~Database();
    Member *addMember(string id, string password, string phoneNumber);
    User *findUser(string id, string password);
    Bicycle *addBicycle(string bicycleId, string bicycleName);
    Bicycle *findBicycle(string bicycleId);
};

#endif