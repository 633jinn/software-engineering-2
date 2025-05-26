#include "bicycleCollection.h"

BicycleCollection::BicycleCollection() {}

BicycleCollection::~BicycleCollection() {}

void BicycleCollection::addRentedBicycle(Bicycle *bicycle)
{
    rentedBicycle.push_front(bicycle);
}

list<Bicycle *> BicycleCollection::getRentedList()
{
    list<Bicycle *> rentedBicycleList;
    for (auto bicycle : rentedBicycle)
    {
        rentedBicycleList.push_back(bicycle);
    }
    return rentedBicycleList;
}