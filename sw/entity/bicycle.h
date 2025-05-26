#ifndef BICYCLE_H
#define BICYCLE_H

#include <string>
using namespace std;

class Bicycle
{
private:
    string id;
    string name;

public:
    Bicycle(string id, string name);
    ~Bicycle();
    string getId();
    string getName();
};

#endif