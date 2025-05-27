#include "checkRentedBicycleControl.h"
#include "member.h"
#include "bicycle.h"  
#include "bicycleCollection.h"

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
        
        if (member) //로그인한 유저가 회원인 경우 대여 리스트 조회
        {
            return member->getBicycleCollection()->getRentedList();
        }
    }
    return list<Bicycle *>();
}
