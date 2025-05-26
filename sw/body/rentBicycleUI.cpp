#include "../header/rentBicycleUI.h"
#include "../header/rentBicycleControl.h"
#include "../header/bicycle.h"
#include <iostream>
using namespace std;

void RentBicycleUI::readInput(ifstream &in_fp)
{
    in_fp >> bicycleId;
}

RentBicycleUI::RentBicycleUI(RentBicycle *rentBicycle)
{
    this->rentBicycle = rentBicycle;
}

RentBicycleUI::~RentBicycleUI() {}

void RentBicycleUI::rentBicycleInfo(ifstream &in_fp, ofstream &out_fp)
{
    readInput(in_fp);
    Bicycle *bicycle = rentBicycle->rentBicycle(bicycleId);
    if (bicycle)
    {
        writeOutput(out_fp, bicycle);
    }
}

void RentBicycleUI::writeOutput(ofstream &out_fp, Bicycle *bicycle)
{
    out_fp << "4.1. 자전거 대여" << endl;
    out_fp << "> " << bicycle->getId() << " " << bicycle->getName() << endl
           << endl;
}