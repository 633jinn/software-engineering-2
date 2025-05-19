#include "bicycle.h"
#include <string>

using namespace std;

bool Bicycle::findBicycle(string id)
{
    if (id == this->getId())
    {
        return true;
    }
    return false;
}

bool Bicycle::getBicycleDetails()
{
    return false;
}

string Bicycle::getId()
{
    return this->id;
}
