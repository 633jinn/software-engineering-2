#ifndef REGISTER_BICYCLE_CONTROL_H
#define REGISTER_BICYCLE_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "registerBicycleUI.h"
#include "database.h"
#include "bicycle.h"

// 자전거 등록
class RegisterBicycle
{
private:
    RegisterBicycleUI *registerBicycleUI;
    Database *database;

public:
    RegisterBicycle(Database *database);
    ~RegisterBicycle();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Bicycle *registerBicycle(string bicycleId, string bicycleName);
};

#endif