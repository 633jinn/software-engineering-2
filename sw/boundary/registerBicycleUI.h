#ifndef REGISTER_BICYCLE_UI_H
#define REGISTER_BICYCLE_UI_H

#include "../forward.h"
#include <string>
#include <fstream>

using namespace std;

class RegisterBicycleUI
{
private:
    RegisterBicycle *registerBicycle;
    string bicycleId;
    string bicycleName;
    void readInput(ifstream &in_fp);
    void writeOutput(ofstream &out_fp, Bicycle *bicycle);

public:
    RegisterBicycleUI(RegisterBicycle *registerBicycle);
    ~RegisterBicycleUI();
    void registerBicycleInfo(ifstream &in_fp, ofstream &out_fp);
};

#endif