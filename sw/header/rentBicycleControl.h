#ifndef RENT_BICYCLE_CONTROL_H
#define RENT_BICYCLE_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "rentBicycleUI.h"
#include "database.h"
#include "session.h"
#include "user.h"
#include "member.h"
#include "bicycle.h"
#include "bicycleCollection.h"

using namespace std;

// 자전거 대여
class RentBicycle
{
private:
    RentBicycleUI *rentBicycleUI;
    Database *database;
    Session *session;

public:
    RentBicycle(Database *database, Session *session);
    ~RentBicycle();
    void startInterface(ifstream &in_fp, ofstream &out_fp);
    Bicycle *rentBicycle(string bicycleId);
};

#endif