#include "../control/checkRentedBicycleControl.h"
#include "../entity/member.h"
#include "../entity/bicycle.h"
#include "../entity/bicycleCollection.h"

CheckRentedBicycle::CheckRentedBicycle(Database *database, Session *session)
{
    this->database = database;
    this->session = session;
    checkRentedBicycleUI = new CheckRentedBicycleUI(this);
}

CheckRentedBicycle::~CheckRentedBicycle()
{
    delete checkRentedBicycleUI;
}

void CheckRentedBicycle::startInterface(ofstream &out_fp)
{
    checkRentedBicycleUI->checkRentedInfo(out_fp);
}

list<Bicycle *> CheckRentedBicycle::checkRentedList()
{
    User *user = session->getLoginUser();
    if (user)
    {
        Member *member = dynamic_cast<Member *>(user);
        if (member)
        {
            return member->getBicycleCollection()->getRentedList();
        }
    }
    return list<Bicycle *>();
}
