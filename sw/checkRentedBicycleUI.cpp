#include "checkRentedBicycleUI.h"
#include "checkRentedBicycleControl.h"
#include "bicycle.h"
#include <iostream>
using namespace std;

CheckRentedBicycleUI::CheckRentedBicycleUI(CheckRentedBicycle *checkRentedBicycle)
{
    this->checkRentedBicycle = checkRentedBicycle;
}

CheckRentedBicycleUI::~CheckRentedBicycleUI() {}

void CheckRentedBicycleUI::checkRentedInfo(ofstream &out_fp)
{
    list<Bicycle *> rentedBicycle = checkRentedBicycle->checkRentedList();
    writeOutput(out_fp, rentedBicycle);
}

void CheckRentedBicycleUI::writeOutput(ofstream &out_fp, list<Bicycle *> rentedBicycle)
{
    out_fp << "5.1. 자전거 대여 리스트" << endl;
    for (auto bicycle : rentedBicycle)
    {
        out_fp << "> " << bicycle->getId() << " " << bicycle->getName() << endl;
    }
    out_fp << endl;
}