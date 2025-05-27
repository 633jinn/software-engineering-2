#include "database.h"
#include "member.h"

Database::Database()
{
    manager = new Manager("admin", "admin");
}

Database::~Database()
{
    delete manager;
    for (auto member : memberList)
    {
        delete member;
    }
    for (auto bicycle : bicycleList)
    {
        delete bicycle;
    }
}

Member *Database::addMember(string id, string password, string phoneNumber)
{
    Member *member = new Member(id, password, phoneNumber);
    memberList.push_back(member);
    return member;
}

User *Database::findUser(string id, string password)
{
    //전달받은 id와 pasword가 valid한경우 해당하는 유저 return
    if (manager->isValid(id, password))
        return manager;
    for (auto member : memberList)
    {
        if (member->isValid(id, password))
            return member;
    }
    return nullptr;
}

Bicycle *Database::addBicycle(string bicycleId, string bicycleName)
{
    //전달받은 info를 바탕으로 Bicycle을 생성하여 저장한다.
    Bicycle *bicycle = new Bicycle(bicycleId, bicycleName);
    bicycleList.push_back(bicycle);
    return bicycle;
}

Bicycle *Database::findBicycle(string bicycleId)
{
    //bicycleList에서 id에 해당하는 객체를 찾아 return한다.
    for (auto bicycle : bicycleList)
    {
        if (bicycle->getId() == bicycleId)
            return bicycle;
    }
    return nullptr;
}