#ifndef RENT_BICYCLE_UI_H
#define RENT_BICYCLE_UI_H

#include <string>
#include <fstream>
#include "forward.h"

using namespace std;

class RentBicycleUI
{
private:
    RentBicycle *rentBicycle;
    string bicycleId;
    void readInput(ifstream &in_fp);
    void writeOutput(ofstream &out_fp, Bicycle *bicycle);

public:
    RentBicycleUI(RentBicycle *rentBicycle);
    ~RentBicycleUI();
    void rentBicycleInfo(ifstream &in_fp, ofstream &out_fp);
};

#endif