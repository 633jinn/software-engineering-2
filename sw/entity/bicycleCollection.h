#ifndef BICYCLE_COLLECTION_H
#define BICYCLE_COLLECTION_H

#include <list>
#include "bicycle.h" 

using namespace std;

class BicycleCollection
{
private:
    list<Bicycle *> rentedBicycle;

public:
    BicycleCollection();
    ~BicycleCollection();
    void addRentedBicycle(Bicycle *bicycle);
    list<Bicycle *> getRentedList();
};

#endif