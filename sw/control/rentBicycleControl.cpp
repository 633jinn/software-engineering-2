#include "../control/rentBicycleControl.h"
#include "../boundary/rentBicycleUI.h"
#include "../entity/database.h"
#include "../entity/session.h"
#include "../entity/user.h"
#include "../entity/member.h"
#include "../entity/bicycle.h"
#include "../entity/bicycleCollection.h"

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
