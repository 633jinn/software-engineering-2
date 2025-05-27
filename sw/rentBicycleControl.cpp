#include "rentBicycleControl.h"
#include "rentBicycleUI.h"
#include "database.h"
#include "session.h"
#include "user.h"
#include "member.h"
#include "bicycle.h"
#include "bicycleCollection.h"

RentBicycle::RentBicycle(Database *database, Session *session)
{
    this->database = database;
    this->session = session;
    rentBicycleUI = new RentBicycleUI(this);
}

RentBicycle::~RentBicycle()
{
    delete rentBicycleUI;
}

void RentBicycle::startInterface(ifstream &in_fp, ofstream &out_fp)
{
    rentBicycleUI->rentBicycleInfo(in_fp, out_fp);
}

Bicycle *RentBicycle::rentBicycle(string bicycleId)
{
    Bicycle *bicycle = database->findBicycle(bicycleId);
    if (bicycle)
    {
        User *user = session->getLoginUser();
        if (user)
        {
            Member *member = dynamic_cast<Member *>(user);
            if (member)
            {
                member->getBicycleCollection()->addRentedBicycle(bicycle);
                return bicycle;
            }
        }
    }
    return nullptr;
}
