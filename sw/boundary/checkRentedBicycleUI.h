#ifndef CHECK_RENTED_BICYCLE_UI_H
#define CHECK_RENTED_BICYCLE_UI_H

#include <string>
#include <fstream>
#include <list>

#include "../forward.h"
using namespace std;

class CheckRentedBicycleUI
{
private:
    CheckRentedBicycle *checkRentedBicycle;
    void writeOutput(ofstream &out_fp, list<Bicycle *> rentedBicycle);

public:
    CheckRentedBicycleUI(CheckRentedBicycle *checkRentedBicycle);
    ~CheckRentedBicycleUI();
    void checkRentedInfo(ofstream &out_fp);
};

#endif