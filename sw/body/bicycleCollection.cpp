#include "../header/bicycleCollection.h"

BicycleCollection::BicycleCollection() {}

BicycleCollection::~BicycleCollection() {}

void BicycleCollection::addRentedBicycle(Bicycle *bicycle)
{
    //전달받은 Bicycle을 리스트에 저장
    rentedBicycle.push_front(bicycle);
}

list<Bicycle *> BicycleCollection::getRentedList()
{
    //rentedBicycleList에 저장된 Bicycle을 return한다.
    list<Bicycle *> rentedBicycleList;
    for (auto bicycle : rentedBicycle)
    {
        rentedBicycleList.push_back(bicycle);
    }
    return rentedBicycleList;
}