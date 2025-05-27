#include "bicycleCollection.h"

BicycleCollection::BicycleCollection() {}

BicycleCollection::~BicycleCollection() {}

void BicycleCollection::addRentedBicycle(Bicycle *bicycle)
{
    //전달받은 Bicycle을 리스트에 저장
    rentedBicycle.push_front(bicycle);
}

list<Bicycle *> BicycleCollection::getRentedList()
{
    return rentedBicycle;
}