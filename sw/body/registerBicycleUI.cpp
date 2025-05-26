#include <iostream>
#include "../header/registerBicycleUI.h"
#include "../header/registerBicycleControl.h"
#include "../header/bicycle.h"
using namespace std;

void RegisterBicycleUI::readInput(ifstream &in_fp)
{
    in_fp >> bicycleId >> bicycleName;
}

RegisterBicycleUI::RegisterBicycleUI(RegisterBicycle *registerBicycle)
{
    this->registerBicycle = registerBicycle;
}

RegisterBicycleUI::~RegisterBicycleUI() {}

void RegisterBicycleUI::registerBicycleInfo(ifstream &in_fp, ofstream &out_fp)
{
    readInput(in_fp);
    Bicycle *bicycle = registerBicycle->registerBicycle(bicycleId, bicycleName);
    writeOutput(out_fp, bicycle);
}

void RegisterBicycleUI::writeOutput(ofstream &out_fp, Bicycle *bicycle)
{
    out_fp << "3.1. 자전거 등록" << endl;
    out_fp << "> " << bicycle->getId() << " " << bicycle->getName() << endl
           << endl;
}