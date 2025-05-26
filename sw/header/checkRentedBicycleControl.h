#ifndef CHECK_RENTED_BICYCLE_CONTROL_H
#define CHECK_RENTED_BICYCLE_CONTROL_H

#include "../header/forward.h"
#include "../header/session.h"
#include "../header/checkRentedBicycleUI.h"
#include "../header/database.h"
#include <list>

using namespace std;

class CheckRentedBicycle
{
private:
    CheckRentedBicycleUI *checkRentedBicycleUI;
    Database *database;
    Session *session;

public:
    CheckRentedBicycle(Database *database, Session *session);
    ~CheckRentedBicycle();
    void startInterface(ofstream &out_fp);
    list<Bicycle *> checkRentedList();
};

#endif