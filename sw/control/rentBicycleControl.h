#ifndef RENT_BICYCLE_CONTROL_H
#define RENT_BICYCLE_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "../forward.h"
#include "../boundary/rentBicycleUI.h"
#include "../entity/database.h"
#include "../entity/session.h"
#include "../entity/user.h"
#include "../entity/member.h"
#include "../entity/bicycle.h"
#include "../entity/bicycleCollection.h"

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