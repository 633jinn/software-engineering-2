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
    //���޹��� id�� pasword�� valid�Ѱ�� �ش��ϴ� ���� return
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
    //���޹��� info�� �������� Bicycle�� �����Ͽ� �����Ѵ�.
    Bicycle *bicycle = new Bicycle(bicycleId, bicycleName);
    bicycleList.push_back(bicycle);
    return bicycle;
}

Bicycle *Database::findBicycle(string bicycleId)
{
    //bicycleList���� id�� �ش��ϴ� ��ü�� ã�� return�Ѵ�.
    for (auto bicycle : bicycleList)
    {
        if (bicycle->getId() == bicycleId)
            return bicycle;
    }
    return nullptr;
}