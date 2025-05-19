#include <string>
#include <iostream>
#pragma once
using namespace std;

class Bicycle
{
private:
    string id;
    string name;
    string getId();

public:
    Bicycle(string id, string name);
    ~Bicycle();
    bool findBicycle(string id);
    bool getBicycleDetails();
};

Bicycle::Bicycle(string id, string name)
{
    this->id = id;
    this->name = name;
}

Bicycle::~Bicycle()
{
}
