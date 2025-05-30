#include "registerBicycleControl.h"
#include "registerBicycleUI.h"
#include "database.h"
#include "bicycle.h"

RegisterBicycle::RegisterBicycle(Database *database)
{
    this->database = database;
    registerBicycleUI = new RegisterBicycleUI(this);
}

RegisterBicycle::~RegisterBicycle()
{
    delete registerBicycleUI;
}

void RegisterBicycle::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    registerBicycleUI->registerBicycleInfo(in_fp, out_fp);
}

Bicycle *RegisterBicycle::registerBicycle(string bicycleId, string bicycleName)
{
    Bicycle *bicycle = database->addBicycle(bicycleId, bicycleName);
    return bicycle;
}
