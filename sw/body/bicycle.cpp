#include "../header/bicycle.h"

Bicycle::Bicycle(string id, string name)
{
    this->id = id;
    this->name = name;
}

Bicycle::~Bicycle() {}

string Bicycle::getId()
{
    return id;
}

string Bicycle::getName()
{
    return name;
}